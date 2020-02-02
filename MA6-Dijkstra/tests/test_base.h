/*
 *  Test suite for Dijkstra's Algorithm project
 *
 *   All tests should begin with Base* for their group name
 *
 */

#ifndef __BASE_TESTS_H
#define __BASE_TESTS_H

#include <vector>
#include <unordered_map>
#include <list>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library

#include "DijkstraGraph.h"
#include "DijkstraVertex.h"

using namespace testing;    // gtest lives in the testing:: namespace


//**************** Start of Heap Algorithm Tests ********************//
TEST(Base_Dijkstra, Book_Dijkstra_Output_StartNode_1)
{
    DijkstraGraph graph;
    int starting_node = 1;
    graph.loadDotFile("bookGraph.dot");
    graph.run_dijkstras(starting_node);
    cout << graph.to_string(true);
}

TEST(Base_Dijkstra, Book_Dijkstra_Path_1_2)
{
    vector<int> expected_node_ids = {1, 2};
    int starting_node = 1;
    int ending_node = 2;
    DijkstraGraph graph;
    graph.loadDotFile("bookGraph.dot");
    graph.run_dijkstras(starting_node);

    auto path = graph.get_path_of_nodeIds(starting_node, ending_node);
    ASSERT_THAT(path, ElementsAreArray(expected_node_ids));
}

TEST(Base_Dijkstra, Book_Dijkstra_Path_1_6)
{
    vector<int> expected_node_ids = {1, 4, 7, 6};
    int starting_node = 1;
    int ending_node = 6;
    DijkstraGraph graph;
    graph.loadDotFile("bookGraph.dot");
    graph.run_dijkstras(starting_node);

    auto path = graph.get_path_of_nodeIds(starting_node, ending_node);
    ASSERT_THAT(path, ElementsAreArray(expected_node_ids));
}

TEST(Base_Dijkstra, Book_Dijkstra_NoPath_0_7)
{
    vector<int> expected_node_ids = {};     // No path from 0 to 7 (disconnected graph)
    int starting_node = 0;
    int ending_node = 7;
    DijkstraGraph graph;
    graph.loadDotFile("bookGraph.dot");
    graph.run_dijkstras(starting_node);

    auto path = graph.get_path_of_nodeIds(starting_node, ending_node);
    ASSERT_THAT(path, ElementsAreArray(expected_node_ids));
}

TEST(Base_Dijkstra, Book_Dijkstra_All_Path_Weights_From_2)
{
    unordered_map<int, double> expected_weights = {
        {4, 3}, {2, 0}, {1, 9}, {7, 7}, {6, 8}, {3, 5}, {5, 5}, {0, std::numeric_limits<double>::infinity()}
    };

    int starting_node = 2;
    DijkstraGraph graph;
    graph.loadDotFile("bookGraph.dot");
    graph.run_dijkstras(starting_node);

    auto path_weights = graph.get_all_path_weights(starting_node);

    ASSERT_EQ(path_weights, expected_weights);
}

//** Some BIG tests on the Mouse Brain graph ********************************

TEST(Big_Mouse, Big_Brain_All_Paths_Instrumented)
{
    DijkstraGraph graph;
    int starting_node = 8;
    cout << "Loading Big graph: A subset of a Mouse Brain neuron topology structure" << endl;
    cout << "Note: this takes 30 seconds to load on my computer -- patience! " << endl;
    graph.loadDotFile("MouseBrainGraph.dot");
    cout << "Brain loaded -- Stats:" << endl;
    cout << "Vertex count: " << graph.size() << endl;
	cout << "Edge count: " << graph.edges_size() << endl;
    cout << " ... just a quick pause" << endl;
    std::this_thread::sleep_for( std::chrono::seconds(3));
    cout << "Running Dijkstra's Algorithm from node 8 (connected, arbitrarily chosen)" << endl;
    graph.run_dijkstras(starting_node);
    cout << "Dijstra's complete, showing results" << endl;
    cout << graph.to_string();                  // Show without edges!
    cout << " Now calculating stats on Dijkstra's from all nodes " << endl;
    cout << " Yes, this will take a bit ~= O(|V|^2 + |V| * (|E| log |V|)).. you did say 'big-test', right? " << endl;

    auto all_vertex_ids = graph.get_all_vertex_ids();
    long long total_dijkstras_time = 0;
    size_t longest_path_len = 0;

    for( int curr_Id : all_vertex_ids ) {
        cout << "Curr ID: " << setw(3) << curr_Id << " || Dijkstra's runtime: " << std::flush;
        auto start = std::chrono::high_resolution_clock::now();
        graph.run_dijkstras(curr_Id);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        cout << setw(5) << microseconds << "us" << std::flush;
        total_dijkstras_time += microseconds;

        std::pair<int, double> max_weight = graph.get_highest_path_weight(curr_Id);
        cout << " | Heaviest node: " << setw(3) << max_weight.first << " @ weight: " << max_weight.second << endl;

        auto longest_path = graph.get_longest_path(curr_Id);
        if( longest_path.size() > longest_path_len ) {
            longest_path_len = longest_path.size();
        }
        cout << "  #> Longest path: ";
        for( auto vert : longest_path ) {
            cout << vert->getId() << " -> ";
        }
        cout << endl;
    }

    cout << endl << "-----------------------------------------------------------------" << endl;
    cout << "Sum stats on Mouse Brain graph: " << endl;
    cout << " Vertex count: " << graph.size() << endl;
	cout << " Edge count: " << graph.edges_size() << endl;
    cout << " Longest path length: " << longest_path_len << endl;
    cout << " Total time to run Dijkstra's on all nodes: " << total_dijkstras_time << "us" << endl;
    cout << " Average Dijkstra's runtime for a node: " << (double)total_dijkstras_time / (double)graph.size() << "us" << endl;
}

#endif
