/*
 *  Test suite for BST Level Order project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __BASE_TESTS_H
#define __BASE_TESTS_H

#include <vector>
#include <chrono>           // For timing tests
#include <gtest/gtest.h>    // Google's C++ testing harness
#include <gmock/gmock.h>    // Google's object mocking library
#include "BruteDetector.h"
#include "SortingDetector.h"
#include "HashDetector.h"
#include "TestVectors.h"
    /*
     * TestVectors.h defines vectors of strings to search dups in
     * These vectors include:
     *  no_dups_vector
     *  no_dups_vector_dups
     *  super_short_vector
     *  super_short_vector_dups
     *  short_vector
     *  short_vector_dups
     *  onehundred_vector
     *  onehundred_vector_dups
     *  onethousand_vector
     *  onethousand_vector_dups
     */

using namespace testing;    // gtest lives in the testing:: namespace

//**************** Start of Brute Force Tests ********************//
TEST(BaseHash, SuperShortVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = super_short_vector;
    auto & known_dups_vector  = super_short_vector_dups;

    dups_found = find_duplicates_with_hashtable(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(BaseHash, NoDupsVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = no_dups_vector;
    auto & known_dups_vector  = no_dups_vector_dups;

    dups_found = find_duplicates_with_hashtable(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(BaseHash, ShortVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = short_vector;
    auto & known_dups_vector  = short_vector_dups;

    dups_found = find_duplicates_with_hashtable(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(BaseHash, OneHundredVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = onehundred_vector;
    auto & known_dups_vector  = onehundred_vector_dups;

    dups_found = find_duplicates_with_hashtable(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(BaseHash, OneThousandVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = onethousand_vector;
    auto & known_dups_vector  = onethousand_vector_dups;

    dups_found = find_duplicates_with_hashtable(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(BaseComparisons, TimingManyOneThousandVector)
{
    int num_searches = 10;
    std::vector<std::string> dups_found;
    auto & search_vector      = onethousand_vector;
    auto & known_dups_vector  = onethousand_vector_dups;
    using namespace std::chrono;                // Timing library namespace

    // (1) Time how long brute force searching takes on lots of searching
    steady_clock::time_point brute_start = steady_clock::now();
    for( int i = 0; i < num_searches; ++i ) {
        dups_found = find_duplicates_brute_force(search_vector);
    }
    steady_clock::time_point brute_end = steady_clock::now();
    auto brute_time_us = duration_cast<microseconds>(brute_end - brute_start).count();
    //std::cout << "Searching with brute force took "
    //          << duration_cast<microseconds>(brute_end - brute_start).count()
    //          << "us.\n";

    // (2) Time how long a sorting-based way takes on lots of searching
    steady_clock::time_point sort_start = steady_clock::now();
    for( int i = 0; i < num_searches; ++i ) {
        dups_found = find_duplicates_with_sorting(search_vector);
    }
    steady_clock::time_point sort_end = steady_clock::now();
    auto sort_time_us = duration_cast<microseconds>(sort_end - sort_start).count();
    //int sort_time_us = duration_cast<microseconds>(sort_end - sort_start).count();
    //std::cout << "Searching with sorting first took "
    //          << duration_cast<microseconds>(sort_end - sort_start).count()
    //          << "us.\n";


    // (3) Time how long a sorting-based way takes on lots of searching
    steady_clock::time_point hash_start = steady_clock::now();
    for( int i = 0; i < num_searches; ++i ) {
        dups_found = find_duplicates_with_hashtable(search_vector);
    }
    steady_clock::time_point hash_end = steady_clock::now();
    auto hash_time_us = duration_cast<microseconds>(hash_end - hash_start).count();
    //std::cout << "Searching with hash table took "
    //          << duration_cast<microseconds>(hash_end - hash_start).count()
    //          << "us.\n";

    // Determine if Hashing is actually working correctly yet
    dups_found = find_duplicates_with_hashtable(search_vector);
    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());
    bool hashing_works = false;
    float hashing_speedup = 0.0;
    if( dups_found.size() == known_dups_vector.size() ) {
        hashing_works = true;
        if(hash_time_us <= 0) {
            hash_time_us = 1;       // If you've got a less than 1us search, rail at min of 1
        }
        hashing_speedup = (float)(brute_time_us / hash_time_us);
    }

    // Print out results in a happy table
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "|          Searching algorithms timing results           |" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "| (1) Brute force (N^2) search: " << std::setw(22) << brute_time_us << "us |" << std::endl;
    std::cout << "| (2) Sorting-first (N log N + N) search: " << std::setw(12) << sort_time_us << "us |" << std::endl;
    if(!hashing_works) {
        std::cout << "| (3) Hashtable-based (N) search: " << std::setw(20) << "<unknown>" << "us |" << std::endl;
    }else{
        std::cout << "| (3) Hashtable-based (N) search: " << std::setw(20) << hash_time_us << "us |" << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "| Hashing vs Brute Force speedup: " << std::setw(15) << hashing_speedup << " times! |" << std::endl;
    }
    std::cout << "----------------------------------------------------------" << std::endl;


}


#endif
