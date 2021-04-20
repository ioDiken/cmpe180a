/**
 * @file Shape.cc
 * @brief Shape Classes
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include <cmath>
#include <vector>

#include "Shape.h"

inline double xy_distance(XYPoint a, XYPoint b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double Circle::area()
{
    return M_PI * pow(radius, 2);
}

double Triangle::area()
{
    // herons formula
    double s1 = xy_distance(a,b),
           s2 = xy_distance(a,c),
           s3 = xy_distance(b,c),
           sp = (s1 + s2 + s3) / 2;

    return sqrt(sp*(sp-s1)*(sp-s2)*(sp-s3));
}

double Rectangle::area()
{
    Triangle t1(a,b,c), t2(a,c,d);

    return t1.area() + t2.area();
}