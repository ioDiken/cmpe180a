/**
 * @file hw2_distance.h
 * @brief Compute distance between 2D points
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#ifndef AEF5B24D_8526_45AF_9268_AB6EA1CBA064
#define AEF5B24D_8526_45AF_9268_AB6EA1CBA064

#include <float.h>
#include <stdint.h>

class XYPoint {
public:
    int x;
    int y;

    XYPoint(int xc, int yc) : x(xc), y(yc) {}
    ~XYPoint() = default;

};

float distance(XYPoint p1, XYPoint p2);
float distance(XYPoint p1, XYPoint p2, XYPoint p3);
float distance(XYPoint p1, XYPoint p2, XYPoint p3, XYPoint p4);
float distance(XYPoint p1, XYPoint p2, XYPoint p3, XYPoint p4, XYPoint p5);

#endif /* AEF5B24D_8526_45AF_9268_AB6EA1CBA064 */
