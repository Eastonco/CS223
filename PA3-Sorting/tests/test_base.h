/*
 *  Test suite for BST Level Order project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __BASE_TESTS_H
#define __BASE_TESTS_H

#include <vector>
#include <functional>       // For passing functions into functions
#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library

#include "main.h"                   // Sorting Stats
#include "instrumentedBubbleSort.h" // Starter sorting algorithm
#include "instrumentedInsertionSort.h" 
#include "instrumentedMergeSort.h" 
#include "instrumentedQuickSort.h"
#include "testVectors.h"
#include "test_tools.h"

using namespace testing;    // gtest lives in the testing:: namespace


//**************** Start of Sorting Algorithm Tests ********************//
TEST(Base_InsertionSort, BasicSort_Presorted_Len20)
{
    int data_vector_length = 20;
    sort_test<SortedTestVector>(instrumentedInsertionSort, data_vector_length);
}

TEST(Base_InsertionSort, BasicSort_ReverseSorted_Len20)
{
    int data_vector_length = 20;
    sort_test<ReversedTestVector>(instrumentedInsertionSort, data_vector_length);
}

TEST(Base_InsertionSort, BasicSort_Shuffled_Len20)
{
    int data_vector_length = 20;
    sort_test<ShuffledTestVector>(instrumentedInsertionSort, data_vector_length);
}

TEST(Base_InsertionSort, StatsTest_Compares)
{
    int data_vector_length = 20;
    stats_test<ShuffledTestVector>(instrumentedInsertionSort, data_vector_length);
}

//*** Start of MergeSort tests **********************************

TEST(Base_MergeSort, BasicSort_Presorted_Len20)
{
    int data_vector_length = 20;
    sort_test<SortedTestVector>(instrumentedMergeSort, data_vector_length);
}

TEST(Base_MergeSort, BasicSort_ReverseSorted_Len20)
{
    int data_vector_length = 20;
    sort_test<ReversedTestVector>(instrumentedMergeSort, data_vector_length);
}

TEST(Base_MergeSort, BasicSort_Shuffled_Len20)
{
    int data_vector_length = 20;
    sort_test<ShuffledTestVector>(instrumentedMergeSort, data_vector_length);
}

TEST(Base_MergeSort, StatsTest_Compares)
{
    int data_vector_length = 20;
    stats_test<ShuffledTestVector>(instrumentedMergeSort, data_vector_length);
}

TEST(Base_MergeSort, StatsTest_Compares_30k_Elements)
{
    int data_vector_length = 30000;
    int random_seed = 90210;
    stats_test<ShuffledTestVector>(instrumentedMergeSort, data_vector_length, random_seed);
}

//*** Start of QuickSort tests **********************************

TEST(Base_QuickSort, BasicSort_Presorted_Len20)
{
    int data_vector_length = 20;
    sort_test<SortedTestVector>(instrumentedQuickSort, data_vector_length);
}

TEST(Base_QuickSort, BasicSort_ReverseSorted_Len20)
{
    int data_vector_length = 20;
    sort_test<ReversedTestVector>(instrumentedQuickSort, data_vector_length);
}

TEST(Base_QuickSort, BasicSort_Shuffled_Len20)
{
    int data_vector_length = 20;
    sort_test<ShuffledTestVector>(instrumentedQuickSort, data_vector_length);
}

TEST(Base_QuickSort, StatsTest_Compares)
{
    int data_vector_length = 20;
    stats_test<ShuffledTestVector>(instrumentedQuickSort, data_vector_length);
}

TEST(Base_QuickSort, StatsTest_Compares_30k_Elements)
{
    int data_vector_length = 30000;
    int random_seed = 90210;
    stats_test<ShuffledTestVector>(instrumentedQuickSort, data_vector_length, random_seed);
}

//** Full stats generation and printout **********************************
TEST(Base_FullStats, Presorted_n20)
{
    int n = 20;
    algorithm_comparison_test<SortedTestVector>(n);
}
TEST(Base_FullStats, Reverse_Sorted_n20)
{
    int n = 20;
    algorithm_comparison_test<ReversedTestVector>(n);
}
TEST(Base_FullStats, Shuffled_n20)
{
    int n = 20;
    int seed = 90210;
    algorithm_comparison_test<ShuffledTestVector>(n, seed);
}

TEST(Base_FullStats, Presorted_n1k)
{
    int n = 1000;
    algorithm_comparison_test<SortedTestVector>(n);
}
TEST(Base_FullStats, Reverse_Sorted_n1k)
{
    int n = 1000;
    algorithm_comparison_test<ReversedTestVector>(n);
}
TEST(Base_FullStats, Shuffled_n1k)
{
    int n = 1000;
    int seed = 90210;
    algorithm_comparison_test<ShuffledTestVector>(n, seed);
}

//** BIG tests! - See Big* filter in Makefile: make big-tests
TEST(Big_FullStats, Presorted_n30k)
{
    int n = 30000;
    algorithm_comparison_test<SortedTestVector>(n);
}
TEST(Big_FullStats, Reverse_Sorted_n30k)
{
    int n = 30000;
    algorithm_comparison_test<ReversedTestVector>(n);
}
TEST(Big_FullStats, Shuffled_n30k)
{
    int n = 30000;
    int seed = 90210;
    algorithm_comparison_test<ShuffledTestVector>(n, seed);
}

#endif
