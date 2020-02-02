/*
 *  Dijkstra's Algorithm 
 *   Aaron S. Crandall, 2017 - <acrandal@gmail.com>
 */

#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

/**
 *  Normal mode execution for general user control
 */
void run_normal_mode() {
	cout << "Nothing to do in normal mode so here's a hat: " << endl;

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
" To run the Facebook data graph, use 'make big-tests', which takes about 1/4 sec for me. \n"
" You'll find images of the graphs we're using in:\n"
"     topoGraph.png\n"
"\n"
" Both built using: neato -Tpng topoGraph.dot -o topoGraph.png\n"
"  You might need to install graphviz to get the neato tool\n";
}




/**
 *  Main function for test or use
 */
int main( int argc, char* argv[] )
{
	run_normal_mode();      // yeah, nothing to see here
}

