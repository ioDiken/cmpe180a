/**
 * @file asteroid.h
 * @author Nicolas Diken (011280893)
 * @brief Asteroid hit counter
 */

#ifndef CCB9B6CE_4C66_409C_BF2D_D9462B63153A
#define CCB9B6CE_4C66_409C_BF2D_D9462B63153A

#include <stdint.h>
#include <vector>

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

int countHits(std::vector<Asteroid> a);


#endif /* CCB9B6CE_4C66_409C_BF2D_D9462B63153A */
