/**
 * @file hw1_overloading.cpp
 * @author Nicolas Diken (nicolasdiken@ieee.org)
 * @sjsuid 011280893
 * 
 * @brief There isn't much information.. But I'm assuming just show that 
 *        you can overload a function?
 */
 
 #include "hw1_overloading.h"

 #include <stddef.h>
 #include <stdint.h>
 #include <iostream>

/**
 * @brief Validate inputs
 * 
 * @param c         array
 * @param len       array len
 * 
 * @return true     if inputs are valid
 */
static bool validate_input(uint8_t* c, int len)
{
    bool return_val = true;

    if (NULL == c)
    {
        return_val = false;
    }

    if (2 > len)
    {
        return_val = false;
    }

    return return_val;
}

/**
 * @brief Reverse a array of integers
 * 
 * @param a     array of integers
 * @param sz    size of the array
 */
void cmpe180ASort(int a[], int sz)
{
    static int i = 0;
    int tmp = 0;

    // -------------------------------------------------------------------------
    // Input Validation
 
    if (false == validate_input((uint8_t *) a, sz))
    {
        std::cout << "Invalid input parameters!" << std::endl;
        return;
    }

    // -------------------------------------------------------------------------
    // Execution

    if (sz > i)
    {
        tmp = a[i];
        a[i++] = a[sz-1];
        a[sz-1] = tmp;
        cmpe180ASort(a,sz-1);
    }
}

/**
 * @brief Reverse a array of characters
 * 
 * @param a     array of characters
 * @param sz    size of the array
 */
void cmpe180ASort(char c[], int sz)
{
    static int i = 0;
    int tmp = 0;

    // -------------------------------------------------------------------------
    // Input Validation
 
    if (false == validate_input((uint8_t *) c, sz))
    {
        std::cout << "Invalid input parameters!" << std::endl;
        return;
    }

    // -------------------------------------------------------------------------
    // Execution

    if (sz > i)
    {
        tmp = c[i];
        c[i++] = c[sz-1];
        c[sz-1] = tmp;
        cmpe180ASort(c,sz-1);
    }
}