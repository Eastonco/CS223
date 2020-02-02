/*
 *  main.cpp - Main with tests for LinkedList class
 *
 *  Aaron Crandall (acrandal@wsu.edu)
 *  Adam Carter
 *   Copyright 2017 - Instructional use only
 *
 *  Main designed to test a Linked List class for the C++11 big five
 *
 */

#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include "LinkedList.h"
#include "ListNode.h"
#include <string.h>

using namespace std;


/*
 *  Routine to test out the BigFive of your LinkedList implementation
 */
void linkedListTest()
{
	// Base LinkedList initialization test
	cout << " [x] Test #1: Basic Linked List behavior" << endl;
	LinkedList<int> numbers{};
	for (int i = 1; i < 11; i++)
	{
		numbers.addElement(i);
	}
	cout << "   [x] Result:" << endl;
	cout << "   [x]  Expected:\t1 2 3 4 5 6 7 8 9 10" << endl;
	cout << "   [x]  Actual:\t\t";
	for (int i = 0; i < numbers.getSize(); i++)
	{
		cout << numbers.getElementAt(i) << " ";
	}
	cout << endl << endl;

	//**************************************************************************//
	// Use the copy constructor
	cout << " [x] Test #2: Copy constructor behavior" << endl;
	LinkedList<int> copy1{ numbers };
	cout << "   [x] Result:" << endl;
	cout << "   [x]  Expected:\t1 2 3 4 5 6 7 8 9 10" << endl;
	cout << "   [x]  Actual:\t\t";
	for (int i = 0; i < copy1.getSize(); i++)
	{
		cout << copy1.getElementAt(i) << " ";
	}
	cout << endl << endl;

	//**************************************************************************//
	// Use move constructor
	cout << " [x] Test #3: Move constructor behavior" << endl;
	LinkedList<int> tmp = LinkedList<int>{1, 2, 3, 4, 5};
	//LinkedList<int> moved1{ LinkedList<int>{1, 2, 3, 4, 5} };
	LinkedList<int> moved1 = std::move(tmp);
	cout << "   [x] Result:" << endl;
	cout << "   [x]  Expected:\t1 2 3 4 5" << endl;
	cout << "   [x]  Actual:\t\t";
	for (int i = 0; i < moved1.getSize(); i++)
	{
		cout << moved1.getElementAt(i) << " ";
	}
	cout << endl << endl;

	//**************************************************************************//
	// Use copy *assignment* operator
	cout << " [x] Test #4: Copy *assignment* operator behavior" << endl;
	LinkedList<int> copy2;
	copy2 = moved1;
	cout << "   [x] Result:" << endl;
	cout << "   [x]  Expected:\t1 2 3 4 5" << endl;
	cout << "   [x]  Actual:\t\t";
	for (int i = 0; i < copy2.getSize(); i++)
	{
		cout << copy2.getElementAt(i) << " ";
	}
	cout << endl << endl;

	//**************************************************************************//
	// Use move *assignment* operator
	cout << " [x] Test #5: Move *assignment* constructor behavior" << endl;
	moved1 = LinkedList<int>{ 6, 7, 8, 9, 10 };
	cout << "   [x] Result:" << endl;
	cout << "   [x]  Expected:\t6 7 8 9 10" << endl;
	cout << "   [x]  Actual:\t\t";
	for (int i = 0; i < moved1.getSize(); i++)
	{
		cout << moved1.getElementAt(i) << " ";
	}
	cout << endl << endl;

	//**************************************************************************//
	// Testing a destructor
	cout << " [x] Test #6: Create object, then delete to test destructor" << endl;
	LinkedList<int> *llptr = new LinkedList<int>{ 11, 12, 13, 14, 15 };
	cout << "  [x] Temp list contents:" << endl;
	cout << "   [x] Expected:\t11 12 13 14 15" << endl;
	cout << "   [x] Actual:\t\t";
	for (int i = 0; i < llptr->getSize(); i++)
	{
		cout << llptr->getElementAt(i) << " ";
	}
	cout << endl << endl;

	ListNode<int> *frontptr = llptr->getFront();
	cout << "   [x] RAW list test:\t";
	while( frontptr != nullptr ){
		cout << frontptr->getValue() << " ";
		frontptr = frontptr->getNext();
	}
	cout << endl;
	frontptr = llptr->getFront(); // Reset to front of list

	cout << "  [x] Calling delete/destructor on object" << endl;
	delete llptr;

	cout << "  [x] Del list test:\t" << endl;
	cout << "   [x] Expected:\t0" << endl;     // WHY do we get a zero?
	cout << "   [x] Actual:\t\t";
	while( frontptr != NULL ){
		cout << frontptr->getValue() << " ";
		frontptr = frontptr->getNext();
	}
	cout << endl;

	//**************************************************************************//
  cout << " [x] Now last implicit destructors happen. " << endl;
}


/*
 *  Main function - takes a command line option (--test) for test mode
 *   Otherwise, it just prints a cat
 */
int main(int argc, char *argv[])
{
  // Note: If you call this program like this: ./bigFiveList --test
  //  It will call the test function
	if( argc > 1 && !strcmp(argv[1], "--test" ) )
	{
		cout << " [x] Running in test mode. " << endl << endl;
		linkedListTest();
		cout << " [x] Program complete. " << endl;
  }else{
		cout << " [x] Running in normal mode. " << endl;
		cout << "  [!] Nothing to do in normal mode so here's a cat: " << endl;
		cout << "         /\\_/\\\n    ____/ o o \\\n  /~____  =ø= /\n (______)__m_m)\n" << endl;
		cout << endl << " You should probably run 'make test' to test your program. " << endl;
	}
}
