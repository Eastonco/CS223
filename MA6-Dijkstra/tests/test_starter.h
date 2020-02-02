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

#include "DijkstraGraph.h"              // Our Graph library

using namespace testing;        // gtest lives in the testing:: namespace

//**************** Start of Heap API tests ********************//
TEST(Starter_DijkstraGraph, Book_Dijkstra_Output)
{
    DijkstraGraph graph;
    graph.loadDotFile("bookGraph.dot");
    cout << graph.to_string(true);
}

TEST(Starter_DijkstraGraph, Size_When_Empty)
{
    DijkstraGraph graph;
    ASSERT_EQ(0, graph.size());
}

TEST(Starter_DijkstraGraph, Edges_Size_When_Empty)
{
    DijkstraGraph graph;
    ASSERT_EQ(0, graph.edges_size());
}

TEST(Starter_DijkstraGraph, Size_When_Book_Graph)
{
    DijkstraGraph graph;
    int expected_vertex_count = 8;
    graph.loadDotFile("bookGraph.dot");
    ASSERT_EQ(expected_vertex_count, graph.size());
}

TEST(Starter_DijkstraGraph, Edges_Size_When_Book_Graph)
{
    DijkstraGraph graph;
    int expected_edge_count = 12;
    graph.loadDotFile("bookGraph.dot");
    ASSERT_EQ(expected_edge_count, graph.edges_size());
}

TEST(Starter_DijkstraGraph, Path_When_No_Graph_Data)
{
    DijkstraGraph graph;
    int expected_path_size = 0;
    auto path = graph.get_path(1, 2);               // No graph, so should be empty list
    ASSERT_EQ(expected_path_size, path.size());
}

#endif
