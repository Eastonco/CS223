/*
 *  Test suite for Dijkstra's Algorithm project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __STARTER_TESTS_H
#define __STARTER_TESTS_H

#include <vector>
#include <gtest/gtest.h>        // Google's C++ testing harness
#include <gmock/gmock.h>        // Google's object mocking library

#include "Graph.h"              // Our Graph library

#define GRAPH_DOT_FILE "topoGraph.dot"

using namespace testing;        // gtest lives in the testing:: namespace

//**************** Start of Heap API tests ********************//
TEST(Starter_Graph, Topo_Graph_Output)
{
    Graph graph;
    graph.loadDotFile(GRAPH_DOT_FILE);
    cout << graph.to_string(true);
}

TEST(Starter_Graph, Size_When_Empty)
{
    Graph graph;
    ASSERT_EQ(0, graph.size());
}

TEST(Starter_Graph, Edges_Size_When_Empty)
{
    Graph graph;
    ASSERT_EQ(0, graph.edges_size());
}

TEST(Starter_Graph, Size_When_Topo_Graph)
{
    Graph graph;
    int expected_vertex_count = 17;
    graph.loadDotFile(GRAPH_DOT_FILE);
    ASSERT_EQ(expected_vertex_count, graph.size());
}

TEST(Starter_Graph, Edges_Size_When_Topo_Graph)
{
    Graph graph;
    int expected_edge_count = 22;
    graph.loadDotFile(GRAPH_DOT_FILE);
    ASSERT_EQ(expected_edge_count, graph.edges_size());
}

TEST(Starter_Graph, Empty_Graph_Topological_Sort_Vector) {
    Graph graph;
    vector<int> expected_output = {};
    auto found_output = graph.get_topological_sort_vector();
    ASSERT_THAT(found_output, ElementsAreArray(expected_output));
}

#endif
