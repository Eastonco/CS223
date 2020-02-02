/*
 *  Test suite for Duplicate Strings Finder
 *
 *  Copyright 2019 - intructional use only
 *
 *  Contributors:
 *   Aaron S. Crandall <acrandal@wsu.edu>
 */

#include <gtest/gtest.h>        // Google C++ testing harness
#include <gmock/gmock.h>        // Google object mocking library

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
