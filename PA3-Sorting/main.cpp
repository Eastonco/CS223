/***************************************************************************
 *
 *  Sorting algorithms and couting work 
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 */
	
#include <iostream>
#include <string.h>

#include "testVectors.h"
#include "main.h"
#include "instrumentedBubbleSort.h"
#include "instrumentedInsertionSort.h"
#include "instrumentedMergeSort.h"
#include "instrumentedQuickSort.h"

using namespace std;

template<typename SORTORDERTYPE>
void test_presorted_data( int n = 2000, int seed = -1) {
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

	print_SortingStats( &sortedStats );
}


/**
 *  Run a series of tests to evaluate the heap object
 */
void sortingTests(int n = 20)
{
	cout << " [t] Testing sorting algorithms with n = " << n << ". " << endl;
	cout << "  [t] Generating results for pre-sorted data. **********************" << endl;
	test_presorted_data<SortedTestVector>(n);
	cout << endl << "  [t] Generating results for reversed-sorted data. *****************" << endl;
	test_presorted_data<ReversedTestVector>(n);
	cout << endl << "  [t] Generating results for shuffled-sorted data. *****************" << endl;
	test_presorted_data<ShuffledTestVector>(n, 100);
	cout << endl;
}

/**
 *  Main function for our sorting and sorting testing
 */
int main(int argc, char* argv[])
{
	bool is_test_mode = false;
	bool is_bigtest_mode = false;
	bool is_humongoustest_mode = false;

	for( int i = 0; i < argc; i++ ) {
		if( !strcmp(argv[i], "--test" ) ) {
			cout << " [x] Enabling test mode. " << endl;
			is_test_mode = true;
		}
		else if( !strcmp(argv[i], "--bigtest" ) ) {
			cout << " [x] Enabling bigtest mode. " << endl;
			is_bigtest_mode = true;
		}
		else if( !strcmp(argv[i], "--humongoustest" ) ) {
			cout << " [x] Enabling humongoustest mode. " << endl;
			is_humongoustest_mode = true;
		}
    }

	if( is_test_mode )
	{
		cout << " [x] Running in test mode. " << endl;
		sortingTests(20);
		cout << " [x] Program in test mode complete. " << endl;
	}
	else if( is_bigtest_mode ) 
	{
		cout << " [x] Running in BIG test mode. " << endl;
		sortingTests(30000);
		cout << " [x] Program in BIG test mode complete. " << endl;
	}
	else if( is_humongoustest_mode ) 
	{
		cout << " [x] Running in ***HUMONGOUS*** test mode. " << endl;
		cout << "  [WTF] - This is going to sort 3 million elements." << endl;
		cout << "  [WTFII] - RIP your CPU, don't say I didn't warn you. " << endl;
		cout << "  [WTFIIT] - My desktop took X Seconds to complete - " << endl;
		cout << "  [WTFIV]   - Use 'time make humongoustest' to see it for you" << endl;
		sortingTests(3000000);
		cout << " [x] Program in ***HUMONGOUS*** test mode complete. " << endl;
	}
	else
	{
		cout << endl << " You should probably run 'make test' to test your program. " << endl;
		cout << " Once ready for a big test, run 'make bigtest' to get bigger numbers. " << endl;
		cout << "  My bigtest takes about 1 minute to finish. " << endl;
		cout << "  With big numbers, the percentage counts do round to 0%" << endl;
	}
}
