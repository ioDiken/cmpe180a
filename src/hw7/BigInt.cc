/**
 * @file BigInt.cc
 * @brief Integer Class of "Unlimited" Size
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

// Everything needs to be reworked for negative numbers
// use special char (ie 0xFE) for negative representation

#include "BigInt.h"
#include <type_traits>


#define _DEBUG_

#ifdef _DEBUG_
    #include <iostream>
    #include <stdio.h>
#endif

#define INVALID_NUM (0xFF)
#define NEGATIVE_CHAR ('-')

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

    // ensure if a number is 0, it keeps one digit
    num.resize((i == num.size()) ? num.size()-i+1 : num.size()-i);
}

// /**
//  * @brief Check that a vector valid &| if it is negative
//  * 
//  * @return int8_t   -1 if vector is invalid
//  *                  0 if vector is positive
//  *                  N if vector is negative, where N represents
//  *                  the number of entries until the negative value
//  */
// template<typename T>
// int8_t check_vector(const std::vector<T> &v, bool lsb_first)
// {
//     int8_t ret_val = 0;
//     T e;
//     bool first_entry = true;
//     bool is_neg, is_invalid;
//     bool is_zero;

//     for (uint64_t i = 0u; i < v.size(); i++)
//     {
//         e = v[(lsb_first) ? v.size()-i-1 : i];

//         // check if negative for int template
//         if (std::is_same<T, int>::value)
//         {
//             is_neg = ((e == NEGATIVE_CHAR) || (e < -1)) ? true : false;
//             is_invalid = ((e > 9) || (e < -9)) ? true : false;
//         }
//         // check if negative for char template
//         else
//         {
//             is_neg = (e == NEGATIVE_CHAR) ? true : false;
//             is_invalid = ((e > '9') || (e < '0')) ? true : false;
//         }

//         // return i+1 so that we know how many entries to pop
//         if (first_entry && is_neg)
//         {
//             ret_val = i+1;
//         }

//         if ((!first_entry && is_neg) || is_invalid)
//         {
//             return_val = -1;
//             break;
//         }
//         // not a leading 0 anymore
//         else if ((e != '0') && (e != 0))
//         {
//             first_entry = false;
//         }
//     }

//     return return_val;
// }

BigInt::BigInt(const std::vector<int> &v)
{
    num.resize(v.size()+1,0);
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
        num.reserve(v.size()+1);
        for (auto i : v)
        {
            num.push_back(i);
        }
    }
    else
    {
        num.resize(v.size()+1,0);
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
// Public Functions

BigInt& BigInt::operator++()
{
    uint8_t carry = 0u;
    uint8_t hold = 0u;
    uint8_t num1, num2;
    uint64_t i;
    std::vector<int> welp;
    welp.push_back(1);

    for (i = 0u; i < this->num.size(); i++)
    {
        num1 = (this->num.size() > i) ? this->num[i] : 0;
        num2 = (welp.size() > i) ? welp[i] : 0;

        // if both 0, use carry
        if ((num1 | num2) == 0x0)
        {
            num[i] = carry;
            carry = 0;
            continue;
        }

        if (carry)
        {
            hold = (((num1 + num2) % 10) + carry) % 10;
            carry = ((num1 + num2) + carry) / 10;
        }
        else
        {
            hold = (num1 + num2) % 10;
            carry = (num1 + num2) / 10;
        }

        this->num[i] = hold;
    }

    if (carry != 0)
    {
        this->num.push_back(carry);
    }

    return *this;
}

BigInt BigInt::operator++(int)
{
    auto b = *this;
    ++*this;
    return b;
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

bool operator>(const BigInt& b1, const BigInt& b2)
{
    bool gt = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0u; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : INVALID_NUM;
        num2 = (b2.num.size() > i) ? b2.num[i] : INVALID_NUM;

        if ((num1 ^ num2) == INVALID_NUM)
        {
            continue;
        }

        else if (num1 > num2)
        {
            gt = true;
        }

        else if (num1 < num2)
        {
            gt = false;
        }
    }

    return gt;
}

bool operator<=(const BigInt& b1, const BigInt& b2)
{
    bool lt_eq = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0u; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : 0;
        num2 = (b2.num.size() > i) ? b2.num[i] : 0;

        if ((num1 == num2)
        {
            continue;
        }

        else if (num1 < num2)
        {
            lt_eq = true;
        }

        else if (num1 > num2)
        {
            lt_eq = false;
        }
    }

    return lt_eq;
}

bool operator<(const BigInt& b1, const BigInt& b2)
{
    bool lt = true;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();

    uint8_t num1, num2;
    for (uint64_t i = 0u; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : INVALID_NUM;
        num2 = (b2.num.size() > i) ? b2.num[i] : INVALID_NUM;

        if ((num1 ^ num2) == INVALID_NUM)
        {
            continue;
        }

        else if (num1 < num2)
        {
            lt = true;
        }

        else if (num1 > num2)
        {
            lt = false;
        }
    }

    return lt;
}

BigInt operator+(const BigInt& b1, const BigInt& b2)
{
    std::vector<int> v;
    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();
    v.resize(len+1, 0);
    uint8_t carry = 0u;
    uint8_t hold = 0u;
    uint8_t num1, num2;
    uint64_t i;

    for (i = 0u; i < len; i++)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : 0;
        num2 = (b2.num.size() > i) ? b2.num[i] : 0;

        // if both 0, use carry
        if ((num1 | num2) == 0x0)
        {
            v[i] = carry;
            carry = 0;
            continue;
        }

        if (carry)
        {
            hold = (((num1 + num2) % 10) + carry) % 10;
            carry = ((num1 + num2) + carry) / 10;
        }
        else
        {
            hold = (num1 + num2) % 10;
            carry = (num1 + num2) / 10;
        }

        v[i] = hold;
    }

    v[i] = carry;

    return BigInt(v, true);
}

BigInt operator-(const BigInt& b1, const BigInt& b2)
{
    std::vector<int> v;
    if (b1 <= b2)
    {
        v.push_back(0);
        return BigInt(v);
    }

    uint64_t len = (b1.num.size() > b2.num.size()) ? b1.num.size() : b2.num.size();
    v.resize(len, 0);
    int8_t borrow = 0u;
    int8_t hold = 0u;
    uint8_t num1, num2;

    for(int i=len-1; i >= 0; --i)
    {
        num1 = (b1.num.size() > i) ? b1.num[i] : 0;
        num2 = (b2.num.size() > i) ? b2.num[i] : 0;

        hold = num1 - num2 - borrow;
        if(hold < 0)
        {
            v[i] = hold + 10;
            borrow = 1;
        } 
        else
        {
            v[i] = hold;
            borrow = 0;
        }
    }

    return BigInt(v);
}

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
        // how to print negative number?
        os << bi.num[s-i-1]+0;
    }

    return os;
}