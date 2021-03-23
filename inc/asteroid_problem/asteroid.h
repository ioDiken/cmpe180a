/**
 * @file asteroid.h
 * @author Nicolas Diken (011280893)
 * @brief Header as provided in class
 */

#ifndef A243AB0C_5C16_4694_9AFB_93D5BB329A3D
#define A243AB0C_5C16_4694_9AFB_93D5BB329A3D

enum Direction 
{
    right = 0,
    left,
};

struct Asteroid 
{
    // Mass
    int m;

    // Right or Left
    Direction d;
};

#endif /* A243AB0C_5C16_4694_9AFB_93D5BB329A3D */
