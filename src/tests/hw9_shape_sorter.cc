/**
 * @file hw7_tests.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief Test & see if BigInt functions as expected
 */
 
#include <gtest/gtest.h> // googletest header file

#include <iostream>
#include <cmath>
#include "global.h"

#include "ShapeSorter.h"

class HW9 : public ::testing::Test
{
public:
    std::vector<Shape *> shapes;

protected:
    
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
        shapes.clear();
    }

    XYPoint point(int x = 0, int y = 0)
    {
        XYPoint p(x,y);
        return p;
    }

    bool areEQ(Shape* s, double b, double EPSILON = 0.01)
    {
        DEBUG("\nareEQ:\nShape=%.2f\nb=%.2f\n",s->area(),b);

        return fabs(s->area()-b) < EPSILON;
    }

    bool areEQ(Shape* s1, Shape* s2, double EPSILON = 0.01)
    {
        DEBUG("\nareEQ:\nShape1=%.2f\nShape2=%.2f\n",s1->area(),s2->area());

        return fabs(s1->area()-s2->area()) < EPSILON;
    }

    void sortAndTest()
    {
        ShapeSorter(shapes);

        Shape *prev;
        prev = shapes[0];

        for (int i = 0; i < shapes.size(); i++)
        {
            EXPECT_LE(prev->area(), shapes[i]->area());
            prev = shapes[i];
        }
    }
};

TEST_F(HW9, circles)
{
    Circle c1(point(0,0), 10);
    EXPECT_TRUE(areEQ(&c1, 314.159));

    Circle c2(point(34123,9999), 1275.3854);
    EXPECT_TRUE(areEQ(&c2, 5110139.487));

    Circle c3(point(), 3);
    Circle c4(point(), 4);
    Circle c5(point(), 5);
    Circle c6(point(), 6);
    Circle c7(point(), 7);

    shapes.push_back(&c1);
    shapes.push_back(&c7);
    shapes.push_back(&c4);
    shapes.push_back(&c2);
    shapes.push_back(&c3);
    shapes.push_back(&c6);
    shapes.push_back(&c5);

    sortAndTest();
}

TEST_F(HW9, triangles)
{
    Triangle t1(point(), point(4,0), point(0,3));
    EXPECT_TRUE(areEQ(&t1, 6));

    Triangle t2(point(23,48), point(0,32), point(45,2));
    EXPECT_TRUE(areEQ(&t2, 705));

    Triangle t3(point(378,473), point(471,274), point(385,257));
    Triangle t4(point(27478,4728), point(45723,29452), point(5893,9853));
    Triangle t5(point(23,1), point(58,21), point(13,96));
    Triangle t6(point(19,374), point(480,12), point(43,477));
    Triangle t7(point(), point(0,1), point(1,0));

    shapes.push_back(&t1);
    shapes.push_back(&t2);
    shapes.push_back(&t3);
    shapes.push_back(&t4);
    shapes.push_back(&t5);
    shapes.push_back(&t6);
    shapes.push_back(&t7);

    sortAndTest();
}

TEST_F(HW9, rectangles)
{
    Rectangle r1(point(), point(4,0), point(4,4), point(0,4));
    EXPECT_TRUE(areEQ(&r1, 16));

    Rectangle r2(point(), point(0,32), point(18,24), point(45,2));
    EXPECT_TRUE(areEQ(&r2, 810));

    Rectangle r3(point(378,473), point(471,274), point(153,21), point(0,485));
    Rectangle r4(point(), point(27478,4728), point(45723,29452), point(20384,9853));
    Rectangle r5(point(-2,4), point(-2,12), point(4,12), point(4,4));

    shapes.push_back(&r1);
    shapes.push_back(&r2);
    shapes.push_back(&r3);
    shapes.push_back(&r4);
    shapes.push_back(&r5);

    sortAndTest();
}

TEST_F(HW9, mixed_shapes)
{
    Circle c1(point(0,0), 2);
    EXPECT_TRUE(areEQ(&c1, 12.566));

    Triangle t1(point(), point(4,0), point(0,3));
    EXPECT_TRUE(areEQ(&t1, 6));

    Rectangle r1(point(), point(4,0), point(4,4), point(0,4));
    EXPECT_TRUE(areEQ(&r1, 16));

    shapes.push_back(&c1);
    shapes.push_back(&r1);
    shapes.push_back(&t1);

    sortAndTest();
}
