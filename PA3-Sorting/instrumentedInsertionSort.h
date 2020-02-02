/***************************************************************************
 *
 *  Sorting algorithms and counting work - Insertion sort algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented insertionsort
 *
 */

#ifndef __INSTRUMENTED_IS_H
#define __INSTRUMENTED_IS_H

#include <vector>
#include <ctime>
#include "main.h"   // For SortStats struct definiton

using namespace std;

void instrumentedInsertionSort( vector<int> & a, SortStats & stats )
{
	clock_t time_begin = clock();			// Please leave this in for timing stats

	// Begin sorting algorithm

	// Begin your insertion sort code here
	// You're free to add more functions if you like, but vector<int> a must be sorted when done
	// NOTE: you must update stats with comparisons and moves as your algorithm runs
	//  The best example of updating the stats is available in the file:
	//  instrumentedBubbleSort.h


	int i, key, j;
	for(i = 1; i< a.size(); i++){
		key = a[i];
		j = i - 1;
		
		while(++stats.compares && j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j=j-1;
			stats.moves++;
		}
		a[j+1] = key;
	}

	// End sorting algorithm


	clock_t time_end = clock();				// Please leave this in for timing stats
	stats.sortTime = double(time_end - time_begin) / CLOCKS_PER_SEC;
}

#endif
