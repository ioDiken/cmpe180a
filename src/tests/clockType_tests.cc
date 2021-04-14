/**
 * @file hw7_tests.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Test & see if BigInt functions as expected
 */
 
#include <gtest/gtest.h> // googletest header file

#include <iostream>
#include <string.h>
#include "global.h"
#include "clockType.h"

class clockType_tests : public ::testing::Test
{
public:

protected:
    
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(clockType_tests, all_methods)
{
    int hr = 1,
        min = 2,
        sec = 3;

    clockType c(hr,min,sec);
    clockType c_zero;
    clockType c_invalid(100,1,1);

    c.getTime(hr,min,sec);
    EXPECT_EQ(hr,1);
    EXPECT_EQ(min,2);
    EXPECT_EQ(sec,3);

    c_zero.getTime(hr,min,sec);
    EXPECT_EQ(hr,0);
    EXPECT_EQ(min,0);
    EXPECT_EQ(sec,0);

    c_invalid.getTime(hr,min,sec);
    EXPECT_EQ(hr,0);
    EXPECT_EQ(min,0);
    EXPECT_EQ(sec,0);

    c.incrementSeconds();
    c.getTime(hr,min,sec);
    EXPECT_EQ(hr,1);
    EXPECT_EQ(min,2);
    EXPECT_EQ(sec,4);

    c.incrementMinutes();
    c.getTime(hr,min,sec);
    EXPECT_EQ(hr,1);
    EXPECT_EQ(min,3);
    EXPECT_EQ(sec,4);

    c.incrementHours();
    c.getTime(hr,min,sec);
    EXPECT_EQ(hr,2);
    EXPECT_EQ(min,3);
    EXPECT_EQ(sec,4);

    EXPECT_TRUE(c_zero.equalTime(c_invalid));

    c.printTime();
    std::cout << std::endl;
}
