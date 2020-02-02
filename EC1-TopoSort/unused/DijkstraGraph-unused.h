/**
 *  Core graph data structure
 *   -- Overhauled to have better storage structures
 * 
 *  Contributors:
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   Aaron S. Crandall, 2019 <acrandal@gmail.com>
 */

#ifndef __DIJKSTRA_GRAPH_H
#define __DIJKSTRA_GRAPH_H

#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <list>
#include <unordered_map>

#include "DijkstraVertex.h"

using namespace std;

class DijkstraGraph
{
	unordered_map<int, DijkstraVertex*> vertices;
	int current_dijkstras_starting_vertex_id = std::numeric_limits<int>::infinity();

public:
	// Remove all vertices
	void clear() {
		vertices.clear();
	}

	// Number of vertices in our graph
	std::size_t size() {
		return vertices.size();
	}

	int edges_size() {
		int count = 0;
		for( auto vert : this->vertices ) {
			count += (vert.second)->edges_size();
		}
		return(count);
	}

	/**
	 *  Parses a single in from a dot file
	 */
	void parseDotfileLine( string line ) {
		smatch matched;
		regex newSubGraph ("\\s*(\\S+)\\s*->\\s*(\\S+)\\s*\\[.*?weight=\"*(\\S+?)\"*\\s*\\]\\;");
		regex loneVertex ("\\s*(\\S+);");

		if( regex_match( line, matched, loneVertex ) ) {
			string strconv = matched[1];
			int srcid = (int)::atof(strconv.c_str());
			DijkstraVertex* newSrcVert;
			auto found = vertices.find(srcid);
			if( found == vertices.end() ) {	// No vertex by that ID yet - create it
				newSrcVert = new DijkstraVertex(srcid);
				vertices[srcid] = newSrcVert;
			}
		}

		if( regex_match( line, matched, newSubGraph ) ) {
			string strconv = matched[1];
			int srcid = (int)::atof(strconv.c_str());
			strconv = matched[2];
			int destid = (int)::atof(strconv.c_str());
			strconv = matched[3];
			double weight = ::atof(strconv.c_str());
			//cout << "SrcID: " << srcid << " | DestID: " << destid << " | Edge Weight: " << weight << endl;

			DijkstraVertex* newSrcVert;
			DijkstraVertex* newDestVert;
			auto found = vertices.find(srcid);
			if( found == vertices.end() ) {	// No vertex by that ID yet - create it
				newSrcVert = new DijkstraVertex(srcid);
				vertices[srcid] = newSrcVert;
			} else {
				newSrcVert = (*found).second;
			}

			found = vertices.find(destid);
			if( found == vertices.end() ) {	// No vertex by that ID yet - create it
				newDestVert = new DijkstraVertex(destid);
				vertices[destid] = newDestVert;
			} else {
				newDestVert = (*found).second;
			}

			newSrcVert->addEdge(newDestVert, weight);
		}
	}

	/**
	 *  Loads a limited feature set GraphViz-formatted dot file with a graph
	 *   For more information about GraphViz (which is a very cool tool):
	 *		https://www.graphviz.org/
	 */
	void loadDotFile( string filename ) {
		cout << " Loading dot file: " << filename << std::flush;
		ifstream ifs( filename );
		string instr;
		while (getline(ifs, instr)) {
			parseDotfileLine( instr );
		}
		cout << " - Done." << endl;
	}

	/**
	 *  Returns stringified version of graph for viewing
	 */
	string to_string( bool with_edges = false ) {
		string ret = "Graph: \n";
		for( auto vert : this->vertices ) {
			ret += (vert.second)->to_string( with_edges ) + "\n";
		}
		return ret;
	}

	//** Start of Dijkstra's Algorithm tools and interfaces
	void reset_dijkstras() {
		for( auto vert_pair : vertices ) {
			auto vert = vert_pair.second;
			vert->reset_dijkstras_bookkeeping();
		}
	}

	//** Returns vector of all of the graph's vertex ids
	vector<int> get_all_vertex_ids() {
		vector<int> all_Ids;
		for( auto vert_pair : vertices ) {
			all_Ids.push_back( vert_pair.first );
		}
		return all_Ids;
	}

	//** Returns the node and weight of "furthest away" node from starting_nodeId
	std::pair<int, double> get_highest_path_weight(int starting_nodeId) {
		auto weights = get_all_path_weights(starting_nodeId);
		std::pair<int,double> max_weight = {0, 0};
		for( auto node_pair : weights ) {
			if( node_pair.second > max_weight.second ) {
				max_weight = node_pair;
			}
		}
		return max_weight;
	}

	//** Returns longest path of all connected nodes for a given starting_nodeId
	std::list<DijkstraVertex*> get_longest_path(int starting_nodeId) {
		std::list<DijkstraVertex*> longest_path;
		auto all_Ids = get_all_vertex_ids();

		for( int curr_Id : all_Ids ) {
			auto curr_path = get_path(starting_nodeId, curr_Id);
			if( curr_path.size() > longest_path.size() ) {
				longest_path = std::move(curr_path);
			}
		}
		return longest_path;
	}

	//** Get the path weight from a starting node to a specified ending node
	double get_path_weight(int starting_nodeId, int ending_nodeId) {
		run_dijkstras(starting_nodeId);		// Ensure the calculations are ready
		return vertices[ending_nodeId]->get_path_weight();
	}

	unordered_map<int, double> get_all_path_weights( int starting_nodeId ) {
		run_dijkstras(starting_nodeId);		// Ensure the calculations are ready
		unordered_map<int, double> path_weights;
		for( auto vert_pair : vertices ) {
			int nodeId = vert_pair.first;
			double weight = vert_pair.second->get_path_weight();
			path_weights[nodeId] = weight;
		}
		return path_weights;
	}

	//** Returns a vector for node ids from starting_nodeId to ending node
	std::vector<int> get_path_of_nodeIds(int starting_nodeId, int ending_nodeId) {
		std::vector<int> nodeIds_path;
		auto ptr_path = get_path(starting_nodeId, ending_nodeId);

		for( auto vert_ptr : ptr_path ) {
			nodeIds_path.push_back(vert_ptr->getId());
		}
		return nodeIds_path;
	}

	//** Get the optimal path from one node to the other in our graph
	list<DijkstraVertex*> get_path(int starting_nodeId, int ending_nodeId) {
		list<DijkstraVertex*> path;

		run_dijkstras(starting_nodeId);				// Ensure paths are established for the graph from starting node

		auto curr_itr = vertices.find( ending_nodeId );
		if( curr_itr == vertices.end() ) {
			// Ending nodeId is not in the graph, return empty vector
			return path;
		} else if( starting_nodeId == ending_nodeId ) {	// Starting == ending, and it's in the graph
			auto curr_vert = (*curr_itr).second;
			path.push_front(curr_vert);
			return path;
		} else if( (*curr_itr).second->get_path_ptr() == nullptr ) {	// No path found case
			return path;
		} else {
			auto curr_vert = (*curr_itr).second;
			path.push_front(curr_vert);	// pull out pointer from pair, add to front of list
			while( curr_vert->get_path_ptr() != nullptr ) {
				curr_vert = curr_vert->get_path_ptr();
				path.push_front(curr_vert);	// pull out pointer from pair, add to front of list
			}
		}
		return path;
	}

	//** Run Dijkstra's Algorithm from a selected nodeId for whole graph
	void run_dijkstras(int starting_nodeId) {
		if( vertices.find(starting_nodeId) == vertices.end() ) {
			return;						// Starting node not in graph - just bail
		} else if( starting_nodeId == current_dijkstras_starting_vertex_id ) {
			return;						// Starting node same as last run, bail
		} else {
			reset_dijkstras();				// Reset all of the bookkeeping data
			current_dijkstras_starting_vertex_id = starting_nodeId;	// Track which was last starting node run
		}

		// Heap of vertex pointers, stored internally in a vector, and using the custom path weight comparer
		// Comparer is found in DijkstraVertex.h
		priority_queue<DijkstraVertex*, vector<DijkstraVertex*>, PathWeightComparer> dijkstra_queue{};
		auto starting_vertex = vertices[starting_nodeId];

		// NOTE:
		//  You'll need to look at the interface for the DijkstraVertex class for how to access & modify vertexes
		//  You'll also need to look at this class' approach to storing vertices in an unordered_map

		// MA TODO: Insert Dijkstra's algorithm here:





		// MA END - Should have finished Dijkstra's algorithm by this point
	}
};


#endif
