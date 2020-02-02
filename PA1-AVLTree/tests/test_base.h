/*
 *  Test suite for BST Level Order project
 *
 *  All tests in this file should start with Base*
 * 
 */

#ifndef __BASE_TESTS_H
#define __BASE_TESTS_H

#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

//#include "../AVLTree.h"
//#include "../AVLNode.h"

using namespace testing;

//********* Start of AVL tests *****************//
// ** Tests for basic BST internal details implemented ** //
// ** No rotations for these first set of tests ** //

TEST(BaseAVL, EmptyWhenEmpty)
{
    AVLTree<int> tree;                // Assemble
    ASSERT_EQ(true, tree.empty());  // Assert
}

TEST(BaseAVL, SizeWhenEmpty)
{
    AVLTree<int> tree;                // Assemble
    ASSERT_EQ(0, tree.size());  // Assert
}

TEST(BaseAVL, NoRotateInsert)
{
    AVLNode<int>::nodeCount = 0;
    std::stringstream ss;       // Buffer to store stream
    AVLTree<int> tree;
    std::vector<int> vals{10, 15, 6, 3, 8, 16, 13};
    for( auto val : vals ){
        tree.add(val);
    }
    std::string preOrderResult = "10 6 3 8 15 13 16";
    tree.printPreOrder(ss);
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, EmptyAfterAdd)
{
    AVLTree<int> tree;              // Assemble
    tree.add(17);                   // Act
    ASSERT_EQ(false, tree.empty());  // Assert
}

TEST(BaseAVL, ClearEmptyTree)
{
    AVLTree<int> tree;              // Assemble
    tree.clear();                   // Act - Should delete all nodes
    ASSERT_EQ(true, tree.empty());  // Assert
}

TEST(BaseAVL, ClearAfterAdd)
{
    AVLTree<int> tree;              // Assemble
    std::vector<int> vals{10, 15, 6, 3, 8, 16, 13, 7, 14};
    for( auto val : vals )
        tree.add(val);
    tree.clear();
    ASSERT_EQ(true, tree.empty());  // Assert
}

TEST(BaseAVL, HeightsNoRotations)
{
    AVLTree<int> tree;              // Assemble
    ASSERT_EQ(-1, tree.height());   // Empty tree is height -1 (nullptr root)
    std::vector<int>    vals{10, 4, 16, 20, 8, 2, 6};
    std::vector<int> heights{ 0, 1,  1,  2, 2, 2, 3};
    for( int i = 0; i < (int)vals.size(); i++ ) {
        tree.add( vals[i] );
        ASSERT_EQ(heights[i], tree.height());
    }

}

TEST(BaseAVL, ContainsNoRotations)
{
    AVLTree<int> tree;
    std::vector<int> vals{10, 15, 6, 3, 8, 18, 12, 7, 14, 16, 20, 24};
    for( auto val : vals )
        tree.add(val);
    ASSERT_EQ(true, tree.contains(10));         // Testing root
    ASSERT_EQ(false, tree.contains(9));         // Testing not there (right)
    ASSERT_EQ(false, tree.contains(1));         // Testing not there (left)

    for( auto val : vals )
        ASSERT_EQ(true, tree.contains(val));    // Test whole tree
}

TEST(BaseAVL, findMINnoRotations)
{
    AVLTree<int> tree;
    std::vector<int> vals{10, 15, 6, 3, 8, 18, 12, 7, 14, 16, 20, 24};
    int minVal = 3;
    for( auto val : vals )
        tree.add(val);
    ASSERT_EQ(minVal, tree.findMin());
}

TEST(BaseAVL, findMAXnoRotations)
{
    AVLTree<int> tree;
    std::vector<int> vals{10, 15, 6, 3, 8, 18, 12, 7, 14, 16, 20, 24};
    int maxVal = 24;
    for( auto val : vals )
        tree.add(val);
    ASSERT_EQ(maxVal, tree.findMax());
}

TEST(BaseAVL, sizeAfterAddNoRotations)
{
    AVLTree<int> tree;
    std::vector<int> vals{10, 15, 6, 3, 8, 18, 12, 7, 14, 16, 20, 24};
    for( auto val : vals )
        tree.add(val);
    ASSERT_EQ(vals.size(), tree.size());
}

TEST(BaseAVL, Remove_On_Empty_Tree)
{
    AVLTree<int> tree;
    tree.remove(10);
    ASSERT_EQ(true, tree.empty());
}

TEST(BaseAVL, Remove_On_Root_Only_Tree)
{
    AVLTree<int> tree;
    tree.add(10);
    tree.remove(10);
    ASSERT_EQ(true, tree.empty());
    ASSERT_EQ(0, tree.size());
    ASSERT_EQ(-1, tree.height());
}

TEST(BaseAVL, Remove_On_Leaf)
{
    AVLTree<int> tree;
    tree.add(10);
    tree.add(20);
    tree.remove(20);
    ASSERT_EQ(false, tree.empty());
    ASSERT_EQ(1, tree.size());
    ASSERT_EQ(0, tree.height());
}

TEST(BaseAVL, Remove_Inner_Node_No_Rotates)
{
    AVLTree<int> tree;
    std::stringstream ss;       // Buffer to store stream
    std::vector<int> vals{10, 15, 6, 3, 8, 18, 12, 7, 14, 16, 20, 11};
    for( auto val : vals )
        tree.add(val);
    tree.remove(15);
    std::string preOrderResult = "10 6 3 8 7 16 12 11 14 18 20";
    tree.printPreOrder(ss);
    std::cout << " After remove(15), should be: " << preOrderResult << std::endl;
    std::cout << "                   result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

// *********************** Tests with Rotations ******************* //
TEST(BaseAVL, Single_Right_Rotate)
{
    AVLTree<int> tree;
    std::stringstream ss;       // Buffer to store stream
    std::vector<int> vals{10, 8, 5};
    for( auto val : vals )
        tree.add(val);                      // At add(5) it should right rotate
    std::string preOrderResult = "8 5 10";
    tree.printPreOrder(ss);
    std::cout << " After right rotate, should be: " << preOrderResult << std::endl;
    std::cout << "                     result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Single_Right_Rotate_With_Deeper_Tree)
{
    AVLTree<int> tree;
    std::stringstream ss;
    std::vector<int> vals{20, 10, 30, 6, 15, 25, 35, 13, 8, 4, 1};
    for( auto val : vals )
        tree.add(val);                      // At add(1) it should right rotate over root
    std::string preOrderResult = "10 6 4 1 8 20 15 13 30 25 35";
    tree.printPreOrder(ss);
    std::cout << " After right rotate, should be: " << preOrderResult << std::endl;
    std::cout << "                     result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Single_Left_Rotate)
{
    AVLTree<int> tree;
    std::stringstream ss;
    std::vector<int> vals{75, 80, 90};
    for( auto val : vals )
        tree.add(val);                      // At add(90) it should left rotate over root
    std::string preOrderResult = "80 75 90";
    tree.printPreOrder(ss);
    std::cout << " After left rotate, should be: " << preOrderResult << std::endl;
    std::cout << "                    result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Single_Left_Rotate_With_Deeper_Tree)
{
    AVLTree<int> tree;
    std::stringstream ss;
    std::vector<int> vals{20, 10, 25, 8, 15, 22, 30, 13, 28, 35, 40};
    for( auto val : vals )
        tree.add(val);                      // At add(40) it should left rotate over 25
    std::string preOrderResult = "20 10 8 15 13 30 25 22 28 35 40";
    tree.printPreOrder(ss);
    std::cout << " After left rotate, should be: " << preOrderResult << std::endl;
    std::cout << "                    result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Single_Right_Rotate_Height_Check)
{
    AVLTree<int> tree;
    std::stringstream ss;
    int expected_final_height = 3;
    std::vector<int> vals{20, 10, 30, 6, 15, 25, 35, 13, 8, 4, 1};
    for( auto val : vals )
        tree.add(val);                      // At add(1) it should right rotate over root
    ASSERT_EQ(expected_final_height, tree.height());
}

TEST(BaseAVL, Single_Left_Rotate_Height_Check)
{
    AVLTree<int> tree;
    std::stringstream ss;
    int expected_final_height = 3;
    std::vector<int> vals{20, 10, 25, 8, 15, 22, 30, 13, 28, 35, 40};
    for( auto val : vals )
        tree.add(val);                      // At add(40) it should left rotate over 25
    ASSERT_EQ(expected_final_height, tree.height());
}

TEST(BaseAVL, Double_Left_Right_Rotate)
{
    AVLTree<int> tree;
    std::stringstream ss;
    std::vector<int> vals{10, 5, 8};
    for( auto val : vals )
        tree.add(val);                      // At add(8) it should double left right rotate at 10 
    std::string preOrderResult = "8 5 10";
    tree.printPreOrder(ss);
    std::cout << " After left right double rotate, should be: " << preOrderResult << std::endl;
    std::cout << "                                 result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Double_Right_Left_Rotate)
{
    AVLTree<int> tree;
    std::stringstream ss;
    std::vector<int> vals{5, 10, 8};
    for( auto val : vals )
        tree.add(val);                      // At add(8) it should double left right rotate at 5
    std::string preOrderResult = "8 5 10";
    tree.printPreOrder(ss);
    std::cout << " After right left double rotate, should be: " << preOrderResult << std::endl;
    std::cout << "                                 result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Textbook_Tree_Example)
{
    std::cout << "Course Textbook AVL tree example from pages 148-153" << std::endl;
    AVLTree<int> tree;
    std::stringstream ss;
    std::vector<int> vals{3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    for( auto val : vals )
        tree.add(val);                      // At add(8) it should double left right rotate at 5
    std::string preOrderResult = "7 4 2 1 3 6 5 13 11 9 8 10 12 15 14 16";
    tree.printPreOrder(ss);
    std::cout << " After all rotations, tree pre order" << std::endl;
    std::cout << "   should be: " << preOrderResult << std::endl;
    std::cout << "   result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

TEST(BaseAVL, Remove_Inner_Node_Left_Right_Rotate)
{
    AVLTree<int> tree;
    std::stringstream ss;       // Buffer to store stream
    std::vector<int> vals{10, 15, 6, 3, 8, 18, 12, 7, 14, 16, 11, 5, 2, 4, 13};
    for( auto val : vals )
        tree.add(val);
    tree.remove(15);
    std::string preOrderResult = "10 6 3 2 5 4 8 7 14 12 11 13 16 18";
    tree.printPreOrder(ss);
    std::cout << " After remove(15), should be: " << preOrderResult << std::endl;
    std::cout << "                   result is: " << ss.str() << std::endl;
    ASSERT_THAT(ss.str(), HasSubstr(preOrderResult));
}

// ************************** HUGE Test ************************ //
TEST(StressAVL, Random_Tree_Test)
{
    AVLTree<int> tree;
    std::vector<int> nodes;
    uint64_t max_node_count = (uint64_t)pow(2, 16);       // 65536
    std::cout << "  Building tree up to: " << max_node_count << " nodes big with random ints" << std::endl;
    while(nodes.size() < max_node_count)
    {
        int new_val = rand() % INT_MAX;
        tree.add(new_val);
        nodes.push_back(new_val);
        //float percent_complete = 100 * (float)nodes.size() / (float)max_node_count;
        //std::cout << "\r  Tree size: " << nodes.size() << "  | Height: " << tree.height();
        //std::cout << " |  Percent complete: " << percent_complete << "%        ";

        if(nodes.size() % 5 == 0) {
            uint64_t selected_index = rand() % nodes.size();
            int selected_val = nodes[selected_index];
            tree.remove( selected_val );
            nodes.erase( nodes.begin() + selected_index );
            // After removing a random one, add one more to push forward
            new_val = rand() % INT_MAX;
            tree.add(new_val);
            nodes.push_back(new_val);
        }
    }
    //std::cout << std::endl;
}

TEST(StressAVL, In_Order_Data_Tree_Test)
{
    AVLTree<int> tree;
    uint64_t max_node_count = (uint64_t)pow(2, 16);       // 65536
    std::cout << "  Building tree with " << max_node_count << " nodes inserted in order 1..n" << std::endl;

    for(uint64_t i = 0; i <= max_node_count; i++) {
        //float percent_complete = 100 * (float)i / (float)max_node_count;
        //std::cout << "\r  Tree size: " << i << "  | Tree height: " << tree.height();
        //std::cout << " |  Percent complete: " << percent_complete << "%        ";

        tree.add((int)i);
    }
    //std::cout << std::endl;
}

// ********************* Frakin HUGE Test ************************ //
TEST(HugeAVL, Huge_Random_Tree_Test)
{
    std::time_t start_time = std::time(nullptr);    // Get starting time
    std::time_t curr_time = start_time;
    AVLTree<int> tree;
    std::vector<int> nodes;
    uint64_t max_node_count = (uint64_t)pow(2, 22);       // 4194304
    std::cout << "  Building tree up to: " << max_node_count << " nodes big" << std::endl;
    while(nodes.size() < max_node_count)
    {
        int new_val = rand() % INT_MAX;
        tree.add(new_val);
        nodes.push_back(new_val);

        curr_time = std::time(nullptr);             // Get current time
        float percent_complete = 100 * (float)nodes.size() / (float)max_node_count;
        std::cout << "\r  Tree size: " << nodes.size() << "  | Height: " << tree.height();
        std::cout << " | Done: " << percent_complete << "% ";
        std::cout << " | Runtime: " << (curr_time - start_time) << " sec    ";

        if(nodes.size() % 5 == 0) {
            uint64_t selected_index = rand() % nodes.size();
            int selected_val = nodes[selected_index];
            tree.remove( selected_val );
            nodes.erase( nodes.begin() + selected_index );
            // After removing a random one, add one more to push forward
            new_val = rand() % INT_MAX;
            tree.add(new_val);
            nodes.push_back(new_val);
        }
    }
    std::cout << std::endl;
}

#endif
