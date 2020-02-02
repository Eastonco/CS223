/*
 *  Test suite for BST Level Order (and BigFive) project
 *
 *  Copyright 2018 - intructional use only
 *
 *  Contributors:
 *   Aaron S. Crandall <acrandal@wsu.edu>
 */

#include <gtest/gtest.h>        // Google C++ testing harness
#include <gmock/gmock.h>        // Google object mocking library
using namespace testing;        // Google's testing namespace

#include "ChainingHash.h"
#include "ProbingHash.h"

/* Class designed to expose implementation details of the BST
   Notably, this allows us direct access to the root pointer
   This allows for testing shallow/deep comparisions and destructors
   This class is used in some of the tests
*/
template<class K, class V>
class TestableChainingHash : public ChainingHash<K, V> {
    public:
    vector<vector<V*>> & getData() {       // Gives out our root pointer for testing
        return this->data;
    }
};

template<class K, class V>
class TestableProbingHash : public ProbingHash<K, V> {
    public:
    vector<V*> & getData() {       // Gives out our root pointer for testing
        return this->data;
    }
};


#include "tests/test_starter.h"
#include "tests/test_base.h"


// Main only sets up the Google gtest system and runs the tests
// Any Functions called "TEST" will be run
// These tests are all kept in the tests/ directory
//  -- See the #include "tests/*" above
int main(int argc, char* argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
