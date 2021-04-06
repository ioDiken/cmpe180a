/**
 * @file hw7_tests.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Test & see if BigInt functions as expected
 */
 
#include <gtest/gtest.h> // googletest header file

#include <iostream>
#include <string.h>
#include "global.h"
#include "BigInt.h"

class HW7 : public ::testing::Test
{
public:
    std::vector<int> vi;
    std::vector<char> vc;
    char ca[50];

protected:
    
    virtual void SetUp()
    {
        vi.clear();
        vc.clear();
        (void) memset(ca, 0, sizeof(ca));
    }

    virtual void TearDown()
    {
    }
};

TEST_F(HW7, print)
{
    vi.push_back(2);
    vi.push_back(0);
    BigInt bi(vi);
    std::cout << "Bi: " << bi << std::endl;

    vc.push_back('0');
    vc.push_back('2');
    vc.push_back('0');
    BigInt bc(vc);
    std::cout << "Bc: " << bc << std::endl;

    ca[0] = '2';
    ca[1] = '0';
    BigInt ba(ca, 2);
    std::cout << "Ba: " << ba << std::endl;
}

TEST_F(HW7, eq)
{
    vi.push_back(2);
    vi.push_back(0);
    BigInt bi(vi);
    vc.push_back('2');
    vc.push_back('0');
    BigInt bc(vc);
    ca[0] = '0';
    ca[1] = '2';
    ca[2] = '0';
    BigInt ba(ca, 3);

    EXPECT_TRUE(bi == bc);
    EXPECT_TRUE(bi == ba);
    EXPECT_TRUE(bc == ba);
}

TEST_F(HW7, gt_eq)
{
    vi.push_back(2);
    vi.push_back(0);
    BigInt bi(vi);
    vc.push_back('2');
    vc.push_back('0');
    BigInt bc(vc);
    ca[0] = '0';
    ca[1] = '2';
    ca[2] = '1';
    BigInt ba(ca, 3);

    EXPECT_TRUE(bi >= bc);
    EXPECT_TRUE(ba >= bi);
    EXPECT_FALSE(bi >= ba);
}

TEST_F(HW7, lt_eq)
{
    vi.push_back(2);
    vi.push_back(0);
    BigInt bi(vi);
    vc.push_back('2');
    vc.push_back('0');
    BigInt bc(vc);
    ca[0] = '0';
    ca[1] = '2';
    ca[2] = '1';
    BigInt ba(ca, 3);

    EXPECT_TRUE(bi <= bc);
    EXPECT_FALSE(ba <= bi);
    EXPECT_TRUE(bi <= ba);
}

TEST_F(HW7, multiply)
{
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    vi.push_back(1);
    BigInt ba(vi);
    vi.clear();
    vi.push_back(1);
    vi.push_back(8);
    vi.push_back(4);
    BigInt bb(vi);

    std::cout << ba << std::endl;
    std::cout << bb << std::endl;
    BigInt b = ba*bb;
    std::cout << b << std::endl;

    // EXPECT_TRUE(bc == (ba * bb));
}