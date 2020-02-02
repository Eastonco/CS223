/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - inherits from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    vector<list<pair<K,V>>> _table; //?? CORRECT
    int TableSize;
public:

    ChainingHash(int n = 11){
        TableSize = n;
        _table.resize(findNextPrime(n), list<pair<K,V>>());
    }

    ~ChainingHash() {
        this->clear();
    }

    bool empty() {
        list<pair<K,V>> tmpList;
        for(int i = 0; i < _table.capacity(); i++){
            tmpList = _table[i];
            if(tmpList.size() > 0){
                return false;
            }
        }
       return true;
    }


    int size() {
        int total_size = 0;
        for(auto i = 0; i < _table.size(); i++){
            for(auto b : _table[i]){
                total_size++;
            }
        }
        return total_size;
    }

    V& at(const K& key) {
        int hkey = hash(key);
        list<pair<K,V>> & hlist = _table[hkey];
        for(pair<K,V> & p : hlist){
            if(p.first == key){
                return p.second;
            }
        }
        throw std::out_of_range("Key not in hash");
    }

    V& operator[](const K& key) {
        return at(key);
    }

    int count(const K& key) {
        int hkey = hash(key);
        int keycount = 0;
        list<pair<K,V>> & hlist = _table[hkey];
        for(pair<K,V> & p : hlist){
            if(p.first == key){
                keycount++;
            }
        }
        return keycount;
    }


    void emplace(K key, V value) {
          if(!count(key)){
            int hkey = hash(key);
            _table[hkey].emplace_front(key, value);
        } else {
            erase(key);
            emplace(key, value);
        }

        if(load_factor() > 1)
            rehash();
    }
        /*
        try {
            auto curr_val = at(key);
            cout << "Overwritting value" << endl;
            curr_val = value;
        } catch (std::out_of_range& e) {
            cout << "Catch in emplace!" << endl;
            int hkey = hash(key);
            _table[hkey].emplace_front(key, value);
        }
        */

      

    void insert(const std::pair<K, V>& pair) {
        emplace(pair.first, pair.second);
    }

    void erase(const K& key) {
        int hkey = hash(key);
        list<pair<K,V>> & hlist = _table[hkey];
        auto itr = hlist.begin();

        for(pair<K,V> p : hlist){
            if(p.first == key){
                hlist.erase(itr);
                return;
            }
            itr++;

        }
    }

    void clear() {
        for(auto i = 0; i < _table.size() ; i++){
            _table[i].clear();
        }
    }

    int bucket_count() {
        return _table.capacity();
    }

    int bucket_size(int n) {
        int size;
        for(auto i : _table[n]){
            size++;
        }
        return size;
    }

    int bucket(const K& key) {
    }

    float load_factor() {
        float usedBuckets = 0;
        list<pair<K,V>> tmpList;
        for(int i = 0; i < _table.capacity(); i++){
            tmpList = _table[i];
            if(tmpList.size() > 0){
                usedBuckets++;
            }
        }
        return usedBuckets / bucket_count();
    }

    void rehash() {
        TableSize = findNextPrime(2 * bucket_count());
        vector<pair<K,V>> AllVals;
        for(int i = 0; i < _table.capacity(); i++){
            for(pair<K,V> j : _table[i]){
                AllVals.push_back(j);
            }
        }
        clear();
        _table.resize(TableSize);

        for(pair<K,V> p : AllVals){
            insert(p);
        }
    }

    void rehash(int n) {
        TableSize = findNextPrime(n);
        vector<pair<K,V>> AllVals;
        pair<K,V> tmpPair;
        for(int i = 0; i < _table.capacity(); i++){
            for(pair<K,V> j : _table[i]){
                AllVals.push_back(j);
            }
        }

        clear();
        _table.resize(TableSize);

        for(pair<K,V> p : AllVals){
            insert(p);
        }
    }


private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return (key % TableSize);       // This technicall works, but is very very bad
    }
};

#endif //__CHAINING_HASH_H
