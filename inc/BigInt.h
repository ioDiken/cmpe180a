/**
 * @file BigInt.h
 * @brief Integer Class of "Unlimited" Size
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#ifndef E155A08A_1457_45E1_BCCB_43DA54FD7470
#define E155A08A_1457_45E1_BCCB_43DA54FD7470

#include <stdint.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <ostream>

class BigInt
{
public:
    BigInt(const std::vector<int> &v);
    BigInt(const std::vector<int> &v, bool lsb_first);
    BigInt(const std::vector<char> &v);
    BigInt(const char *c, uint64_t len);
    ~BigInt() = default;

    BigInt& operator++(); // prefix
    BigInt operator++(int); // postfix
    BigInt& operator--(); // prefix
    BigInt operator--(int); // postfix
    
    friend bool operator==(const BigInt& b1, const BigInt& b2);
    friend bool operator>=(const BigInt& b1, const BigInt& b2);
    friend bool operator<=(const BigInt& b1, const BigInt& b2);
    friend BigInt operator*(const BigInt& b1, const BigInt& b2);
    friend std::ostream& operator<<(std::ostream& os, const BigInt& dt);

private:

    // stored in reverse order. LSB is index 0
    // stored as Decimal values
    std::vector<uint8_t> num;
    bool is_num_neg;

};

/**
+
-
*
!
>=
>
<=
<
++ (pre/post)
-- (pre/post)
>>
*/

#endif /* E155A08A_1457_45E1_BCCB_43DA54FD7470 */
