/**
 * @file hw3_concat.cc
 * @brief Concatenate 2 strings
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "hw3_concat.h"

#include <string>
#include <iostream>

// wow this is real tough
std::string mergeStrings(const std::string &a, const std::string &b)
{
    std::string s;
    std::string tmp_a,tmp_b;
    
    if (a.length())
    {
        s += a[0];
        tmp_a = a.substr(1);
    }
    if (b.length())
    {
        s += b[0];
        tmp_b = b.substr(1);
    }

    // if both strings are empty
    if (!(a.length() | b.length()))
    {
        return s;
    }
    else
    {
        return s+mergeStrings(tmp_a,tmp_b);
    }
}