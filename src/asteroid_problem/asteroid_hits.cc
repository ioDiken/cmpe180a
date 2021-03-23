/**
 * @file asteroid.cc
 * @author Nicolas Diken (011280893)
 * @brief Asteroid hit counter
 */

#include <stdbool.h>
#include <stdint.h>
#include <vector>
#include <list>

#include "asteroid_hits.h"

/**
 * @brief Simple function to count the number of hits to a space station.
 *        The station is assumed to be on the right, and any asteroid that
 *        continues right will hit it.
 * 
 * @param a Vector of asteroids
 *  
 * @return int The number of asteroids that hit the space station
 */
int countHits(std::vector<Asteroid> a)
{
    int count = 0;
    std::list<Asteroid> ast;
    int m = 0;

    for (int i = a.size()-1; i >= 0 ; i--)
    {
        // if any negatives fail out
        if (0 > a[i].m)
        {
            count = -1;
            break;
        }

        // skip entry if mass is 0
        if (0 == a[i].m)
        {
            continue;
        }

        // if there are any asteroids moving left, check front
        if (right == a[i].d)
        {
            // Guaranteed hit
            if (ast.empty())
            {
                count++;
            }

            // run through asteroid list
            else
            {
                while (1)
                {
                    m = a[i].m - ast.front().m;

                    // left-asteroid is destroyed
                    if (m > 0)
                    {
                        ast.pop_front();

                        // right-asteroid has won
                        if (ast.empty())
                        {
                            count++;
                            break;
                        }
                    }

                    // Both asteroids are destroyed
                    else if (m == 0)
                    {
                        ast.pop_front();
                        break;
                    }

                    // right-asteroid is destroyed
                    else
                    {
                        break;
                    }
                }
            }
        }

        // add to left
        else
        {
            ast.push_front(a[i]);
        }
    }

    return count;
}