#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>
#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> {
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<EntryState, pair<K,V>>> _table;
    int TableSize;

public:
    ProbingHash(int n = 11) {
        TableSize = n;
        _table.resize(findNextPrime(n), pair<EntryState, pair<K,V>>());
    }

    ~ProbingHash() {
        // Needs to actually free all table contents
    }

    bool empty() {
        for(int i = 0; i < _table.capacity(); i++){
            if(_table[i].first != EMPTY)
                return false;
        }
        return true;
    }

    int size() {
        int totalSize = 0;
        for(auto i = 0; i < _table.size(); i++){
            if(_table[i].first == VALID){
                totalSize++;
            }
        }
        return totalSize;
    }

    V& at(const K& key) {
        int hkey = hash(key);
        K tmpkey = key;
        V & returnval();
        while(_table[hkey].first != EMPTY ){
            if(_table[hkey].second.first == key && _table[hkey].first != DELETED){
                return _table[hkey].second.second;
            }
            tmpkey++;
            hkey = hash(tmpkey);
        }
        throw std::out_of_range("Key not in hash");
    }

    V& operator[](const K& key) {
        return at(key);
    }

    int count(const K& key) {
        int hkey = hash(key);
        int keycount = 0;
        int i = 0;
        while(_table[hkey].first != EMPTY){
            if(_table[hkey].second.first == key && _table[hkey].first != DELETED){
                keycount++;
            }
            i++;
            hkey = hash(key+i);
        }
        return keycount;
    }
    void emplace(K key, V value) {
        if(!count(key)){
            int hkey = hash(key);
            K tmpkey = key;
            while(_table[hkey].first != EMPTY){
                tmpkey++;
                hkey = hash(tmpkey);
            }
            _table[hkey].first = VALID;
            _table[hkey].second.first = key;
            _table[hkey].second.second = value;
        }
        else{
            erase(key);
            emplace(key, value);
        }

        if(load_factor() > .5)
            rehash();

    }

    void insert(const std::pair<K, V>& pair) {
        emplace(pair.first, pair.second);
    }

    void erase(const K& key) {
        int hkey = hash(key);
        K tmpkey = key;
        while(_table[hkey].first != EMPTY){
            if(_table[hkey].second.first == key){
                _table[hkey].first = DELETED;
                return;
            }
            tmpkey++;
            hkey = hash(tmpkey);
        }
        return;
    }

    void clear() {
        for(int i = 0; i < _table.capacity(); i++){
            _table[i].first = EMPTY;
        }
        _table.clear();
    }

    int bucket_count() {
        return _table.capacity();
    }
    

    int bucket_size(int n) {
    }

    int bucket(const K& key) {
    }

    float load_factor() {
        int count = 0;
        for(int i = 0; i < _table.capacity(); i++){
            if(_table[i].first != EMPTY){
                count++;
            }
        }
        float load = count / bucket_count();
    }

    void rehash() {
        TableSize = findNextPrime(2 * bucket_count());
        vector<pair<K,V>> AllVals;
        for(int i = 0; i < _table.capacity(); i++){
            if(_table[i].first != EMPTY){
                AllVals.push_back(_table[i].second);
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
        for(int i = 0; i < _table.capacity(); i++){
            if(_table[i].first != EMPTY){
                AllVals.push_back(_table[i].second);
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
            return (key % TableSize);
        }
    
};

#endif //__PROBING_HASH_H
