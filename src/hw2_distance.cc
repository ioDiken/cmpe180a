/**
 * @file hw2_distance.cc
 * @brief Compute distance between 2D points
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "hw2_distance.h"

#include <float.h>
#include <math.h>


float distance(XYPoint p1, XYPoint p2)
{
    return sqrt((pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

float distance(XYPoint p1, XYPoint p2, XYPoint p3)
{
    return distance(p1,p2) + distance(p2,p3);
}

float distance(XYPoint p1, XYPoint p2, XYPoint p3, XYPoint p4)
{
    return distance(p1,p2) + distance(p2,p3,p4);
}

float distance(XYPoint p1, XYPoint p2, XYPoint p3, XYPoint p4, XYPoint p5)
{
    return distance(p1,p2) + distance(p2,p3,p4,p5);
}

bool XYPoint::operator<(const XYPoint &p)
{
    XYPoint p0 = XYPoint(0,0);

    float d1 = distance(p0,*this);
    float d2 = distance(p0,p);

    return (d1 < d2) ? true : false;
}

XYPoint XYPoint::operator+(const XYPoint &p)
{
    return XYPoint(this->x+p.x,this->y+p.y);
}
