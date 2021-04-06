/**
 * @file BigInt.cc
 * @brief Integer Class of "Unlimited" Size
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

// Everything needs to be reworked for negative numbers
// use special char (ie 0xFE) for negative representation

#include "BigInt.h"


#define _DEBUG_

#ifdef _DEBUG_
    #include <iostream>
    #include <stdio.h>
#endif

#define INVALID_NUM (0xFF)

void remove_trailing_zeros(std::vector<uint8_t> &num)
{
    uint64_t i;
    for (i = 0; i < num.size(); i++)
    {
        if (num[num.size()-i-1] != 0)
        {
            break;
        }
    }
    num.resize(num.size()-i);
}

BigInt::BigInt(const std::vector<int> &v)
{
    num.resize(v.size());
    for (uint64_t i = 0; i < v.size(); i++)
    {
        num[i] = v[v.size()-i-1];
    }

    remove_trailing_zeros(num);    
}

// Fake constructor utilized for internal usage.
BigInt::BigInt(const std::vector<int> &v, bool lsb_first)
{
    if (lsb_first == true)
    {
        num.reserve(v.size());
        for (auto i : v)
        {
            num.push_back(i);
        }
    }
    else
    {
        num.resize(v.size());
        for (uint64_t i = 0; i < v.size(); i++)
        {
            num[i] = v[v.size()-i-1];
        }
    }

    remove_trailing_zeros(num);
}

BigInt::BigInt(const std::vector<char> &v)
{
    num.resize(v.size());
    for (uint64_t i = 0; i < v.size(); i++)
    {
        num[i] = v[v.size()-i-1]-'0';
    }

    remove_trailing_zeros(num);
}

BigInt::BigInt(const char *c, uint64_t len)
{
    num.resize(len);
    for (int i = 0; i < len; i++)
    {
        num[i] = c[len-i-1]-'0';
    }

    remove_trailing_zeros(num);
}


// -----------------------------------------------------------------------------
// Friend Functions

bool operator==(const BigInt& b1, const BigInt& b2)
{
    bool eq = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0u; i < len; i++)
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
            eq = false;
            break;
        }
    }

    return eq;
}

bool operator>=(const BigInt& b1, const BigInt& b2)
{
    bool gt_eq = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0u; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : INVALID_NUM;
        num2 = (b2.num.size() > i) ? b2.num[i] : INVALID_NUM;

        if ((num1 == num2)
            || ((num1 ^ num2) == INVALID_NUM))
        {
            continue;
        }

        else if (num1 > num2)
        {
            gt_eq = true;
        }

        else if (num1 < num2)
        {
            gt_eq = false;
        }
    }

    return gt_eq;
}

bool operator<=(const BigInt& b1, const BigInt& b2)
{
    bool gt_eq = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0u; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : INVALID_NUM;
        num2 = (b2.num.size() > i) ? b2.num[i] : INVALID_NUM;

        if ((num1 == num2)
            || ((num1 ^ num2) == INVALID_NUM))
        {
            continue;
        }

        else if (num1 < num2)
        {
            gt_eq = true;
        }

        else if (num1 > num2)
        {
            gt_eq = false;
        }
    }

    return gt_eq;
}

// still more to be modified here
// BigInt operator+(const BigInt& b1, const BigInt& b2)
// {
//     std::vector<int> v;
//     uint8_t carry = 0u;
//     uint8_t hold = 0u;
//     uint8_t num1, num2;

//     uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();
//     v.resize(len+1);
//     // set MSB
//     v[0] = 0;

//     for (uint64_t i = 0u; i < len; i++)
//     {
//         num1 = (b1.num.size() > i) ? b1.num[i] : 1;
//         num2 = (b2.num.size() > i) ? b2.num[i] : 1;

// #ifdef _DEBUG_
//         printf("\nNum1: %d\nNum2: %d\n", num1, num2);
// #endif

//         // if both 0, use carry
//         if ((num1 | num2) == 0x0)
//         {
//             v[len-i] = carry;
//             carry = 0;
//             continue;
//         }

//         // if either one is a 0 set it to 1
//         if (num1 == 0)
//         {
//             num1 = 1;
//         }
//         else if (num2 == 0)
//         {
//             num2 = 1;
//         }

//         if (carry)
//         {
//             hold = (((num1 * num2) % 10) + carry) % 10;
//             carry = ((num1 * num2) + carry) / 10;
//         }
//         else
//         {
//             hold = (num1 * num2) % 10;
//             carry = (num1 * num2) / 10;
//         }

//         v[len-i] = hold;
//     }

//     return BigInt(v);
// }

BigInt operator*(const BigInt& b1, const BigInt& b2)
{
    std::vector<int> v;
    v.resize(b1.num.size() + b2.num.size()+1, 0);
    
    uint8_t carry = 0u,
            hold = 0u;

    const BigInt& bL = (b1.num.size() >= b2.num.size()) ? b1 : b2,
                  bS = (b1.num.size() >= b2.num.size()) ? b2 : b1;

    uint64_t blen = bL.num.size(),
             slen = bS.num.size(),
             i, j;

    for (i = 0u; i < slen; i++)
    {
        carry = 0u;
        for (j = 0u; j < blen; j++)
        {
            // if both 0, use carry
            if ((bL.num[j] | bS.num[i]) == 0x0)
            {
                hold = carry;
                carry = 0u;
            }
            else
            {
                hold = ((bL.num[j] * bS.num[i]) + carry) % 10;
                carry = ((bL.num[j] * bS.num[i]) + carry) / 10;
            }

            // previous value already exists
            if (v[j+i] != 0)
            {
                carry = carry + ((hold + v[j+i]) / 10);
                hold = (hold + v[j+i]) % 10;
            }

            v[j+i] = hold;
        }

        // Include extra carry if exists
        v[j+i] = carry;
    }

    return BigInt(v, true);
}


std::ostream& operator<<(std::ostream& os, const BigInt& bi)
{
    uint64_t s = bi.num.size();
    for (uint64_t i = 0u; i < s; i++)
    {
        // not entirely sure why the +0 is required..
        os << bi.num[s-i-1]+0;
    }

    return os;
}