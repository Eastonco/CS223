/***************************************************************************
 *
 *  Sorting algorithms and counting work - Quicksort algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented quicksort
 *
 */

#ifndef __INSTRUMENTED_QS_H
#define __INSTRUMENTED_QS_H

#include <vector>
#include <ctime>
#include "main.h"   // For SortStats struct definiton

using namespace std;

void quicksort( vector<int> & a, int low, int high, SortStats & stats){
	int i = low, j = high;
	int pivot = a[(low + high)/ 2];

	while(i <= j ){
		while(a[i] < pivot && ++stats.compares){
			i++;
		}
		while(a[j] > pivot && ++stats.compares){
			j--;
		}
		if(i<= j){
			swap(a[i], a[j]);
			++stats.moves;
			i++;
			j--;
		}
	}

	if(low < j){
		quicksort(a, low, j, stats);
	}
	if(i < high){
		quicksort(a, i, high, stats);
	}
}

void instrumentedQuickSort( vector<int> & a, SortStats & stats )
{
	clock_t time_begin = clock();		// Please leave in place for stats


	// Begin sorting algorithm

	// Begin your quicksort code here
	// You're free to add more functions if you like, but vector<int> a must be sorted when done
	// NOTE: you must update stats with comparisons and moves as your algorithm runs
	//  The best example of updating the stats is available in the file:
	//  instrumentedBubbleSort.h
	
	quicksort(a, 0, a.size()-1, stats);

	// End sorting algorithm


	clock_t time_end = clock();			// Please leave in place for stats
	stats.sortTime = double(time_end - time_begin) / CLOCKS_PER_SEC;
}

#endif
