

#ifndef __TEST_TOOLS_H
#define __TEST_TOOLS_H

#include <vector>
#include <functional>           // Allows passing in functions to functions

#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library

#include "main.h"

using namespace testing;


template<typename SORTORDERTYPE>
void sort_test(std::function<void(std::vector<int>&, SortStats&)> sortFunc, int data_vector_length, int random_seed = -1)
{
    SortStats stats;
    SORTORDERTYPE expected_data(data_vector_length, random_seed);
    std::sort(expected_data.begin(), expected_data.end());

    SORTORDERTYPE sorting_data(data_vector_length, random_seed);
    sortFunc(sorting_data, stats);

    ASSERT_THAT(sorting_data, ElementsAreArray(expected_data));
}


template<typename SORTORDERTYPE>
void stats_test(std::function<void(std::vector<int>&, SortStats&)> sortFunc, int data_vector_length, int random_seed = -1)
{
    SortStats stats;

    SORTORDERTYPE sorting_data(data_vector_length, random_seed);
    sortFunc(sorting_data, stats);

    std::cout << "  Comparisons done: " << stats.compares << endl;

    ASSERT_GE(stats.compares, 1);           // Are there any compares in the stats?
}


template<typename SORTORDERTYPE>
void algorithm_comparison_test( int n = 2000, int seed = -1) {
	SortingStats sortedStats;			     // Create object for our statistics - pre-sorted

	cout << "   [x] Running bubble sort..." << endl;;
	SORTORDERTYPE presorted(n, seed);	  // Create n item vector of pre-sorted data to sort
	instrumentedBubbleSort( presorted, sortedStats.bubblesort );

	cout << "   [x] Running insertion sort: ";
	SORTORDERTYPE presorted2(n, seed);	  
	instrumentedInsertionSort( presorted2, sortedStats.insertionsort );
	( presorted == presorted2 ) ? cout << " - pass " : cout << " - fail "; cout << endl;

	cout << "   [x] Running merge sort:     ";
	SORTORDERTYPE presorted3(n, seed);	  
	instrumentedMergeSort( presorted3, sortedStats.mergesort );
	( presorted == presorted3 ) ? cout << " - pass " : cout << " - fail "; cout << endl;

	cout << "   [x] Running quicksort:      ";
	SORTORDERTYPE presorted4(n, seed);	  
	instrumentedQuickSort( presorted4, sortedStats.quicksort );
	( presorted == presorted4 ) ? cout << " - pass " : cout << " - fail "; cout << endl;

	if( n < 25 ) {  // Only print out if it's a reasonable amount of data to view
		SORTORDERTYPE starting(n, seed);
		cout << "    [d] Start List: "; for( auto val : starting   ) { cout << val << ", "; } cout << endl;
		cout << "    [d] BubbleSort: "; for( auto val : presorted  ) { cout << val << ", "; } cout << endl;
		cout << "    [d] InsertSort: "; for( auto val : presorted2 ) { cout << val << ", "; } cout << endl;
		cout << "    [d] MergeSort:  "; for( auto val : presorted3 ) { cout << val << ", "; } cout << endl;
		cout << "    [d] QuickSort:  "; for( auto val : presorted4 ) { cout << val << ", "; } cout << endl;
	}

	print_SortingStats( &sortedStats );         // in main.h
}


#endif