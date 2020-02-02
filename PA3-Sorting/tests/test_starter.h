/*
 *  Test suite for Hashing based duplicates project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __STARTER_TESTS_H
#define __STARTER_TESTS_H

#include <gtest/gtest.h>        // Google's C++ testing harness
#include <gmock/gmock.h>        // Google's object mocking library

#include "main.h"                   // Sorting Stats
#include "instrumentedBubbleSort.h" // Base sorting algorithm
#include "testVectors.h"
#include "test_tools.h"

using namespace testing;    // gtest lives in the testing:: namespace

//**************** Start of Heap API tests ********************//
TEST(Starter_BubbleSort, BasicSort_Presorted_Len20)
{
    int data_vector_length = 20;
    sort_test<SortedTestVector>(instrumentedBubbleSort, data_vector_length);
}

TEST(Starter_BubbleSort, BasicSort_ReverseSorted_Len20)
{
    int data_vector_length = 20;
    sort_test<ReversedTestVector>(instrumentedBubbleSort, data_vector_length);
}

TEST(Starter_BubbleSort, BasicSort_Shuffled_Len20)
{
    int data_vector_length = 20;
    sort_test<ShuffledTestVector>(instrumentedBubbleSort, data_vector_length);
}

TEST(Starter_BubbleSort, StatsTest_Compares)
{
    int data_vector_length = 20;
    stats_test<ShuffledTestVector>(instrumentedBubbleSort, data_vector_length, 90210);
}


#endif
