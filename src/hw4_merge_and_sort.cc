/**
 * @file hw4_merge_and_sort.cc
 * @brief Merge & Sort 2 Vectors
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "hw4_merge_and_sort.h"

#include <algorithm> // std::sort

#include <iostream>

std::vector<int> mergeAndSort(const std::vector<int> &a, const std::vector<int> &b)
{
    std::vector<int> v;

    // insert both vectors
    v.insert(v.end(), a.begin(), a.end());
    v.insert(v.end(), b.begin(), b.end());

    std::sort(v.begin(),v.end());

    return v;
}