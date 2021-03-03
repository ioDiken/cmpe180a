/**
 * @file hw4_tests.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Test & see if input vectors are sorted
 * @date 2020-07-20
 */
 
#include <gtest/gtest.h> // googletest header file

#include "global.h"
#include <iostream>
#include "hw4_merge_and_sort.h"

class HW4 : public ::testing::Test
{
public:
    std::vector<int> v,v1,v2; 

protected:
    
    virtual void SetUp()
    {
        v.clear();
        v1.clear();
        v2.clear();
    }

    virtual void TearDown()
    {
    }
};

TEST_F(HW4, zero_size)
{
    v = mergeAndSort(v1,v2);
    EXPECT_TRUE(v.empty());
}

TEST_F(HW4, one_empty)
{
    v1.push_back(5);

    v = mergeAndSort(v1,v2);

    EXPECT_EQ(v.size(), 1);

    EXPECT_EQ(v[0], 5) << "Vector not eq";
}

TEST_F(HW4, two_vectors)
{
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    for (int i = 5; i < 10; i++)
    {
        v2.push_back(i);
    }

    v = mergeAndSort(v2,v1);

    EXPECT_EQ(v.size(), 10);

    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(v[i], i) << "Vector not sorted";
    }
}
