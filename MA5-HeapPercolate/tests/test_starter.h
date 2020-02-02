/*
 *  Test suite for Hashing based duplicates project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __STARTER_TESTS_H
#define __STARTER_TESTS_H

#include <vector>
#include <gtest/gtest.h>        // Google's C++ testing harness
#include <gmock/gmock.h>        // Google's object mocking library
#include "Heap.h"

using namespace testing;    // gtest lives in the testing:: namespace

//**************** Start of Heap API tests ********************//
TEST(Starter_HeapAPI, Empty)
{
    Heap<int> heap;
    ASSERT_EQ(true, heap.empty());
}

TEST(Starter_HeapAPI, Size_When_Empty)
{
    Heap<int> heap;
    ASSERT_EQ(0, heap.size());
}

TEST(Starter_HeapAPI, Push_No_Percolate)
{
    Heap<int> heap;
    heap.push(15);
    ASSERT_EQ(true, true);
}

TEST(Starter_HeapAPI, EmptyFalse)
{
    Heap<int> heap;
    heap.push(10);
    ASSERT_EQ(false, heap.empty());
}

TEST(Starter_HeapAPI, Size1)
{
    Heap<int> heap;
    heap.push(10);
    ASSERT_EQ(1, heap.size());
}

TEST(Starter_HeapAPI, SizeN_No_Percolate)
{
    Heap<int> heap;
    int n = 40;
    for(int i = 1; i <= n; ++i){
        heap.push(i);
        ASSERT_EQ(i, heap.size());
    }
}

TEST(Starter_HeapAPI, Top_No_Percolate)
{
    Heap<int> heap;
    heap.push(70);
    ASSERT_EQ(70, heap.top());
}

TEST(Starter_HeapAPI, Top_Out_Of_Range_Exception)
{
    Heap<int> heap;
    ASSERT_THROW(heap.top(), std::out_of_range);
}

TEST(Starter_HeapAPI, Pop_Out_Of_Range_Exception)
{
    Heap<int> heap;
    ASSERT_THROW(heap.pop(), std::out_of_range);
}

TEST(Starter_HeapAPI, Pop_No_Percolate)
{
    Heap<int> heap;
    heap.push(20);
    heap.push(40);
    heap.push(30);
    ASSERT_EQ(false, heap.empty());
    ASSERT_EQ(3, heap.size());
    ASSERT_EQ(20, heap.top());

    heap.pop();                 // Remove root of heap
    ASSERT_EQ(false, heap.empty());
    ASSERT_EQ(2, heap.size());
    ASSERT_EQ(30, heap.top());

    heap.pop();                 // Remove root of heap
    ASSERT_EQ(false, heap.empty());
    ASSERT_EQ(1, heap.size());
    ASSERT_EQ(40, heap.top());

    heap.pop();                 // Remove root of heap
    ASSERT_EQ(true, heap.empty());
    ASSERT_EQ(0, heap.size());
}

TEST(Starter_HeapAPI, Get_Contents_No_Percolate)
{
    Heap<int> heap;
    std::vector<int> expected_vector;
    std::vector<int> found_vector;
    for(int i = 0; i < 8; ++i) {
        heap.push(i*2);                   // Should never percolate
        expected_vector.push_back(i*2);   // Should be heap contents
    }
    found_vector = heap.get_contents();
    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}

#endif
