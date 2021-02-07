/**
 * @file global.h
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @brief 
 * @date 2020-07-16
 */

#include <stdlib.h>
#include <iostream>

#ifndef A0A9ECC1_3A79_4D60_99E2_5C2C22D6C056
#define A0A9ECC1_3A79_4D60_99E2_5C2C22D6C056

// remove any debug print statements
#define DEBUG_
#ifdef DEBUG_
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define DEBUG_START_FUNC() DEBUG("\nBeginning %s\n", __func__)

/**
 * @brief check malloc pass, throw std::bad_alloc
 * 
 * @param var pointer to be checked
 * @param str string to print prior to throwing error
 */
inline void check_malloc(void *var, const char *str)
{
    if (var == NULL)
    {
        printf("%s", str);
        throw std::bad_alloc();
    }
}

#endif /* A0A9ECC1_3A79_4D60_99E2_5C2C22D6C056 */
