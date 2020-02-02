/*
 *  Test suite for BST Level Order project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __BASE_TESTS_H
#define __BASE_TESTS_H

#include <vector>
#include <chrono>           // For timing tests
#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library
#include "Heap.h"

using namespace testing;    // gtest lives in the testing:: namespace


//**************** Start of Heap Algorithm Tests ********************//
TEST(Base_HeapAlg, PercolateUp_Single)
{
    Heap<int> heap;
    heap.push(10);
    heap.push(5);
    std::vector<int> expected_vector({5, 10});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}

TEST(Base_HeapAlg, PercolateUp_Two_Levels)
{
    Heap<int> heap;
    heap.push(10);
    heap.push(15);
    heap.push(20);
    heap.push(5);   // Should percolate two levels to root

    std::vector<int> expected_vector({5, 10, 20, 15});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}

TEST(Base_HeapAlg, PercolateUp_Two_Pushes)
{
    Heap<int> heap;
    heap.push(10);
    heap.push(15);
    heap.push(20);
    heap.push(5);   // Should percolate two levels to root
    heap.push(8);   // Should percolate one level up

    std::vector<int> expected_vector({5, 8, 20, 15, 10});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}


TEST(Base_HeapAlg, Percolate_Down_Small_Single_Left)
{
    Heap<int> heap;
    heap.push(10);
    heap.push(15);
    heap.push(20);
    heap.push(40);
    heap.push(30);      // No percolations

    // Act
    heap.pop();         // Runs percolateDown one level

    // Assert
    std::vector<int> expected_vector({15, 30, 20, 40});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}

TEST(Base_HeapAlg, Percolate_Down_Small_Right)
{
    Heap<int> heap;
    heap.push(10);
    heap.push(20);
    heap.push(15);
    heap.push(40);
    heap.push(30);      // No percolations

    // Act
    heap.pop();         // Runs percolateDown one level

    // Assert
    std::vector<int> expected_vector({15, 20, 30, 40});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}

TEST(Base_HeapAlg, Percolate_Down_Med_Both_Children)
{
    Heap<int> heap;
    heap.push(10);
    heap.push(15);
    heap.push(20);
    heap.push(40);
    heap.push(30);
    heap.push(50);
    heap.push(60);
    heap.push(70);
    heap.push(80);
    heap.push(35);      // No percolations

    // Act
    heap.pop();         // Runs percolateDown 

    // Assert
    std::vector<int> expected_vector({15, 30, 20, 40, 35, 50, 60, 70, 80});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));
}

TEST(Base_HeapAlg, Percolates_Both_Types)
{
    std::vector<int> test_vals({890, 567, 456, 921, 678, 123, 234, 345, 750, 101});
    Heap<int> heap;

    for( auto val : test_vals ) {
        heap.push(val);             // Causes percolate ups
    }

    std::vector<int> expected_vector({101, 123, 234, 678, 345, 567, 456, 921, 750, 890});
    std::vector<int> found_vector = heap.get_contents();

    std::cout << "After inserting heap values --" << std::endl;
    std::cout << "Heap should be : ";
    for(auto val : expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl << std::endl;

    ASSERT_THAT(found_vector, ElementsAreArray(expected_vector));

    for( int i = 0; i < 3; ++i )
        heap.pop();
    std::vector<int> popped_expected_vector({345, 678, 456, 921, 890, 567, 750});
    std::vector<int> popped_found_vector = heap.get_contents();

    std::cout << "After three pops heap values --" << std::endl;
    std::cout << "Heap should be : ";
    for(auto val : popped_expected_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    std::cout << "Heap acually is: ";
    for(auto val : popped_found_vector)
        std::cout << std::setw(4) << val;
    std::cout << std::endl;

    ASSERT_THAT(popped_found_vector, ElementsAreArray(popped_expected_vector));
}

#endif
