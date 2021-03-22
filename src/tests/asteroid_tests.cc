/**
 * @file asteroid_tests.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Ensure 
 */
 
#include <gtest/gtest.h> // googletest header file

#include "global.h"
#include <iostream>
#include "asteroid.h"

class ASTERIOD : public ::testing::Test
{
public:
    std::vector<Asteroid> ast_v;
    struct Asteroid a;

protected:
    
    virtual void SetUp()
    {
        ast_v.clear();
    }

    virtual void TearDown()
    {
    }

    void push_ast(int m, Direction d)
    {
        struct Asteroid ass;
        ass.m = m;
        ass.d = d;
        ast_v.push_back(ass);
    }
};

TEST_F(ASTERIOD, empty)
{
    EXPECT_EQ(0,countHits(ast_v));
}

TEST_F(ASTERIOD, all_right)
{
    push_ast(5,right);
    
    EXPECT_EQ(1,countHits(ast_v)) << "One hit";

    push_ast(5,right);

    EXPECT_EQ(2,countHits(ast_v)) << "Two hit";
}

TEST_F(ASTERIOD, vaporized)
{
    push_ast(5,right);
    push_ast(5,left);
    
    EXPECT_EQ(0,countHits(ast_v)) << "One-One";

    push_ast(5,right);
    push_ast(5,left);

    EXPECT_EQ(0,countHits(ast_v)) << "Two-Two";

    push_ast(5,right);
    push_ast(5,left);

    EXPECT_EQ(0,countHits(ast_v)) << "Three-Three";
}

TEST_F(ASTERIOD, late_carry)
{
    push_ast(5,right);
    for (int i = 1; i < 6; i++)
        push_ast(i,left);
    
    EXPECT_EQ(0,countHits(ast_v)) << "Right vaporized after destroying all others";

    ast_v.clear();
    push_ast(5,right);
    for (int i = 1; i < 4; i++)
        push_ast(i,left);

    EXPECT_EQ(1,countHits(ast_v)) << "Right push through";

    ast_v.clear();
    push_ast(5,right);
    push_ast(4,left);
    push_ast(4,right);
    for (int i = 1; i < 5; i++)
        push_ast(i,left);

    EXPECT_EQ(1,countHits(ast_v)) << "Big right push through";
}