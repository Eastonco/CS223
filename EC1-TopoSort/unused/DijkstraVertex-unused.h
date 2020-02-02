/*
 *	Dijkstra style Vertex nodes in the graph
 * 	 -- Includes features for Dijkstra's Algorithm
 *   -- Includes edges hash table for holding refs to other vertices
 * 
 *  Contributors:
 *    Aaron S. Crandall <acrandal@gmail.com> - 2019
 * 
 */


#ifndef __DIJKSTRA_VERTEX_H
#define __DIJKSTRA_VERTEX_H

#include <iostream>
#include <string>
#include <unordered_map>	// For storing edges
#include <limits>			// For infinity representations
#include <sstream>

using namespace std;


template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

//** Forward delcaration of Vertex so Edge can have the interface at compile time
class DijkstraVertex;

//
//** Class to hold a single edge - A vertex* and a weight (double)
class Edge
{
public:
	DijkstraVertex* dijkstra_vertex = nullptr;
	double weight = std::numeric_limits<double>::infinity();

	Edge(DijkstraVertex* newVert, double newWeight)
	{
		this->dijkstra_vertex = newVert;
		this->weight = newWeight;
	}
	std::string to_string();		// Forward declaration - see end of file for definition
};

//** Class to hold a single Dijkstra style vertex in a graph
class DijkstraVertex
{


private:

	int _id;                    // ID (key) of given vertice - must be unique!

	// Stores the other nodes as pointers and the weights of the edges to those nodes
	unordered_map<DijkstraVertex*, Edge*> _edges;  // Nodes adjacent to this vertex


	// Dijkstra's Algorithm book keeping fields
	bool _known = false;        // Dijkstra's algorithm "known" flag
	DijkstraVertex* _path = nullptr;    // Dijkstra's algorithm parent vertex pointer
	    // Weight of path through graph - starts at a true infinity (inf)
	double _path_weight = std::numeric_limits<double>::infinity();


public:
	DijkstraVertex( int id ) {		// id must be unique for all verticies
		_id = id;
	}

	// Dijkstra's book keeping interfaces
	double get_path_weight() const {
		return _path_weight;
	}

	void set_path_weight(double weight) {
		_path_weight = weight;
	}

	void unset_path_weight() {
		_path_weight = std::numeric_limits<double>::infinity();
	}

	bool is_known() const {
		return _known;
	}

	void set_known() {
		_known = true;
	}

	void unset_known() {
		_known = false;
	}
	
	void set_path_ptr(DijkstraVertex* path) {
		_path = path;
	}

	DijkstraVertex* get_path_ptr() {
		return _path;
	}

	void unset_path_ptr() {
		_path = nullptr;
	}

	void reset_dijkstras_bookkeeping() {
		unset_known();
		unset_path_ptr();
		unset_path_weight();
	}

	// Print out the vertex and optionally all of the edges
	std::string to_string( bool with_edges = false ) {
		int weight_precision_output = 8;
		std::string ret = "Dijkstra Vert: " + std::to_string(this->_id);
		ret += "\t known: ";
		ret += ((_known) ? "True" : "False");
		ret += "\t path: ";
		ret += ((_path) ? std::to_string(_path->getId()) : "nullptr");
		ret += "\t weight: ";
		ret += to_string_with_precision<double>(_path_weight, weight_precision_output);

		if( with_edges ) {
			for( auto edge_pair : this->_edges ) {
				auto edge = edge_pair.second;
				ret += "\n\t-> adjacent: " + std::to_string(edge->dijkstra_vertex->getId()) + "  weight: " + to_string_with_precision<double>(edge->weight, weight_precision_output);
			}
		}
		return ret;
	}

	// Allow users to get our ID - for lookups and hashing/heaping
	int getId() const {
		return _id;
	}

	// Edge management
	//  Edges are stores as entries in a hash table kept by this vertex
	void addEdge(DijkstraVertex* vertex, double weight) {
		_edges[vertex] = new Edge(vertex, weight);
	}

	double getEdgeWeight(DijkstraVertex* edge) {
		return _edges[edge]->weight;
	}

	unordered_map<DijkstraVertex*, Edge*> &getEdges() {
		return _edges;
	}

	void removeEdge(DijkstraVertex* vertex) {
		_edges.erase(vertex);
	}

	int edges_size() {
		return (int)_edges.size();
	}
};

/**
 *  Class used to compare path weights in priority queues
 *   This definition makes it prefer the lower path weight of the two vertices
 */
class PathWeightComparer
	{
	public:
		bool operator()(const DijkstraVertex* lhs, const DijkstraVertex* rhs)
		{
			return (lhs->get_path_weight() > rhs->get_path_weight());
		}
	};


// Implemented here so the call to dijkstravertex->getId() is defined
std::string Edge::to_string() {
		std::string ret = std::to_string(this->dijkstra_vertex->getId()) + " w: " + std::to_string(this->weight);
		return ret;
}


#endif
