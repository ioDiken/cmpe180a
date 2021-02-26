/**
 * @file main.cpp
 */

#include <stdint.h>
#include <iostream>

#include "hw2_distance.h"

int main(int argc, char *argv[])
{
    XYPoint p1(0,0);
    XYPoint p2(1,1);

    std::cout << distance(p1,p2);

    return 0;
}