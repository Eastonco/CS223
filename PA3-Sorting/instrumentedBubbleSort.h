/***************************************************************************
 *
 *  Sorting algorithms and counting work - BS algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented bubblesort
 *
 */

#ifndef __INSTRUMENTED_BS_H
#define __INSTRUMENTED_BS_H

#include <vector>
#include <ctime>
#include "main.h"   // For SortStats struct definiton

using namespace std;

void instrumentedBubbleSort( vector<int> & a, SortStats & stats )
{
	clock_t time_begin = clock();
	bool swapp = true;
	while(swapp){
		swapp = false;
		for (size_t i = 0; i < a.size()-1; i++)
		{
			if ( ++stats.compares && a[i] > a[i+1] ) 	// NOTE: Log the comparison
			{
				stats.moves++;             				// NOTE: Log that we swapped (moved)
				a[i] += a[i+1];
				a[i+1] = a[i] - a[i+1];
				a[i] -= a[i+1];
         		swapp = true;
			}
		}
	}
	clock_t time_end = clock();
	stats.sortTime = double(time_end - time_begin) / CLOCKS_PER_SEC;
}

#endif
