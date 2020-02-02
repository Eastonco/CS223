/***************************************************************************
 *
 *  Sorting algorithms and counting work - Merge sort algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented mergesort
 *
 */

#ifndef __INSTRUMENTED_MS_H
#define __INSTRUMENTED_MS_H

#include <vector>
#include <ctime>
#include "main.h"   // For SortStats struct definiton

using namespace std;

void merge(vector<int> & a, vector<int> & tmp, int lpos, int rpos, int rEnd, SortStats & stats){
	int lEnd = rpos -1;
	int tmppos = lpos;
	int numElements = rEnd - lpos +1;

	while(lpos <= lEnd && rpos <= rEnd){
		if(a[lpos] <= a[rpos] && ++stats.compares){
			tmp[tmppos++] = move(a[lpos++]);
			stats.moves++;
		}
		else{
			tmp[tmppos++] = move(a[rpos++]);
			stats.moves++;
		}
	}
	while(lpos <= lEnd){
		tmp[tmppos++] = move(a[lpos++]);
		stats.moves++;
	}
	while(rpos <= rEnd){
		tmp[tmppos++] = move(a[rpos++]);
		stats.moves++;
	}
	for(int i = 0; i < numElements; ++i, --rEnd){
		a[rEnd] = move(tmp[rEnd]);
		stats.moves++;
	}
} 


void mergeSort( vector<int> & a, vector<int> & tmp, int left, int right , SortStats & stats){
	if( left < right){
		int center = (left + right) / 2;
		mergeSort(a, tmp, left, center, stats);
		mergeSort(a, tmp, center +1, right, stats);
		merge(a, tmp, left, center +1, right, stats);
	}
}




void instrumentedMergeSort( vector<int> & a, SortStats & stats )
{
    clock_t time_begin = clock();		// Please leave in place for stats

	// Begin sorting algorithm

	// Begin your merge sort code here
	// You're free to add more functions if you like, but vector<int> a must be sorted when done
	// NOTE: you must update stats with comparisons and moves as your algorithm runs
	//  The best example of updating the stats is available in the file:
	//  instrumentedBubbleSort.h
	vector<int> tmpArr;

	for(int i = 0; i < a.size(); i++){
		tmpArr.push_back(i);
	}
	
	mergeSort(a, tmpArr, 0, a.size() -1, stats);

	//mergeSort(a, 0, a.size(), stats);
	// End sorting algorithm

    clock_t time_end = clock();			// Please leave in place for stats
	stats.sortTime = double(time_end - time_begin) / CLOCKS_PER_SEC;
}


#endif
