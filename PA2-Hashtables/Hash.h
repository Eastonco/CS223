/*
 *  Yet another Hash table interface
 * 
 *  Contributors:
 *      Aaron S. Crandall <acrandal@wsu.edu> - 2019
 *      Sean Kallaher <seanp@kallaher.org> - 2019
 * 
 */

#ifndef __Hash_H
#define __Hash_H

// Hash class interface notes
// ******************PUBLIC OPERATIONS*********************
// bool empty( )                            --> Test for empty hash
// int size( )                              --> Quantity of (non-deleted) elements in hash
// V& at( const K& k )                      --> Returns the value with key k
// V& operator[]( const K&t k )              --> Returns the value with key k
// int count( const K& key )                --> Returns the number of elements with key k
// bool emplace ( const K& key, V& value )  --> Adds element with key, true if successful
// bool insert( const pair<K, V>& pair )    --> Adds pair to hash, true if successful
// void erase( const K& k )                 --> Removes all any (if any) entries with key k
// void clear( )                            --> Empties the hash
// int bucket_count()                       --> Returns the number of buckets allocated (size of the hash vector)
// int bucket_size( int n )                 --> Returns the number of elements in bucket n (0, 1, or length of list if chaining)
// int bucket( const K& key )               --> Returns the bucket number of key (or throws std::out_of_range if key not found)
// float load_factor( )                     --> Returns the load factor of the hash
// void rehash( int n )                     --> Resizes the hash to contain at least n buckets
//                                              Resizes to next prime starting from n and going up


// void ~Hash( )       --> Destructor
// Hash( )             --> Basic constructor

//
//  Hash is a purely virtual base class for other Hash implementations to inherit from
//   Expected subclasses include: ChainingHash - uses a vector of lists
//                                ProbingHash - linear probing on a vector
//  This interface is based upon, and expects similar behavior to the C++11 STL unordered_map
//
template <typename K, typename V>
class Hash
{
private:

public:
    virtual ~Hash() = 0;

    virtual bool empty() = 0;

    virtual int size() = 0;

    virtual V& at(const K& key) = 0;

    virtual V& operator[](const K& key) = 0;

    virtual int count(const K& key) = 0;

    virtual void emplace(K key, V value) = 0;

    virtual void insert(const std::pair<K, V>& pair) = 0;

    virtual void erase(const K& key) = 0;

    virtual void clear() = 0;

    virtual int bucket_count()= 0;

    virtual int bucket_size(int n) = 0;

    virtual int bucket(const K& key) = 0;

    virtual float load_factor() = 0;

    virtual void rehash( int n ) = 0;

// *************** Private /internal function implementation ******* //

private:
    virtual int hash(const K& key) = 0;

};

// This is required to make Hash a pure virtual (abstract) class
template <typename K, typename V>
Hash<K, V>::~Hash() {}


#endif
