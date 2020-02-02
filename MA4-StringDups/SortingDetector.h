/*
 *  Brute force detector implementation
 * 
 *  Aaron S. Crandall <acrandal@wsu.edu> - 2019
 * 
 */

#ifndef __SORT_DETECTOR_H
#define __SORT_DETECTOR_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>        // for std::sort - quicksort!

/*
 *  Function to return a list of the strings appearing more than one time in an input vector
 */
std::vector<std::string> find_duplicates_with_sorting(std::vector<std::string> & strings) {
    std::vector<std::string> dups;

    std::sort(strings.begin(), strings.end());

    for( unsigned int i = 0; i < strings.size() - 1; ++i ) {
        if( strings[i].compare(strings[i+1]) == 0 ) {
            std::string found_dup = strings[i];
            if( dups.size() == 0 ) {
                dups.push_back(found_dup);
            }
            else
            {
                std::string last_found_dup = dups[ dups.size() - 1 ];
                if( last_found_dup.compare(found_dup) != 0 ) {              // Not a dup of a dup
                    dups.push_back(found_dup);
                }
            }
        }
    }

    return dups;
}

#endif