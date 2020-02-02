/**
 *  Core graph data structure
 *   -- Overhauled to have better storage structures
 * 
 *  Contributors:
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   Aaron S. Crandall, 2019 <acrandal@gmail.com>
 */

#ifndef __GRAPH_H
#define __GRAPH_H

#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <list>
#include <unordered_map>

#include "Vertex.h"

using namespace std;

class Graph
{
	unordered_map<int, Vertex*> verticies;

public:
	// Remove all vertices
	void clear() {
		verticies.clear();
	}

	// Number of vertices in our graph
	std::size_t size() {
		return verticies.size();
	}

	int edges_size() {
		int count = 0;
		for( auto vert : this->verticies ) {
			count += (vert.second)->edges_size();
		}
		return(count);
	}

	/**
	 *  Parses a single in from a dot file
	 */
	void parseDotfileLine( string line, regex newSubGraph ) {
		smatch matched;

		if( regex_match( line, matched, newSubGraph ) ) {
			string strconv = matched[1];
			int srcid = (int)::atof(strconv.c_str());
			strconv = matched[2];
			int destid = (int)::atof(strconv.c_str());
			strconv = matched[3];
			double weight = ::atof(strconv.c_str());
			//cout << "SrcID: " << srcid << " | DestID: " << destid << " | Edge Weight: " << weight << endl;

			Vertex* newSrcVert;
			Vertex* newDestVert;
			auto found = verticies.find(srcid);
			if( found == verticies.end() ) {	// No vertex by that ID yet - create it
				newSrcVert = new Vertex(srcid);
				verticies[srcid] = newSrcVert;
			} else {
				newSrcVert = (*found).second;
			}

			found = verticies.find(destid);
			if( found == verticies.end() ) {	// No vertex by that ID yet - create it
				newDestVert = new Vertex(destid);
				verticies[destid] = newDestVert;
			} else {
				newDestVert = (*found).second;
			}

			newSrcVert->addEdge(newDestVert, weight);
		}
	}

	/**
	 *  Loads a single Graphviz-(limited) formatted dot file with a graph
	 */
	void loadDotFile( string filename ) {
		cout << " Loading dot file: " << filename;
		ifstream ifs( filename );
		string instr;
		regex newSubGraph ("\\s*(\\S+)\\s*->\\s*(\\S+)\\s*\\[.*?weight=\"*(\\S+?)\"*\\s*\\]\\;");
		while (getline(ifs, instr)) {
			parseDotfileLine( instr, newSubGraph );
		}
		cout << " - Done." << endl;
	}

	/**
	 *  Returns stringified version of graph for viewing
	 */
	string to_string( bool with_edges = false ) {
		string ret = "Graph: \n";
		for( auto vert : this->verticies ) {
			ret += (vert.second)->to_string( with_edges ) + "\n";
		}
		return ret;
	}

	//** Runs topological sort on this graph
	void run_topological_sort() {
		//** Start of toposort algorithm **//

		//** Algorithm complete
	}

	//** Returns a vector of Node IDs from the topological sort
	vector<int> get_topological_sort_vector() {
		vector<int> toposort_results = {};

		// TODO: Extra Credit algorithm work goes here

		return toposort_results;
	}
};


#endif
