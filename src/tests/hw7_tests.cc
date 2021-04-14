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

    BigInt create_BI(uint64_t val)
    {
        return create_BI(val,false);
    }

    BigInt create_BI(uint64_t val, bool is_neg)
    {
        std::vector<int> v;

        do
        {
            v.push_back(val % 10);
        } while((val/=10) > 0);

        if (is_neg)
        {
            v.push_back('-');
        }
        else
        {
            v.push_back(0);
        }

        return BigInt(v,true);
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
    EXPECT_TRUE(ba > bi);
    EXPECT_FALSE(bi >= ba);
    EXPECT_FALSE(bi > ba);
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
    EXPECT_FALSE(ba < bi);
    EXPECT_TRUE(bi <= ba);
    EXPECT_TRUE(bi < ba);
}

TEST_F(HW7, multiply)
{
    auto ba = create_BI(12341u);
    auto bb = create_BI(184u);
    auto bc = create_BI(2270744u);
    auto b_zero = create_BI(0);

    EXPECT_TRUE(bc == (ba * bb));

    EXPECT_TRUE(b_zero == (ba * b_zero));
}

TEST_F(HW7, addition)
{
    auto ba = create_BI(999u);
    auto bb = create_BI(999u);
    auto b1k = create_BI(1000u);
    auto bc = create_BI(1998u);
    auto b_zero = create_BI(0);

    EXPECT_TRUE(bc == (ba + bb));
    EXPECT_TRUE(ba == (ba + b_zero));
    EXPECT_TRUE(bb == ba++);
    EXPECT_TRUE(b1k == ba);
    EXPECT_TRUE(++bb == b1k);
}

TEST_F(HW7, subtraction)
{
    auto ba = create_BI(1000u);
    auto bb = create_BI(1u);
    auto bc = create_BI(999u);
    auto b_zero = create_BI(0);

    std::cout << (ba - bb) << std::endl;
    EXPECT_TRUE(bc == (ba - bb));
    EXPECT_TRUE(ba == (ba - b_zero));
    // EXPECT_TRUE(bb == ba++);
    // EXPECT_TRUE(b1k == ba);
    // EXPECT_TRUE(++bb == b1k);
}