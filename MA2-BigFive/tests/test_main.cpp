/*
 *  Test suite for Big Five Linked List project
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

#include "LinkedList.h"
#include "ListNode.h"

#include <sstream>      // stringstream stream buffer

using namespace testing;

//**************** Start of ListNode Tests ********************//
TEST(StarterListNode, SetAndGetValue)
{
    // Assemble
    ListNode<int> node;
    int testValue = 13;
    node.setValue(testValue);
    // Assert
    ASSERT_EQ(testValue, node.getValue());
}

TEST(StarterListNode, CopyConstructor)
{
    // Assemble
    ListNode<int> nodeA;
    int testValue = 13;
    nodeA.setValue(testValue);
    // Act
    ListNode<int> nodeB(nodeA);    // Invokes copy constructor
    // Assert
    ASSERT_EQ(nodeA.getValue(), nodeB.getValue());
}

TEST(StarterListNode, CopyOperator)
{
    // Assemble
    ListNode<int> nodeA;
    int testValue = 13;
    nodeA.setValue(testValue);
    ListNode<int> nodeB;
    // Act
    nodeB = nodeA;    // Invokes copy operator
    // Assert
    ASSERT_EQ(nodeA.getValue(), nodeB.getValue());
}
//****************** End of ListNode Tests ********************//


//****************** Start of LinkedList Tests ********************//
TEST(StarterLinkedList, IsEmpty)
{
    // Assemble
    LinkedList<int> numbers{};
    // Assert
    ASSERT_EQ(true, numbers.isEmpty());
}

TEST(StarterLinkedList, IsNotEmpty)
{
    // Assemble
    LinkedList<int> numbers{};
    numbers.addElement(50);
    // Assert
    ASSERT_EQ(false, numbers.isEmpty());
}

TEST(StarterLinkedList, GetElementAt)
{
    // Assemble
    LinkedList<int> numbers{};
    vector<int> vals = {2, 5, 7, 3, 6};
    // Act
    for (auto val : vals)
        { numbers.addElement(val); }
    // Assert
    ASSERT_EQ(7, numbers.getElementAt(2));
}

TEST(StarterLinkedList, SetElementAt)
{
    // Assemble
    LinkedList<int> numbers{};
    int setVal = 10;
    int setLocation = 4;
    vector<int> vals = {2, 5, 7, 3, 6};
    for (auto val : vals)
        { numbers.addElement(val); }
    // Act
    numbers.setElementAt(setVal, setLocation);
    // Assert
    ASSERT_EQ(setVal, numbers.getElementAt(setLocation));
}

TEST(StarterLinkedList, AddElementAtFront)
{
    // Assemble
    LinkedList<int> numbers{};
    int setVal = 10;
    int setLocation = 0;
    vector<int> vals = {2, 5, 7, 3, 6};
    for (auto val : vals)
        { numbers.addElement(val); }
    // Act
    numbers.setElementAt(setVal,setLocation);
    // Assert
    ASSERT_EQ(setVal, numbers.getElementAt(setLocation));
}

TEST(StarterLinkedList, AddElementAtEnd)
{
    // Assemble
    LinkedList<int> numbers{};
    int setVal = 10;
    vector<int> vals = {2, 5, 7, 3, 6};
    int setLocation = (int)vals.size();      // Inserts at tail of LL
    for (auto val : vals)
        { numbers.addElement(val); }
    // Act
    numbers.addElementAt(setVal, setLocation);
    // Assert
    ASSERT_EQ(setVal, numbers.getElementAt(setLocation));
}

TEST(StarterLinkedList, AddElementAtMiddle)
{
    // Assemble
    LinkedList<int> numbers{};
    int setVal = 10;
    vector<int> vals = {2, 5, 7, 3, 6};
    int setLocation = (int)vals.size() / 2; // Inserts in middle of LL
    for (auto val : vals)                   // Add all vals to list as nodes
        { numbers.addElement(val); }
    // Act
    numbers.addElementAt(setVal, setLocation);
    // Assert
    ASSERT_EQ(setVal, numbers.getElementAt(setLocation));
}

TEST(StarterLinkedList, GetElementAtExceptionOut_Of_RangeUnderZero)
{
    LinkedList<int> numbers{};
    ASSERT_THROW(numbers.getElementAt(-1), out_of_range);
}
TEST(StarterLinkedList, GetElementAtExceptionOut_Of_RangeTooHigh)
{
    LinkedList<int> numbers{};
    ASSERT_THROW(numbers.getElementAt(2), out_of_range);
}

TEST(StarterLinkedList, RemoveElementAtExceptionOut_Of_RangeUnderZero)
{
    LinkedList<int> numbers{};
    ASSERT_THROW(numbers.removeElementAt(-1), out_of_range);
}

TEST(StarterLinkedList, RemoveElementAtExceptionOut_Of_RangeTooHigh)
{
    LinkedList<int> numbers{};
    vector<int> vals = {2, 5, 7, 3, 6};
    //int remLocation = (int)vals.size() / 2; // Inserts in middle of LL
    for (auto val : vals)                   // Add all vals to list as nodes
        { numbers.addElement(val); }
    ASSERT_THROW(numbers.removeElementAt(10), out_of_range);
}

TEST(StarterLinkedList, RemoveElementAtMiddle)
{
    LinkedList<int> numbers{};
    vector<int> vals = {2, 5, 7, 3, 6};
    int remLocation = (int)vals.size() / 2; // Inserts in middle of LL
    for (auto val : vals)                   // Add all vals to list as nodes
        { numbers.addElement(val); }
    numbers.removeElementAt(remLocation);   // Removing from middle of list
    ASSERT_EQ(4, numbers.getSize());
    ASSERT_EQ(3, numbers.getElementAt(remLocation));
    numbers.removeElementAt(0);         // Removing from head of list
    ASSERT_EQ(3, numbers.getSize());
    ASSERT_EQ(5, numbers.getElementAt(0));
    numbers.removeElementAt(2);         // Removing from current tail of list
    ASSERT_EQ(2, numbers.getSize());
    numbers.removeElementAt(0);         // Removing to make size 1
    ASSERT_EQ(1, numbers.getSize());
    numbers.removeElementAt(0);         // Removing to make size 0
    ASSERT_EQ(0, numbers.getSize());
}

TEST(StarterLinkedList, getElementAt)
{
    // Assemble
    LinkedList<int> numbers{};
    int getVal = 7; 
    vector<int> vals = {2, 5, 7, 3, 6};
    int getLocation = 2;                // Gets value of node at index 2 (val=7)
    for (auto val : vals)               // Add all vals to list as nodes
        { numbers.addElement(val); }
    // Act
    int gotVal = numbers.getElementAt(getLocation);
    // Assert
    ASSERT_EQ(getVal, gotVal);
}

TEST(StarterLinkedList, BasicInOrderStorage)
{
    // Assemble
    LinkedList<int> numbers{};
    vector<int> vals = {2, 5, 7, 3, 6};
    // Act
    for (auto val : vals)
        { numbers.addElement(val); }
    vector<int> result;
    for (int i = 0; i < numbers.getSize(); i++)
        { result.push_back(numbers.getElementAt(i)); }
    // Assert
    ASSERT_THAT(result, ElementsAreArray(vals));
}
//****************** End of LinkedList tests **************************//


//********* Start of Microassignment LinkedList tests *****************//
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
    ASSERT_THAT(copyVals, ElementsAreArray(srcVals));
}




//********* End of Microassignment LinkedList tests *******************//



// Main only sets up the Google gtest system and runs the tests
// Any Functions in this file called "TEST" will be run
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

    // Notes
    //ASSERT_EQ(true, true);
    //ASSERT_THAT(result, ElementsAre(2,5,7,3,6));
    //ASSERT_THAT(result, ElementsAreArray(vals));
    // ASSERT_THROW(statement, exception_type);
    // ASSERT_ANY_THROW(statement);
    // ASSERT_NO_THROW(statement);
