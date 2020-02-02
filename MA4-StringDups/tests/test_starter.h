/*
 *  Test suite for Hashing based duplicates project
 *
 *   All tests should begin with Starter* for their group name
 *
 */

#ifndef __STARTER_TESTS_H
#define __STARTER_TESTS_H

#include <vector>
#include <gtest/gtest.h>        // Google's C++ testing harness
#include <gmock/gmock.h>        // Google's object mocking library
#include "BruteDetector.h"      // Brute force duplicate detector
#include "SortingDetector.h"    // Sort then search detector
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
TEST(StarterBrute, SuperShortVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = super_short_vector;
    auto & known_dups_vector  = super_short_vector_dups;

    dups_found = find_duplicates_brute_force(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterBrute, NoDupsVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = no_dups_vector;
    auto & known_dups_vector  = no_dups_vector_dups;

    dups_found = find_duplicates_brute_force(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterBrute, ShortVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = short_vector;
    auto & known_dups_vector  = short_vector_dups;

    dups_found = find_duplicates_brute_force(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterBrute, OneHundredVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = onehundred_vector;
    auto & known_dups_vector  = onehundred_vector_dups;

    dups_found = find_duplicates_brute_force(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterBrute, OneThousandVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = onethousand_vector;
    auto & known_dups_vector  = onethousand_vector_dups;

    dups_found = find_duplicates_brute_force(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}


//**************** Start of Sorting-based Tests ********************//
TEST(StarterSorting, SuperShortVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = super_short_vector;
    auto & known_dups_vector  = super_short_vector_dups;

    dups_found = find_duplicates_with_sorting(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterSorting, NoDupsVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = no_dups_vector;
    auto & known_dups_vector  = no_dups_vector_dups;

    dups_found = find_duplicates_with_sorting(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterSorting, ShortVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = short_vector;
    auto & known_dups_vector  = short_vector_dups;

    dups_found = find_duplicates_with_sorting(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterSorting, OneHundredVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = onehundred_vector;
    auto & known_dups_vector  = onehundred_vector_dups;

    dups_found = find_duplicates_with_sorting(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

TEST(StarterSorting, OneThousandVector)
{
    std::vector<std::string> dups_found;
    auto & search_vector      = onethousand_vector;
    auto & known_dups_vector  = onethousand_vector_dups;

    dups_found = find_duplicates_with_sorting(search_vector);

    std::sort(dups_found.begin(), dups_found.end());
    std::sort(known_dups_vector.begin(), known_dups_vector.end());

    ASSERT_EQ(known_dups_vector.size(), dups_found.size());
    for( unsigned int i = 0; i < dups_found.size(); ++i ) {
        ASSERT_EQ(known_dups_vector[i], dups_found[i]);
    }
}

#endif
