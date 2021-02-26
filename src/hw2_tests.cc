/**
 * @file helloWorld.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Simple test to ensure "hello world" is printed
 * @date 2020-07-20
 */
 
#include <gtest/gtest.h> // googletest header file

#include "global.h"
#include <iostream>
#include "hw2_distance.h"

#define DISTANCE_1 4
#define DISTANCE_2 3
#define DISTANCE_3 7
#define DISTANCE_4 1

class HW2 : public ::testing::Test
{
public:
    XYPoint *p1,*p2,*p3,*p4,*p5;

protected:
    
    virtual void SetUp()
    {
        p1 = new XYPoint(0,0);
        p2 = new XYPoint(0,DISTANCE_1);
        p3 = new XYPoint(DISTANCE_2,DISTANCE_1);
        p4 = new XYPoint(DISTANCE_2,DISTANCE_1+DISTANCE_3);
        p5 = new XYPoint(DISTANCE_2+DISTANCE_4,DISTANCE_1+DISTANCE_3);
    }

    virtual void TearDown()
    {
    }
};

TEST_F(HW2, test_2_points)
{
    EXPECT_TRUE(distance(*p1,*p2) == DISTANCE_1) << "Distance between p1,p2 is incorrect";
}

TEST_F(HW2, test_3_points)
{
    EXPECT_TRUE(distance(*p1,*p2,*p3) == (DISTANCE_1+DISTANCE_2)) << "Distance between p1,p2,p3 is incorrect";
}

TEST_F(HW2, test_4_points)
{
    EXPECT_TRUE(distance(*p1,*p2,*p3,*p4) == (DISTANCE_1+DISTANCE_2+DISTANCE_3)) << "Distance between p1,p2,p3,p4 is incorrect";
}

TEST_F(HW2, test_5_points)
{
    EXPECT_TRUE(distance(*p1,*p2,*p3,*p4,*p5) == (DISTANCE_1+DISTANCE_2+DISTANCE_3+DISTANCE_4)) << "Distance between p1,p2,p3,p4,p5 is incorrect";
}