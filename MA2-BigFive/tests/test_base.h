/*
 *  Test suite for Big Five Linked List project
 *
 *  All tests in this file should start with Base*
 * 
 */

#ifndef BASE_TESTS_H
#define BASE_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

using namespace testing;

//********* Start of Microassignment LinkedList tests *****************//

//*** Start of Copy Constructor test ***
TEST(BaseLinkedListBigFive, CopyConstructor)
{
    // Assemble
    LinkedList<int> firstList{};
    vector<int> srcVals = {1, 2, 3, 4, 5};
    for (auto val : srcVals) {
        firstList.addElement(val);
    }
    // Act
    LinkedList<int> listCopy{ firstList };      // Executes Copy Constructor
    vector<int> copyVals = {};
    for (int i = 0; i < listCopy.getSize(); i++)
    {
        copyVals.push_back(listCopy.getElementAt(i));
    }
    // Assert
    ASSERT_NE(firstList.getFront(), listCopy.getFront());
    ASSERT_THAT(copyVals, ElementsAreArray(srcVals));
}
//*** End of Copy Constructor tests ***

//*** Start of Move Constructor tests ***
TEST(BaseLinkedListBigFive, MoveConstructor)
{
    LinkedList<int> firstList{};
    vector<int> srcVals = {1, 2, 3, 4, 5};
    for (auto val : srcVals)
        { firstList.addElement(val); }
    // Act
    ListNode<int>* srcFront = firstList.getFront();     // Save pointer for testing
    LinkedList<int> movedList = std::move(firstList);   // Move constructor

    vector<int> movedListVals = {};
    for (int i = 0; i < movedList.getSize(); i++)
    {
        movedListVals.push_back(movedList.getElementAt(i));
    }
    // Assert
    ASSERT_EQ(srcFront, movedList.getFront());              // Should be same Nodes
    ASSERT_THAT(movedListVals, ElementsAreArray(srcVals));  // Elements all in order
    ASSERT_EQ(srcVals.size(), movedListVals.size());        // No elements lost
    ASSERT_EQ(srcVals.size(), movedList.getSize());         // List knows size properly
    ASSERT_EQ(nullptr, firstList.getFront());               // Old list destroyed
    ASSERT_EQ(0, firstList.getSize());                      // Old list empty
}
//*** End of Move Constructor tests ***

//*** Start of Initializer List Constructor tests ***
TEST(BaseLinkedListBigFive, InitializerListConstructor)
{
    initializer_list<int> srcInitList = { 1, 2, 3, 4, 5 };      // Assemble
    vector<int> srcVals = {1, 2, 3, 4, 5};
    LinkedList<int> newList = LinkedList<int>{ srcInitList };   // Act
    vector<int> newVals;
    for (int i = 0; i < newList.getSize(); i++) {
        newVals.push_back(newList.getElementAt(i));
    }
    // Assert
    ASSERT_EQ( srcInitList.size(), newList.getSize() );         // Size correct?
    ASSERT_THAT(srcVals, ElementsAreArray(newVals));            // Content correct?
}
//*** End of Initializer List Constructor tests ***

//*** Start of Copy *assignment* operator tests ***
TEST(BaseLinkedListBigFive, CopyAssignmentOperator)
{
    LinkedList<int> firstList{}; 
    vector<int> srcVals = {1, 2, 3, 4, 5};
    for (auto val : srcVals)
        { firstList.addElement(val); }      // Fill the first list up
    LinkedList<int> copiedList;             // List to copy into via assignment
    // Act - Run copy assignment operator
    copiedList = firstList;                 // Copy assignment operator executed
    // Assert
    vector<int> copyVals = {};
    for (int i = 0; i < copiedList.getSize(); i++)
        { copyVals.push_back(copiedList.getElementAt(i)); }
    // Assert
    ASSERT_EQ(srcVals.size(), copiedList.getSize());        // Test size correct
    ASSERT_NE(firstList.getFront(), copiedList.getFront()); // Test shallow copy (bad)
    ASSERT_THAT(copyVals, ElementsAreArray(srcVals));       // Test contents
}
//*** End of Copy *assignment* operator tests ***

//*** Start of Move *assignment* operator tests ***
TEST(BaseLinkedListBigFive, MoveAssignmentOperator)
{
    LinkedList<int> movedList{};                // Assemble - create our list
    vector<int> srcVals = {1, 2, 3, 4, 5};
    vector<int> finalVals = {6, 7, 8, 9, 10, 11};
    for (auto val : srcVals)
        { movedList.addElement(val); }          // Fill list with init data
    // Act - execute move assignment operator
    // NOTE: This requires a working initializer_list constructor
    //  The rvalue on the right of the = operator is built with an intializer_list
    movedList = LinkedList<int>{6, 7, 8, 9, 10, 11}; // Move assignment op

    vector<int> movedVals = {};
    for (int i = 0; i < movedList.getSize(); i++)
        { movedVals.push_back(movedList.getElementAt(i)); }
    // Assert
    ASSERT_EQ(finalVals.size(), movedList.getSize());       // Test size correct
    ASSERT_THAT(finalVals, ElementsAreArray(movedVals));    // Test contents
}
//*** End of Move *assignment* operator tests ***

//*** Start of Destructor (~) tests ***
TEST(BaseLinkedListBigFive, DestructorTests)
{
    LinkedList<int> * myList = new LinkedList<int>(); // Assemble - create our list
    myList->debug_on();                      // Turn on extra LinkedList output
    vector<int> srcVals = {1, 2, 3, 4, 5};
    for (auto val : srcVals)
        { myList->addElement(val); }         // Fill list with init data
    // Gather white box data
    ListNode<int> * front = myList->getFront();
    vector< ListNode<int>* > nodes;

    ListNode<int> * curr_node = front;
    while( curr_node != nullptr ) {
        nodes.push_back(curr_node);
        curr_node = curr_node->getNext();
    }

    delete myList;
    for (auto node : nodes) {
        ASSERT_EQ(nullptr, node->getNext());
    } 

}
//*** End of Destructor (~) tests ***


//********* End of Base Microassignment LinkedList tests **************//


#endif
