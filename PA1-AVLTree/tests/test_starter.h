/*
 *  Test suite for BST Level Order project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __STARTER_TESTS_H
#define __STARTER_TESTS_H

#include <vector>
#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library
using namespace testing;    // gtest lives in the testing:: namespace


//**************** Start of Node Tests ********************//
TEST(StarterAVLNode, BasicInitializer)
{
    // Assemble
    int testValue = 13;
    AVLNode<int> node = AVLNode<int>(testValue);
    // Assert
    ASSERT_EQ(testValue, node.val);
    ASSERT_EQ(nullptr, node.left);
    ASSERT_EQ(nullptr, node.right);
}

TEST(StarterAVLNode, InitializeChildren)
{
    // Assemble
    int testValue = 13;
    AVLNode<int> * leftChild = new AVLNode<int>(8);
    AVLNode<int> * rightChild = new AVLNode<int>(15);
    AVLNode<int> node = AVLNode<int>(testValue, leftChild, rightChild);
    // Assert
    ASSERT_EQ(testValue, node.val);
    ASSERT_EQ(leftChild, node.left);
    ASSERT_EQ(rightChild, node.right);
}

//****************** End of Node Tests ********************//

#endif