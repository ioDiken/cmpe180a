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
    }

    virtual void TearDown()
    {
    }
};

TEST_F(HW3, different_chars)
{
    s1 = "abc";
    s2 = "12&@";

    EXPECT_TRUE(mergeStrings(s1,s2) == "a1b2c&@") << "Wow how did you fuck this up";
}

TEST_F(HW3, one_blank)
{
    s1 = "";
    s2 = "def";
    EXPECT_TRUE(mergeStrings(s1,s2) == "def") << "Wow how did you fuck this up";
}
