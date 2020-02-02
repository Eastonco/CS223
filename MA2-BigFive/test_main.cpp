/*
 *  Test suite for Big Five Linked List project
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

#include "LinkedList.h"
#include "ListNode.h"

#include "tests/test_starter.h"
#include "tests/test_base.h"
#include "tests/test_btests.h"
#include "tests/test_atests.h"

#include <sstream>      // stringstream stream buffer

// Main only sets up the Google gtest system and runs the tests
// Any Functions called "TEST" will be run
// These tests are all kept in the tests/ directory
//  -- See the #include "tests/*" above
int main(int argc, char* argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

    // Notes
    //ASSERT_EQ(true, true);
    //ASSERT_THAT(result, ElementsAre(2,5,7,3,6));
    //ASSERT_THAT(result, ElementsAreArray(vals));
    // ASSERT_THROW(statement, exception_type);
    // ASSERT_ANY_THROW(statement);
    // ASSERT_NO_THROW(statement);
