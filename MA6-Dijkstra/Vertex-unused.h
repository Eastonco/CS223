/*
 *	Vertex node in the graph
 * 	 -- Includes features for Dijkstra's Algorithm
 *   -- Includes edges hash table for holding refs to other vertices
 * 
 *  Edge - utility/storage class
 *   -- Stores a pointer to a vertex and the weight of the edge
 *   -- Used in a hash table of edges adjacent to a vertex
 * 
 *  Contributors:
 *    Aaron S. Crandall <acrandal@gmail.com> - 2019
 * 
 */


#ifndef __VERTEX_H
#define __VERTEX_H

#include <iostream>
#include <string>
#include <unordered_map>	// For storing edges
#include <limits>			// For infinity representations

using namespace std;

//** Forward delcaration of Vertex so Edge can have the interface at compile time
class Vertex;

//
//** Class to hold a single edge - A vertex* and a weight (double)
class Edge
{
public:
	Vertex* vertex = nullptr;
	double weight = std::numeric_limits<double>::infinity();

	Edge(Vertex* newVert, double newWeight)
	{
		this->vertex = newVert;
		this->weight = newWeight;
	}
	std::string to_string();		// Forward declaration - see end of file for definition
};


//
//** Class to hold a single vertex in a graph
class Vertex
{
protected:						// Protected so that inherited Dijkstra's Vertex can read them
	int _id;                    // ID (key) of given vertice - must be unique!

	// Stores the other nodes as pointers and the weights of the edges to those nodes
	unordered_map<Vertex*, Edge*> _edges;  // Nodes adjacent to this vertex

public:
	Vertex(int id) {
		_id = id;
	}

	// Allow users to get our ID - for lookups and hashing/heaping
	int getId() const {
		return _id;
	}

	// Print out the vertex and optionally all of the edges
	std::string to_string( bool with_edges = false ) {
		std::string ret = "Vert: " + std::to_string(this->_id);

		if( with_edges ) {
			for( auto edge_pair : this->_edges ) {
				auto edge = edge_pair.second;
				ret += "\n  -> e: " + std::to_string(edge->vertex->getId()) + "  w: " + std::to_string(edge->weight);
			}
		}
		return ret;
	}

	// Edge management
	//  Edges are stores as entries in a hash table kept by this vertex
	void addEdge(Vertex* vertex, double weight) {
		_edges[vertex] = new Edge(vertex, weight);
	}

	double getEdgeWeight(Vertex* edge) {
		return _edges[edge]->weight;
	}

	unordered_map<Vertex*, Edge*> &getEdges() {
		return _edges;
	}

	void removeEdge(Vertex* vertex) {
		_edges.erase(vertex);
	}

	int edges_size() {
		return (int)_edges.size();
	}

};

/**
 *  Comparison operators used for sorting, treeing, and queuing
 *  These will provide functions to call when passed vertices to compare
 */
int operator==(const Vertex &lhs, const Vertex &rhs)
{
	return lhs.getId() == rhs.getId();
}

bool operator<(const Vertex &lhs, const Vertex &rhs)
{
	return lhs.getId() < rhs.getId();
}

bool operator>(const Vertex &lhs, const Vertex &rhs)
{
	return lhs.getId() > rhs.getId();
}


/**
 *  Hashing algorithm must exist in STD namespace
 *   Used by structures like unordered_map (it's a hash table)
 *   This is adding to the C++ STL unordered_map hash functions
 *   It will use polymorphism to handle a Vertex* type as the key in a hash table
 *   This function must return a size_t integer from anything we define in the vertex
 *   In our case, it just uses the _id of the Vertex
 */
namespace std {

	template <>
	struct hash<Vertex>
	{
		// Provide a hash (convert item into integer)
		std::size_t operator()(const Vertex& item) const
		{
			size_t hash_val = 0;
			hash<int> int_hash{};              // To hash INTs using the STL
			hash_val = int_hash(item.getId()); // Define hashing algorithm.
			return hash_val;                   // Add other hash algs as necessary
		}
	};
}


// Implemented here so the call to vertex->getId() is defined
std::string Edge::to_string() {
		std::string ret = std::to_string(this->vertex->getId()) + " w: " + std::to_string(this->weight);
		return ret;
	}

#endif
