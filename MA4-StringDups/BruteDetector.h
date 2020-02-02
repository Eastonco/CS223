/*
 *  Brute force detector implementation
 * 
 *  Aaron S. Crandall <acrandal@wsu.edu> - 2019
 * 
 */

#ifndef __BRUTE_DETECTOR_H
#define __BRUTE_DETECTOR_H

#include <string>
#include <vector>
#include <iostream>

/*
 *  Finds duplicate strings by brute force in N^2 time (well... N/2 time)
 */
std::vector<std::string> find_duplicates_brute_force(std::vector<std::string> & strings) {
    std::vector<std::string> dups;

    for( unsigned int i = 0; i < strings.size() - 1; ++i ) {
        for( unsigned int j = i+1; j < strings.size(); ++j ) {
            if( strings[i].compare(strings[j]) == 0 ) {
                bool already_found = false;
                for( auto str : dups ) {                    // Use a foreach loop & iterators
                    if( str.compare(strings[i]) == 0) {
                        already_found = true;
                    }
                }
                if( !already_found ) {
                    dups.push_back(strings[i]);
                }
            }
        }
    }
    return dups;
}

#endif