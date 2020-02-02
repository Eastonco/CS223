/*
 *
 */

#include "helloworld.h"
#include <gtest/gtest.h>

#include <sstream>      // stringstream stream buffer

TEST(HelloWorldTest, OutputContent)
{
    std::stringstream ss;   // Buffer to store stream
    print_hello_world(ss);  // Call function with output going to ss
    ASSERT_EQ(ss.str(), "Hello World!\n"); // -- Note endl is \n in Unix
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
