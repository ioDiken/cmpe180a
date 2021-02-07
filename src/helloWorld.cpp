/**
 * @file helloWorld.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Simple test to ensure "hello world" is printed
 * @date 2020-07-20
 */
 
#include <gtest/gtest.h> // googletest header file

#include "global.h"
#include <iostream>

class HW0 : public ::testing::Test
{
private:

protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(HW0, empty)
{
    std::cout << "Hello World!" << std::endl;

    // // remove 1 from q
    // ret_entry = q->deq();
    // ASSERT_TRUE(ret_entry != FAILED_DEQ) << "F when dequeue" << std::endl;
}