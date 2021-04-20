/**
 * @file ShapeSorter.cc
 * @brief Sort shapes by their respective areas
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "ShapeSorter.h"

void ShapeSorter(std::vector<Shape *> &shapes)
{
    Shape *tmp = NULL;

    for (int i = 0; i < shapes.size(); i++)
    {
        for (int j = i+1; j < shapes.size(); j++)
        {
            if (shapes[i]->area() > shapes[j]->area())
            {
                tmp = shapes[i];
                shapes[i] = shapes[j];
                shapes[j] = tmp;
            }
        }
    }
}