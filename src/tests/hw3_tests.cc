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

TEST_F(HW3, different_chars_2)
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

TEST_F(HW3, one_off_v)
{
    vector<string> v = {"abc","AB","123"};

    EXPECT_TRUE(mergeStrings(v) == "aA1bB2c3") << "Wow how did you fuck this up";
}

TEST_F(HW3, one_empty_v)
{
    vector<string> v = {"abc","","123"};

    EXPECT_TRUE(mergeStrings(v) == "a1b2c3") << "Wow how did you fuck this up";
}

TEST_F(HW3, two_empty_v)
{
    vector<string> v = {"","","123"};

    EXPECT_TRUE(mergeStrings(v) == "123") << "Wow how did you fuck this up";
}