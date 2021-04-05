/**
 * @file BigInt.cc
 * @brief Integer Class of "Unlimited" Size
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "BigInt.h"

#include <iostream>

#define _DEBUG_

#define INVALID_NUM (0xFF)

BigInt::BigInt(const std::vector<int> &v)
{
    num.resize(v.size());
    for (uint64_t i = 0; i < v.size(); i++)
    {
        num[i] = v[v.size()-i-1];
    }
}

BigInt::BigInt(const std::vector<char> &v)
{
    num.resize(v.size());
    for (uint64_t i = 0; i < v.size(); i++)
    {
        num[i] = v[v.size()-i-1]-'0';
    }
}

BigInt::BigInt(const char *c, uint64_t len)
{
    num.resize(len);
    for (int i = 0; i < len; i++)
    {
        num[i] = c[len-i-1]-'0';
    }
}


bool operator==(const BigInt& b1, const BigInt& b2)
{
    bool ret_val = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : INVALID_NUM;
        num2 = (b2.num.size() > i) ? b2.num[i] : INVALID_NUM;

        if (num1 == num2)
        {
            continue;
        }

        // one DNE, the other is 0
        else if ((num1 ^ num2) == INVALID_NUM)
        {
            continue;
        }
        
        else
        {
            ret_val = false;
            break;
        }
    }

    return ret_val;
}



std::ostream& operator<<(std::ostream& os, const BigInt& bi)
{
    uint64_t s = bi.num.size();
    for (uint64_t i = 0; i < s; i++)
    {
        // not entirely sure why the +0 is required..
        os << bi.num[s-i-1]+0;
    }

    return os;
}