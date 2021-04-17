/**
 * @file hw7_tests.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Test & see if BigInt functions as expected
 */
 
#include <gtest/gtest.h> // googletest header file

#include <iostream>
#include <string.h>
#include "global.h"

#include "CircularLinkedList.h"

class HW8 : public ::testing::Test
{
public:
    CircularLinkedList *cll;

protected:
    
    virtual void SetUp()
    {
        cll = new CircularLinkedList();
    }

    virtual void TearDown()
    {
        delete cll;
    }

//  CircularLinkedList circularLinkedList; circularLinkedList.push(1, ClockDirection::ClockWise);    circularLinkedList.push(2, ClockDirection::ClockWise);    circularLinkedList.push(3, ClockDirection::ClockWise);    circularLinkedList.push(4, ClockDirection::ClockWise);    
// // should print 4,1,2,3 (any notation but this order)    
// cout<<circularLinkedList;

// circularLinkedList.pop(ClockDirection::ClockWise);    
// // should print 1,2,3 (any notation but this order)    
// cout<<circularLinkedList;

// circularLinkedList.pop(ClockDirection::CounterClockWise);    
// // should print 3,2 (any notation but this order)    
// cout<<circularLinkedList;

// CircularLinkedList circularLinkedList2;    
// circularLinkedList2.push(1, ClockDirection::ClockWise);    
// circularLinkedList2.push(2, ClockDirection::ClockWise);    
// circularLinkedList2.push(3, ClockDirection::ClockWise);    
// circularLinkedList2.push(4, ClockDirection::ClockWise);    
// circularLinkedList2.push(5, ClockDirection::ClockWise);    
// circularLinkedList2.push(6, ClockDirection::ClockWise);    
// circularLinkedList2.push(7, ClockDirection::ClockWise);    
// circularLinkedList2.push(8, ClockDirection::ClockWise);    

// // should print 8,1,2,3,4,5,6,7 (any notation but this order)    
// cout<<circularLinkedList2;    

// // should print 8 
// cout<<circularLinkedList2.peek()<<endl;

// circularLinkedList2.rotate(4, ClockDirection::ClockWise);
// // should print 4,5,6,7,8,1,2,3 (any notation but this order)
// cout<<circularLinkedList2; 

// circularLinkedList2.rotate(4, ClockDirection::ClockWise);    
// // should print 8,1,2,3,4,5,6,7 (any notation but this order)
};

using namespace std;

TEST_F(HW8, clockwise)
{
    cll->push(1, ClockDirection::ClockWise);
    cll->push(2, ClockDirection::ClockWise);
    cll->push(3, ClockDirection::ClockWise);
    cll->push(4, ClockDirection::ClockWise);

    // should print 4,1,2,3    
    std::cout<< *cll << std::endl;

    EXPECT_EQ(4, cll->peek());
    EXPECT_EQ(4, cll->pop(ClockWise));
    EXPECT_EQ(1, cll->peek());
    EXPECT_EQ(1, cll->pop(ClockWise));
    EXPECT_EQ(2, cll->peek());
    EXPECT_EQ(2, cll->pop(ClockWise));
    EXPECT_EQ(3, cll->peek());
    EXPECT_EQ(3, cll->pop(ClockWise));
    EXPECT_EQ(0, cll->peek());
    EXPECT_EQ(0, cll->pop(ClockWise));

    // shouldnt print anything
    std::cout << *cll << std::endl;

    cll->rotate(2, CounterClockWise);

    // shouldnt print anything
    std::cout << *cll << std::endl;
}

TEST_F(HW8, counter_clockwise)
{
    cll->push(1, CounterClockWise);
    cll->push(2, CounterClockWise);
    cll->push(3, CounterClockWise);
    cll->push(4, CounterClockWise);

    // should print 4,3,2,1
    std::cout << *cll << std::endl;

    EXPECT_EQ(4, cll->peek());
    EXPECT_EQ(4, cll->pop(CounterClockWise));
    EXPECT_EQ(3, cll->peek());
    EXPECT_EQ(3, cll->pop(CounterClockWise));
    EXPECT_EQ(2, cll->peek());
    EXPECT_EQ(2, cll->pop(CounterClockWise));
    EXPECT_EQ(1, cll->peek());
    EXPECT_EQ(1, cll->pop(CounterClockWise));
    EXPECT_EQ(0, cll->peek());
    EXPECT_EQ(0, cll->pop(CounterClockWise));

    // shouldnt print anything
    std::cout << *cll << std::endl;

    cll->push(1, CounterClockWise);
    cll->push(2, CounterClockWise);
    cll->push(3, CounterClockWise);
    cll->push(4, CounterClockWise);

    // cll->rotate(1, CounterClockWise);

    // shouldnt print anything
    std::cout << *cll << std::endl;
}