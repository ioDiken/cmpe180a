/**
 * @file helloWorld.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Simple test to see whether two strings were concat correctly
 * @date 2020-07-20
 */
 
#include <gtest/gtest.h> // googletest header file

#include "global.h"
#include <iostream>
#include "hw3_concat.h"

class HW3 : public ::testing::Test
{
public:
    std::string s1,s2;

protected:
    
    virtual void SetUp()
    {
        s1 = "abc";
        s2 = "12&@";
    }

    virtual void TearDown()
    {
    }
};

TEST_F(HW3, different_chars)
{
    EXPECT_TRUE(mergeStrings(s1,s2) == "a1b2c&@") << "Wow how did you fuck this up";
}
