/***************************************************************************
 *
 *  Sorting algorithms and couting work 
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides pre-filled vector objects to test with
 *
 */

#ifndef __TEST_VECTORS_H
#define __TEST_VECTORS_H

#include <vector>
#include <algorithm>  // std::random_shuffle
#include <ctime>      // std::time
#include <cstdlib>    // std::rand, std::srand

/**
 *  To get a vector in pre-sorted order:
 *   SortedTestVector sorted;
 *  To get one sorted with n elements:
 *    SortedTestVector sorted(n);
 *  To get a reverse sorted one:
 *    ReversedTestVector reversed;
 *    ReversedTestVector reversed(n);
 *  To get a randomly sorted vector:
 *    ShuffledTestVector shuffled;
 *    ShuffledTestVector shuffled(n);
 *  To get the same vector ordering, add a random seed value (1..MAXINT):
 *    ShuffledTestVector shuffled(n, seed);
 *     -- This will always return the same order if n and seed are the same
 */


//********************************************************************//
//** Data in a vector with pre-sorted ordering **//
class SortedTestVector : public std::vector<int> {
public:
	using vector<int>::vector;    // uses constructors from vector
   int& operator[](int i) { return vector<int>::at(i); } // range-checked
		// range-checked for const objects; 
   const int& operator[](int i) const { return vector<int>::at(i); } 

	SortedTestVector( int n = 100, int seedid = -1 ) {
		for( int i = 0; i < n; i++ ){
			push_back(i);
		}
	}
};

//********************************************************************//
//** Data in a vector with reverse-sorted ordering **//
class ReversedTestVector : public std::vector<int> {
public:
	using vector<int>::vector;    // uses constructors from vector
   int& operator[](int i) { return vector<int>::at(i); } // range-checked
		// range-checked for const objects; 
   const int& operator[](int i) const { return vector<int>::at(i); } 

	ReversedTestVector( int n = 100, int seedid = -1 ) {
		for( int i = 1; i <= n; i++ ){
			push_back(n-i);
		}
	}
};

//********************************************************************//
//** Data in a vector with shuffled-sorted ordering **//
class ShuffledTestVector : public std::vector<int> {
public:
	using vector<int>::vector;    // uses constructors from vector
   int& operator[](int i) { return vector<int>::at(i); } // range-checked
		// range-checked for const objects
   const int& operator[](int i) const { return vector<int>::at(i); } 

	ShuffledTestVector( int n = 100, int seedid = -1 ) {
		if( seedid == -1 )
			srand ( unsigned ( std::time(0) ) );
		else
			srand ( unsigned ( seedid ) );
		for( int i = 0; i < n; i++ ){
			push_back(i);
		}
		random_shuffle( begin(), end() );
	}
};


#endif
