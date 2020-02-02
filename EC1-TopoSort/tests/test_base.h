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

#include "Graph.h"
#include "Vertex.h"

#define GRAPH_DOT_FILE "topoGraph.dot"

using namespace testing;    // gtest lives in the testing:: namespace


//**************** Start of Heap Algorithm Tests ********************//
TEST(Base_TopoSort, SortTest)
{
    Graph graph;

    vector<pair<int, int>> expected_dependencies = {
        make_pair<int,int>(0,8), make_pair<int,int>(0,16), make_pair<int,int>(0,12),
        make_pair<int,int>(0,5), make_pair<int,int>(8,5), make_pair<int,int>(8,11),
        make_pair<int,int>(8,14), make_pair<int,int>(1,8), make_pair<int,int>(1,9),
        make_pair<int,int>(1,10), make_pair<int,int>(1,2), make_pair<int,int>(10,4),
        make_pair<int,int>(10,14), make_pair<int,int>(9,7), make_pair<int,int>(15,14),
        make_pair<int,int>(15,4), make_pair<int,int>(3,13), make_pair<int,int>(3,12)
    };

    graph.loadDotFile(GRAPH_DOT_FILE);
    auto found_output = graph.get_topological_sort_vector();

    cout << "Toposort returned vector of node Ids with this inside: " << endl << "{";
    for( auto val : found_output ) {
        cout << val << " ";
    }
    cout << "}" << endl << endl;
    cout << "---------------------------------------" << endl;

    for( auto curr_pair : expected_dependencies ) {
        int earlier_Id = curr_pair.first;
        int later_Id = curr_pair.second;

        cout << " Checking pair of nodes: " << earlier_Id << " should be before " << later_Id;

        int earlier_Id_index = -1;
        int later_Id_index = -1;

        auto itr = std::find(found_output.begin(), found_output.end(), earlier_Id);
        if (itr != found_output.end() ){
            //std::cout << "Element present at index ";
            //std::cout << std::distance(found_output.begin(), itr );
            //std::cout << endl;
            earlier_Id_index = (int)std::distance(found_output.begin(), itr );
        }
        else
        {
            //std::cout << "Err- Node id not found in topo output vector: " << earlier_Id << endl;
        }

        itr = std::find(found_output.begin(), found_output.end(), later_Id);
        if (itr != found_output.end() ){
            //std::cout << "Element present at index ";
            //std::cout << std::distance(found_output.begin(), itr );
            //std::cout << endl;
            later_Id_index = (int)std::distance(found_output.begin(), itr );
        }
        else
        {
            //std::cout << "Err- Node id not found in topo output vector: " << later_Id << endl;
        }

        if( later_Id_index > earlier_Id_index ) {
            cout << " -- True / Pass " << endl;
        }
        else
        {
            cout << " -- False / Fail " << endl;
        }
        
        EXPECT_GT(later_Id_index, earlier_Id_index);
    }
}


TEST(Big_TopoSort, FacebookData){
    Graph graph;

    vector<pair<int, int>> expected_dependencies = {
        make_pair<int,int>(1,346), make_pair<int,int>(757,756), make_pair<int,int>(3883,3917),
        make_pair<int,int>(171,8)
    };

    graph.loadDotFile("facebook-decycled.dot");
    auto found_output = graph.get_topological_sort_vector();
    cout << "Big Facebook graph vertices: " << graph.size() << " with " << graph.edges_size() << " edges " << endl;

    cout << "Toposort returned vector of node Ids with this inside: " << endl << "{";
    for( auto val : found_output ) {
        cout << val << " ";
    }
    cout << "}" << endl << endl;
    cout << "---------------------------------------" << endl;

    for( auto curr_pair : expected_dependencies ) {
        int earlier_Id = curr_pair.first;
        int later_Id = curr_pair.second;

        cout << " Checking pair of nodes: " << earlier_Id << " should be before " << later_Id;

        int earlier_Id_index = -1;
        int later_Id_index = -1;

        auto itr = std::find(found_output.begin(), found_output.end(), earlier_Id);
        if (itr != found_output.end() ){
            //std::cout << "Element present at index ";
            //std::cout << std::distance(found_output.begin(), itr );
            //std::cout << endl;
            earlier_Id_index = (int)std::distance(found_output.begin(), itr );
        }
        else
        {
            //std::cout << "Err- Node id not found in topo output vector: " << earlier_Id << endl;
        }

        itr = std::find(found_output.begin(), found_output.end(), later_Id);
        if (itr != found_output.end() ){
            //std::cout << "Element present at index ";
            //std::cout << std::distance(found_output.begin(), itr );
            //std::cout << endl;
            later_Id_index = (int)std::distance(found_output.begin(), itr );
        }
        else
        {
            //std::cout << "Err- Node id not found in topo output vector: " << later_Id << endl;
        }

        if( later_Id_index > earlier_Id_index ) {
            cout << " -- True / Pass " << endl;
        }
        else
        {
            cout << " -- False / Fail " << endl;
        }
        
        EXPECT_GT(later_Id_index, earlier_Id_index);
    }
}

#endif
