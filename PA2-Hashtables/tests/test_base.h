/*
 *  Test suite for BST Level Order project
 *
 *  All tests in this file should start with Base*
 * 
 */

#ifndef __BASE_TESTS_H
#define __BASE_TESTS_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <ctime>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <time.h>           // For seeding srand with time

#include "ChainingHash.h"
#include "ProbingHash.h"

using namespace testing;

template <typename K, typename V>
void empty_when_empty(Hash<K, V> & hash) {
    ASSERT_EQ(true, hash.empty());  // Assert
}

template <typename K, typename V>
void size_when_empty(Hash<K, V> & hash) {
    ASSERT_EQ(0, hash.size());  // Assert
}

template <typename K, typename V>
void out_of_range_when_empty(Hash<K, V> & hash) {
    EXPECT_THROW(hash.at(1), std::out_of_range);        // Search for key of 1 - fails, so throw out_of_range
}

template <typename K, typename V>
void not_empty_after_add(Hash<K, V> & hash) {
    hash.emplace(17, 17);           // Act
    ASSERT_EQ(false, hash.empty()); // Assert
}

template <typename K, typename V>
void clear_empty_hash(Hash<K, V> & hash) {
    hash.clear();                   // Act - Should delete all entries
    ASSERT_EQ(true, hash.empty());  // Assert
}


template <typename K, typename V>
void clear_after_add(Hash<K, V> & hash) {
    std::vector<int> vals{10, 15, 6, 3, 8, 16, 13, 7, 14};
    for( auto val : vals )
        hash.emplace(val, val);
    hash.clear();
    ASSERT_EQ(true, hash.empty());  // Assert
    ASSERT_EQ(0, hash.size());  // Assert
}

template <typename K, typename V>
void remove_on_empty_hash(Hash<K, V> & hash) {
    hash.erase(10);                 // Try to remove element that doesn't exist - most likely bug
    ASSERT_EQ(true, hash.empty());
}

template <typename K, typename V>
void access_by_index_key(Hash<K, V> & hash) {
    int key = 17;
    int value = 20;
    hash.emplace(key, value);           // Act
    EXPECT_EQ(false, hash.empty());     // Assert
    EXPECT_EQ(value, hash[key]);        // Test [] operator for accessing
}

template <typename K, typename V>
void update_on_duplicate_key(Hash<K, V> & hash) {
    int key = 17;
    int value = 20;
    hash.emplace(key, value);           // Act
    ASSERT_EQ(false, hash.empty());     // Assert
    EXPECT_EQ(value, hash[key]);
    value = 21;
    hash.emplace(key, value);           // Change value for key (17) to 21
    ASSERT_EQ(false, hash.empty());     // Assert
    EXPECT_EQ(1, hash.size());
    EXPECT_EQ(value, hash[key]);        // Is returned value new key?
}

template <typename K, typename V>
void erase_by_key(Hash<K, V> & hash) {
    int key = 12;
    int val = 42;
    hash.emplace(key, val);
    hash.emplace(15, 123);              // Add some other data
    hash.emplace(23, 12);
    ASSERT_EQ(false, hash.empty());
    EXPECT_EQ(3, hash.size());
    hash.erase(key);                    // Erase the element
    ASSERT_EQ(false, hash.empty());
    EXPECT_EQ(2, hash.size());
    EXPECT_THROW(hash.at(12), std::out_of_range);
}


template <typename K, typename V>
void rehashing(Hash<K, V> & hash) {
    vector<int> keys{ 10, 11, 12, 13, 34, 43 };
    vector<int> values{ 20, 21, 22, 23, 44, 53 };

    for(int i = 0; i < int(keys.size()); i++)   // Insert data into hash table
    {
        hash.emplace(keys[i], values[i]);
    }

    float before_load = hash.load_factor(); // Save current load factor

    EXPECT_EQ(false, hash.empty());         // Just checking for empty table
    EXPECT_EQ(keys.size(), hash.size());    // Verifying the data size

    hash.rehash(300);                       // Force rehash to larger size (should be 23)
    EXPECT_LE(20, hash.bucket_count());

    float after_load = hash.load_factor();  // Get new post-rehash load factor

    std::cout << "Load factor went from " << before_load << " to " << after_load << " after rehash" << std::endl;
    EXPECT_GE(before_load, after_load);     // Test that load factor has dropped

    for (int i = 0; i < int(keys.size()); i++)
    {
        std::cout << " Searching hash for <key,value>: <" << keys[i] << "," << values[i] << "> found: ";
        std::cout << "<" << keys[i] << "," << hash[keys[i]] << ">" << std::endl;
        EXPECT_EQ(values[i], hash[keys[i]]);
    }

    EXPECT_EQ(keys.size(), hash.size());
}


template <typename K, typename V>
void force_rehash(Hash<K, V> & hash) {
    vector<int> keys{ 10, 11, 12, 13, 34, 43 };
    vector<int> values{ 20, 21, 22, 23, 44, 53 };

    for(int i = 0; i < int(keys.size()); i++)   // Insert data into hash table
    {
        hash.emplace(keys[i], values[i]);
    }

    int   curr_element_count = hash.size();
    int   curr_bucket_count = hash.bucket_count();
    int   force_rehash_num = curr_bucket_count - curr_element_count;

    for( int i = 0; i < force_rehash_num; ++i ) {
        hash.emplace((i+1) * 100000, (i+2) * 100000);   // Should force rehash
    }

    EXPECT_LE(curr_element_count, hash.size());
    EXPECT_LE(curr_bucket_count, hash.bucket_count());
}

template <typename K, typename V>
void huge_random_hash_test(Hash<K, V> & hash) {
    std::time_t start_time = std::time(nullptr);    // Get starting time
    std::time_t curr_time = start_time;
    std::vector<std::pair<int, int>> entries;
    uint64_t max_entry_count = (uint64_t)pow(2, 18);       // 1048576
    std::cout << "  Adding " << max_entry_count << " entries with random ints to hash table" << std::endl;
    std::cout << "   Every 5th add, a single random element is selected for removal" << std::endl;
    while(entries.size() < max_entry_count)
    {
        int new_key = rand() % INT_MAX;
        int new_val = rand() % INT_MAX;
        hash.emplace(new_key, new_val);
        entries.push_back(std::pair<int, int>(new_key, new_val));

        curr_time = std::time(nullptr);             // Get current time
        float percent_complete = 100 * (float)entries.size() / (float)max_entry_count;
        std::cout << "\r  Hash size: " << std::setw(8) << hash.size() << " | Buckets: " << std::setw(8) << hash.bucket_count();
        std::cout << " | Load: " << std::setw(9) << 100 * hash.load_factor() << "%";
        std::cout << " | Done: " << std::setw(9) << percent_complete << "% ";
        std::cout << " | Runtime: " << (curr_time - start_time) << " sec    ";

        if(entries.size() % 5 == 0) {
            uint64_t selected_index = rand() % entries.size();
            int selected_key = entries[selected_index].first;
            hash.erase( selected_key );
            entries.erase( entries.begin() + selected_index );
            // After removing a random one, add one more to push forward
            new_key = rand() % INT_MAX;
            new_val = rand() % INT_MAX;
            hash.emplace(new_key, new_val);
            entries.push_back(std::pair<int, int>(new_key, new_val));
        }
    }
    std::cout << std::endl;
}

template <typename K, typename V>
void stress_random_hash_test(Hash<K, V> & hash) {
    srand((unsigned int)time(NULL));
    std::vector<std::pair<int, int>> entries;
    uint64_t max_entry_count = (uint64_t)pow(2, 16);       // 65536
    std::cout << "  Adding " << max_entry_count << " entries with random ints to chaining hash" << std::endl;
    //int entrynum =0;
    while(entries.size() < max_entry_count)
    {
        //entrynum++;
        int new_key = rand() % INT_MAX;
        try
        {
            hash.at(new_key);
            continue;
        } catch (std::out_of_range & e) 
        {   // Ignore these
        }
        int new_val = rand() % INT_MAX;
        int before_size = hash.size();
        hash.emplace(new_key, new_val);
        //cout << entrynum << " / 65536" << endl;
        ASSERT_GT(hash.size(), before_size);
        before_size = int(entries.size());
        entries.push_back(std::pair<int, int>(new_key, new_val));
        ASSERT_GT(int(entries.size()), before_size);

        if(entries.size() % 5 == 0) {
            uint64_t selected_index = rand() % entries.size();
            int selected_key = entries[selected_index].first;

            EXPECT_NO_THROW(hash.at(selected_key)); // Ensure that value is in hash

            int hash_size = int(hash.size());

            hash.erase( selected_key );
            if (hash_size - 1 != hash.size())
            {
                cout << "Failed to erase [" << selected_key << ", "
                     << entries[selected_index].second << "]" << endl;
            }
            ASSERT_EQ(hash_size - 1, int(hash.size()));
            int entry_size = int(entries.size());
            entries.erase( entries.begin() + selected_index );
            ASSERT_EQ(entry_size - 1, int(entries.size()));
            EXPECT_THROW(hash.at(selected_key), std::out_of_range);
            // Insert a new value after removing one to move forward.
            new_key = rand() % INT_MAX;
            try
            {
                while (1)
                {
                    hash.at(new_key); //Hack to ensure a new key value
                    new_key = rand() % INT_MAX;
                }
            } catch (std::out_of_range & e)
            {   // Ignore this kind of error
            }

            new_val = rand() % INT_MAX;
            hash.emplace(new_key, new_val);
            entries.push_back(std::pair<int, int>(new_key, new_val));
            ASSERT_EQ(entries.size(), hash.size());
        }
    }
}

// ********* Start of Hash tests ******************************************** //
// ** Tests for which Separate Chaining internal details are implemented ** //
TEST(Base_ChainingHash, Empty_When_Empty)
{
    ChainingHash<int, int> hash;    // Assemble
    empty_when_empty(hash);
}

TEST(Base_ChainingHash, Size_When_Empty)
{
    ChainingHash<int, int> hash;   // Assemble
    size_when_empty(hash);
}

TEST(Base_ChainingHash, OutOfRangeWhenEmpty)
{
    ChainingHash<int, int> hash;
    out_of_range_when_empty(hash);
}

TEST(Base_ChainingHash, Not_Empty_After_Add)
{
    ChainingHash<int, int> hash;    // Assemble
    not_empty_after_add(hash);
}

TEST(Base_ChainingHash, Clear_Empty_Hash)
{
    ChainingHash<int, int> hash;    // Assemble
    clear_empty_hash(hash);
}

TEST(Base_ChainingHash, Clear_After_Add)
{
    ChainingHash<int, int> hash;              // Assemble
    clear_after_add(hash);
}

TEST(Base_ChainingHash, Remove_On_Empty_Hash)
{
    ChainingHash<int, int> hash;
    remove_on_empty_hash(hash);
}

TEST(Base_ChainingHash, Access_By_Index_Key)
{
    ChainingHash<int, int> hash;    // Assemble
    access_by_index_key(hash);
}

TEST(Base_ChainingHash, Update_On_Duplicate_Key)
{
    ChainingHash<int, int> hash;        // Assemble
    update_on_duplicate_key(hash);
}

TEST(Base_ChainingHash, Erase_By_key)
{
    ChainingHash<int, int> hash;
    erase_by_key(hash);
}

TEST(Base_ChainingHash, Force_Rehash)
{
    ChainingHash<int, int> hash;
    force_rehash(hash);
}

TEST(Base_ChainingHash, Rehashing)
{
    ChainingHash<int, int> hash;
    rehashing(hash);
}

// ************** END Separate Chaining tests ********************* //


// ********* Start of ProbingHash tests ***************** //
TEST(Base_ProbingHash, Empty_When_Empty)
{
    ProbingHash<int, int> hash;    // Assemble
    empty_when_empty(hash);
}

TEST(Base_ProbingHash, Size_When_Empty)
{
    ProbingHash<int, int> hash;   // Assemble
    size_when_empty(hash);
}

TEST(Base_ProbingHash, OutOfRangeWhenEmpty)
{
    ProbingHash<int, int> hash;
    out_of_range_when_empty(hash);
}

TEST(Base_ProbingHash, Not_Empty_After_Add)
{
    ProbingHash<int, int> hash;    // Assemble
    not_empty_after_add(hash);
}

TEST(Base_ProbingHash, Clear_Empty_Hash)
{
    ProbingHash<int, int> hash;    // Assemble
    clear_empty_hash(hash);
}

TEST(Base_ProbingHash, Clear_After_Add)
{
    ProbingHash<int, int> hash;              // Assemble
    clear_after_add(hash);
}

TEST(Base_ProbingHash, Remove_On_Empty_Hash)
{
    ProbingHash<int, int> hash;
    remove_on_empty_hash(hash);
}

TEST(Base_ProbingHash, Access_By_Index_Key)
{
    ProbingHash<int, int> hash;    // Assemble
    access_by_index_key(hash);
}

TEST(Base_ProbingHash, Update_On_Duplicate_Key)
{
    ProbingHash<int, int> hash;        // Assemble
    update_on_duplicate_key(hash);
}

TEST(Base_ProbingHash, Erase_By_key)
{
    ProbingHash<int, int> hash;
    erase_by_key(hash);
}

TEST(Base_ProbingHash, Rehashing)
{
    ProbingHash<int, int> hash;
    rehashing(hash);
}

TEST(Base_ProbingHash, Force_Rehash)
{
    ProbingHash<int, int> hash;
    force_rehash(hash);
}

// ************** END Linear Probing tests ********************* //


// ************************** HUGE Probing Test ************************ //

/** HUGE ChainingHash testing **/
TEST(Huge_ChainingHash, Stress_Random_Hash_Test)
{
    ChainingHash<int, int> hash;
    stress_random_hash_test(hash);
}

TEST(Huge_ChainingHash, Huge_Random_Hash_Test)
{
    ChainingHash<int, int> hash;
    huge_random_hash_test(hash);
}

/** HUGE ProbingHash testing **/
TEST(Huge_ProbingHash, Stress_Random_Hash_Test)
{
    ProbingHash<int, int> hash;
    stress_random_hash_test(hash);
}
TEST(Huge_ProbingHash, Huge_Random_Hash_Test)
{
    ProbingHash<int, int> hash;
    huge_random_hash_test(hash);
}

#endif
