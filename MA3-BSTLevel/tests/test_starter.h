/*
 *  Test suite for BST Level Order project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef STARTER_TESTS_H
#define STARTER_TESTS_H

#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library
#include <vector>

using namespace testing;    // gtest lives in the testing:: namespace

//**************** Start of Node Tests ********************//
TEST(StarterNode, BasicInitializer)
{
    // Assemble
    int testValue = 13;
    Node<int> node = Node<int>(testValue);
    // Assert
    ASSERT_EQ(testValue, node.value);
    ASSERT_EQ(nullptr, node.left);
    ASSERT_EQ(nullptr, node.right);
}

TEST(StarterNode, InitializeChildren)
{
    // Assemble
    int testValue = 13;
    Node<int> * leftChild = new Node<int>(8);
    Node<int> * rightChild = new Node<int>(15);
    Node<int> node = Node<int>(testValue, leftChild, rightChild);
    // Assert
    ASSERT_EQ(testValue, node.value);
    ASSERT_EQ(leftChild, node.left);
    ASSERT_EQ(rightChild, node.right);
}

//****************** End of Node Tests ********************//


//****************** Start of BST Tests ********************//
TEST(StarterBST, IsEmpty)
{
    BST<int> tree{};                // Assemble
    ASSERT_EQ(true, tree.empty());  // Assert
}

TEST(StarterBST, AddContains)
{
    BST<int> tree{};                // Assemble
    tree.add(7);
    ASSERT_EQ(true, tree.contains(7));
}

TEST(StarterBST, MultipleAddContains)
{
    BST<int> tree{};                // Assemble
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35, 2, 7, 12, 17, 23, 28, 32, 38, -1, -4, 0};
    for (auto val : vals)
        { tree.add(val); }
    for (auto val : vals)
    {
        ASSERT_EQ(true, tree.contains(val));
    }
}

TEST(StarterBST, NotContains)
{
    BST<int> tree{};        // Assemble
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35, 2, 7, 12, 17, 23, 28, 32, 38, -1, -4, 0};
    for (auto val : vals)
        { tree.add(val); }  // Act
    for (auto val : vals)
    {
        ASSERT_EQ(false, tree.contains(val+100));   // Assert
    }
}

TEST(StarterBST, DupAddContains)
{
    BST<int> tree{};                // Assemble
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35, 2, 7, 12, 17, 23, 28, 32, 38, -1, -4, 0, 20, 10, 30, 5, 15, 25, 35, 2, 7, 12, 17, 23, 28, 32, 38, -1, -4, 0};
    for (auto val : vals)
        { tree.add(val); }
    for (auto val : vals)
    {
        ASSERT_EQ(true, tree.contains(val));
    }
}

TEST(StarterBST, Size)
{
    BST<int> tree{};
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35, 2, 7, 12, 17, 23, 28, 32, 38, -1, -4, 0};
    for (auto val : vals)
        { tree.add(val); }
    ASSERT_EQ(vals.size(), tree.size());
}

TEST(StarterBST, Height)
{
    BST<int> tree{};
    vector<int> vals = {20, 10, 5, 3, -1, 30, 35, 33};
    ASSERT_EQ(-1, tree.height());    // Test empty tree
    tree.add( vals[0] );
    ASSERT_EQ(0, tree.height());    // Single node tree
    tree.add( vals[1] );
    ASSERT_EQ(1, tree.height());    // Two node tree
    tree.add( vals[2] );
    ASSERT_EQ(2, tree.height());    // Three node degraded (unbalanced) tree
    tree.add( vals[3] );
    ASSERT_EQ(3, tree.height());    // Four node degraded (unbalanced) tree
    tree.add( vals[4] );
    ASSERT_EQ(4, tree.height());    // Five node degraded (unbalanced) tree
    tree.add( vals[5] );
    tree.add( vals[6] );
    tree.add( vals[7] );
    ASSERT_EQ(4, tree.height());    // More balanced tree
}

TEST(StarterBST, MakeEmpty)
{
    TestableBST<int> tree{};
    vector<int> vals = {20, 10, 30, 5, 15, 25, 35, 2, 7, 12, 17, 23, 28, 32, 38, -1, -4, 0};
    for (auto val : vals)
        { tree.add(val); }
    ASSERT_EQ(vals.size(), tree.size());    // Validating tree status
    ASSERT_EQ(false, tree.empty());         // Tree not empty
    ASSERT_EQ(5, tree.height());            // This tree from vals is height = 6
    ASSERT_NE(nullptr, tree.getRoot());        // Should not be an empty root

    tree.makeEmpty();                       // Act - should empty the tree

    ASSERT_EQ(true, tree.empty());          // Should be true
    ASSERT_EQ(0, tree.size());              // Should be zero
    ASSERT_EQ(-1, tree.height());            // Height is zero now
    ASSERT_EQ(nullptr, tree.getRoot());        // Root should be nullptr
        // Should also check to ensure all nodes were freed, not just forgotten
}

TEST(StarterBST, fuzzing)
{
    srand ((unsigned int) time(NULL));  // Initialize random seed
    BST<int> tree{};
    vector<int> vals;

    int totalVals = 20000;                   // Generate 20k values

    for( int i = 0; i < totalVals; ++i )
    {
        int newVal = (rand() % 1000000) - 500000; // Val between -500k and 500k
        vals.push_back(newVal);
        tree.add(newVal);
    }

    for (auto val : vals) {
        ASSERT_EQ(true, tree.contains(val));   // Assert
    }
}

TEST(StarterBST, InOrderTraversal) {
    std::stringstream ss;   // Buffer to store stream
    BST<int> * bst = new BST<int>({4,2,1,3,6,5,7,9,8});
    cout << "\tShould produce:\t1 2 3 4 5 6 7 8 9 " << endl;
    cout << "\tInorder: \t";
    bst->printInOrder(ss);  // Results are stored in ss
    cout << ss.str();
    cout << endl;
    ASSERT_THAT(ss.str(), HasSubstr("1 2 3 4 5 6 7 8 9"));
}

TEST(StarterBST, PostOrderTraversal) {
    std::stringstream ss;       // Buffer to store stream
    BST<int> * bst = new BST<int>({4,2,1,3,6,5,7,9,8});
    cout << "\tShould produce:\t1 3 2 5 8 9 7 6 4 " << endl;
    cout << "\tPostorder: \t";
    bst->printPostOrder(ss);    // Results are stored in ss
    cout << ss.str();
    cout << endl;
    ASSERT_THAT(ss.str(), HasSubstr("1 3 2 5 8 9 7 6 4"));
}

TEST(StarterBST, PreOrderTraversal) {
    std::stringstream ss;       // Buffer to store stream
    BST<int> * bst = new BST<int>({4,2,1,3,6,5,7,9,8});
    cout << "\tShould produce:\t4 2 1 3 6 5 7 9 8 " << endl;
    cout << "\tPreorder: \t";
    bst->printPreOrder(ss);    // Results are stored in ss
    cout << ss.str();
    cout << endl;
    ASSERT_THAT(ss.str(), HasSubstr("4 2 1 3 6 5 7 9 8"));
}

//****************** End of BST tests **************************//

#endif
