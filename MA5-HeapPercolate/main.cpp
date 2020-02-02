	//***************************************************************************//
	//**
	//**  Simple Heap implementation
	//**    Copyright 2016 - Aaron S. Crandall
	//**
	//**
	//**
	//***************************************************************************//
	
#include <iostream>
#include <string.h>
#include "Heap.h"

/**
 *  Run a series of tests to evaluate the heap object
 */
void heapTests()
{
	Heap<int> myHeap;
	myHeap.push(890);
    myHeap.push(567);
	myHeap.push(456);
	myHeap.push(921);
	myHeap.push(678);
	myHeap.push(123);
	myHeap.push(234);
	myHeap.push(345);
	myHeap.push(750);

/*
	// This should build a heap that looks like this:
	//                    123 
	//                   /   \
	//                345     234 
	//                / \     / \
	//              678 890 567 456 
	//              / \
	//            921 750
*/
	
	
	std::cout << " [x] Current elements in the heap (should be low->high order): " << std::endl;
	myHeap.print_array();

	std::cout << " [x] Tree-ish form of the heap elements: " << std::endl;
	myHeap.print_pretty();
	std::cout << std::endl;

	// Testing the push & percolateUp behavior
	std::cout << " ***************** Insert testing ***********************" << std::endl;
	std::cout << " [X] Current heap order test after push / percolateUp: " << std::endl;
	std::cout << "  [x] Heap should be:   123 345 234 678 890 567 456 921 750" << std::endl;
	std::cout << "  [t] Heap actually is: ";
	std::cout << myHeap.to_string();

	if( myHeap.to_string() == "123 345 234 678 890 567 456 921 750 " )
	{
		std::cout << "- PASS " << std::endl;
	}else{
		std::cout << "- FAIL " << std::endl;
	}

	myHeap.push(101);
	std::cout << "  [x] Heap should be:   101 123 234 678 345 567 456 921 750 890 " << std::endl;
	std::cout << "  [t] Heap actually is: ";
	std::cout << myHeap.to_string();

	if( myHeap.to_string() == "101 123 234 678 345 567 456 921 750 890 " )
	{
		std::cout << "- PASS " << std::endl;
	}else{
		std::cout << "- FAIL " << std::endl;
	}
	std::cout << std::endl;


	// Testing the remove & percolateDown behavior
	std::cout << " ***************** Remove/Delete testing ****************" << std::endl;
	std::cout << " [X] Beginning to remove elements from the heap: " << std::endl;
	std::cout << "  [*] Once percolateDown is done, these go low->high." << std::endl;

	std::string acc = "";
	std::cout << "  [x] Order should be:   101 123 234 345 456 567 678 750 890 921" << std::endl;;
	std::cout << "  [t] Order actually is: ";
	while (myHeap.empty() == false)
	{
		int top = myHeap.top();
		myHeap.pop();
		std::cout << top << " ";
		acc += std::to_string(top) + " ";
	}

	if( acc == "101 123 234 345 456 567 678 750 890 921 " )
	{
		std::cout << "- PASS " << std::endl;
	}else{
		std::cout << "- FAIL " << std::endl;
	}

	std::cout << std::endl;


	std::cout << " [x] Done. " << std::endl;
}


/**
 *  Main function for our heap and heap testing
 */
int main(int argc, char* argv[])
{
	
	if( argc > 1 && !strcmp(argv[1], "--test" ) )
	{
		std::cout << " [x] Running in test mode. " << std::endl;
		heapTests();
		std::cout << " [x] Program complete. " << std::endl;
	}
	else
	{
		std::cout << " [x] Running in normal mode. " << std::endl;
		std::cout << "  [!] Nothing to do in normal mode, so here's a helper: " << std::endl << std::endl;

std::cout << ""
""
"                                  ___.___               \n"
"                                    (_]===*             \n"
"                                    o 0                 \n"
"                                                        \n"
"                 _,-}}-._                               \n"
"                /\\   }  /\\                            \n"
"              _|(0\\\\_ _/0)                  ___|_     \n"
"             _|/  (__''__)                 |#####|      \n"
"           _|\\/    WVVVVW                  |#####|     \n"
"          \\ _\\     \\MMMM/_             .-----.###|   \n"
"        _|\\_\\     _ '---; \\_           |#####|###|   \n"
"   /\\   \\ _\\/      \\_   /   \\          |#C++#|###| \n"
"  / (    _\\/     \\   \\  |'VVV     P    |#####|###|   \n"
" (  '-,._\\_.(      'VVV /      (_/|\\_) |#####|###|    \n"
"  \\         /   _) /   _)     (_/_ _\\_)|#####|###|    \n" 
"   '....--''\\__vvv)\\__vvv)_____|_| |_|_|#####|###|____ldb\n";



		std::cout << std::endl << " You should probably run 'make test' to test your program. " << std::endl;
	}
	
}
