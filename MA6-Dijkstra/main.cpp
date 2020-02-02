/*
 *  Dijkstra's Algorithm 
 *   Aaron S. Crandall, 2017 - <acrandal@gmail.com>
 */

#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "DijkstraVertex.h"
#include "DijkstraGraph.h"

using namespace std;

/**
 *  Normal mode execution for general user control
 */
void run_normal_mode() {
	cout << "  [!] Nothing to do in normal mode so here's a hat: " << endl;

cout <<""
"       _.-'`'-._\n"
"    .-'    _    '-.\n"
"     `-.__  `\\_.-'\n"
"       |  `-``\\|\n"
" jgs   `-.....-A\n"
"               #\n"
"               #\n";
	cout << endl;
	cout << " Oh, and you should probably run 'make test' to test your program. \n"
" To run the mouse brain graph, use 'make bigtest', which takes about 15 sec for me. \n"
" You'll find images of the graphs we're using in:\n"
"     bookGraph.png\n"
"     MouseBrainGraph.png (currently being built - fingers crossed)\n"
"\n"
" Both built using: neato -Tpng bookGraph.dot -o bookGraph.png\n"
" Both built using: neato -Tpng MouseBrainGraph.dot -o MouseBrainGraph.png\n";
}




/**
 *  Main function for test or use
 */
int main( int argc, char* argv[] )
{
	// Note: If you call this program like this: ./Dijkstra --test
	//  it will call the test function

	//run_normal_mode();

	//DijkstraVertex* vert = new DijkstraVertex(20);
	//DijkstraVertex* adj = new DijkstraVertex(30);

	//vert->addEdge(adj, 0.5);
	//cout << vert->to_string(true) << endl;

	//DijkstraVertex* dvert = new DijkstraVertex(40); 

	DijkstraGraph graph;
	graph.loadDotFile("./MouseBrainGraph.dot");

	cout << graph.to_string() << endl;

	cout << "Vertex count: " << graph.size() << endl;
	cout << "Edge count: " << graph.edges_size() << endl;
	cout << endl;

	cout << "Running Dijkstra's from node 8" << endl;
	graph.run_dijkstras(8);			// Start at nodeId #8

	cout << "Post Dijkstra's from node 1" << endl;
	cout << graph.to_string() << endl;
}

