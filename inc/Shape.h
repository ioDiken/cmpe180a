/**
 * @file Shape.h
 * @brief Shape Classes
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#ifndef Shape_h
#define Shape_h

#include "XYPoint.h"

class Shape
{
public:
    virtual double area() = 0;
};

class Circle : public Shape
{
public:
    Circle(const XYPoint& c, double r) : centre(c), radius(r){}

    double area();

private:
    XYPoint centre;
    double radius;
};

class Triangle : public Shape
{
public:
    Triangle(const XYPoint& x, const XYPoint& y, const XYPoint& z) : a(x), b(y), c(z){}

    double area();

private:
    XYPoint a;
    XYPoint b;
    XYPoint c;
};

class Rectangle : public Shape
{
public:
    Rectangle(const XYPoint& w, const XYPoint& x, const XYPoint& y, const XYPoint& z) : a(w), b(x), c(y), d(z)
    {}
        
    double area();

private:
    XYPoint a;
    XYPoint b;
    XYPoint c;
    XYPoint d;
};

#endif