/**
 * @file XYPoint.h
 * @brief Simple XY Point class
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#pragma once

class XYPoint
{
public:
    XYPoint(int xc, int yc) : x(xc), y(yc) {}
    int x;
    int y;
};