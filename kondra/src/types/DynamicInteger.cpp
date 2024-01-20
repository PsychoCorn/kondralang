#include "../../headers/types/DynamicInteger.hpp"

#define ERR_MSG_DIVISION_BY_ZERO "Division by zero!"
#define ERR_MSG_NEGATIVE_SHIFT_VALUE "Negative shift value!"
#define ERR_MSG_INVALID_STRING_ARG "Invalid string argument!"

namespace kondra
{

    DynamicInteger::DynamicInteger()
    {
        mpz_init(value);
    }

    DynamicInteger::DynamicInteger(const int &intValue)
    {
        mpz_init_set_si(value, intValue);
    }

    DynamicInteger::DynamicInteger(const long long &intValue)
    {
        mpz_init_set_si(value, intValue);
    }

    DynamicInteger::DynamicInteger(const char *strValue, const size_t& radix)
    {
        if (mpz_init_set_str(value, strValue, radix) == -1)
        {
            throw std::invalid_argument(ERR_MSG_INVALID_STRING_ARG);
        }
    }

    DynamicInteger::DynamicInteger(const string &strValue, const size_t& radix)
    {
        if (mpz_init_set_str(value, strValue.c_str(), radix) == -1)
        {
            throw std::invalid_argument(ERR_MSG_INVALID_STRING_ARG);
        }
    }

    DynamicInteger::DynamicInteger(const std::string &strValue, const size_t& radix)
    {
        if (mpz_init_set_str(value, strValue.c_str(), radix) == -1)
        {
            throw std::invalid_argument(ERR_MSG_INVALID_STRING_ARG);
        }
    }

    DynamicInteger::DynamicInteger(const double &floatValue)
    {
        mpz_init_set_si(value, floatValue);
    }

    DynamicInteger::DynamicInteger(const DynamicInteger &dynIntValue)
    {
        mpz_init_set_str(value, dynIntValue.strGetNumber(), 10);
    }

    DynamicInteger::~DynamicInteger()
    {
        mpz_clear(value);
    }

    std::ostream &operator<<(std::ostream &os, const DynamicInteger &obj)
    {
        os << obj.strGetNumber();
        return os;
    }

    char *DynamicInteger::strGetNumber(const size_t &radix) const
    {
        return mpz_get_str(nullptr, radix, value);
    }

    long long DynamicInteger::longLongGetNumber() const
    {
        return mpz_get_si(value);
    }

    unsigned long long DynamicInteger::uLongLongGetNumber() const
    {
        return mpz_get_ui(value);
    }

    double DynamicInteger::doubleGetNumber() const
    {
        return mpz_get_d(value);
    }

    bool DynamicInteger::boolGetNumber() const
    {
        return mpz_cmp_ui(value, 0) != 0;
    }

    DynamicInteger operator+(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        DynamicInteger result;
        mpz_add(result.value, num1.value, num2.value);
        return result;
    }

    DynamicInteger &DynamicInteger::operator=(const DynamicInteger &other)
    {
        mpz_set(this->value, other.value);
        return *this;
    }

    DynamicInteger operator-(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        DynamicInteger result;
        mpz_sub(result.value, num1.value, num2.value);
        return result;
    }

    DynamicInteger operator*(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        DynamicInteger result;
        mpz_mul(result.value, num1.value, num2.value);
        return result;
    }

    DynamicInteger operator/(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        if (num2 == 0)
        {
            throw std::runtime_error(ERR_MSG_DIVISION_BY_ZERO);
        }
        DynamicInteger result;
        mpz_tdiv_q(result.value, num1.value, num2.value);
        return result;
    }

    bool operator<(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return mpz_cmp(num1.value, num2.value) < 0;
    }

    bool operator>(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return mpz_cmp(num1.value, num2.value) > 0;
    }

    bool operator==(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return mpz_cmp(num1.value, num2.value) == 0;
    }

    bool operator!=(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return mpz_cmp(num1.value, num2.value) != 0;
    }

    bool operator<=(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return mpz_cmp(num1.value, num2.value) <= 0;
    }

    bool operator>=(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return mpz_cmp(num1.value, num2.value) >= 0;
    }

    bool DynamicInteger::operator!() const
    {
        return *this == 0;
    }

    DynamicInteger operator%(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        if (num2 == 0)
        {
            throw std::runtime_error(ERR_MSG_DIVISION_BY_ZERO);
        }
        DynamicInteger result;
        mpz_mod(result.value, num1.value, num2.value);
        return result;
    }
    DynamicInteger DynamicInteger::operator-() const
    {
        DynamicInteger result;
        mpz_neg(result.value, this->value);
        return result;
    }

    DynamicInteger DynamicInteger::operator~() const
    {
        DynamicInteger result;
        mpz_t one;
        mpz_init_set_str(one, "1", 10);
        mpz_xor(result.value, value, one);
        mpz_clear(one);
        return -result;
    }

    DynamicInteger operator&(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        DynamicInteger result;
        mpz_and(result.value, num1.value, num2.value);
        return result;
    }

    DynamicInteger operator|(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        DynamicInteger result;
        mpz_ior(result.value, num1.value, num2.value);
        return result;
    }

    DynamicInteger operator^(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        DynamicInteger result;
        mpz_xor(result.value, num1.value, num2.value);
        return result;
    }

    DynamicInteger operator<<(const DynamicInteger &num, const DynamicInteger &shift)
    {
        if (shift < 0)
        {
            throw std::runtime_error(ERR_MSG_NEGATIVE_SHIFT_VALUE);
        }
        DynamicInteger result;
        mpz_mul_2exp(result.value, num.value, mpz_get_si(shift.value));
        return result;
    }

    DynamicInteger operator>>(const DynamicInteger &num, const DynamicInteger &shift)
    {
        if (shift < 0)
        {
            throw std::runtime_error(ERR_MSG_NEGATIVE_SHIFT_VALUE);
        }
        DynamicInteger result;
        mpz_tdiv_q_2exp(result.value, num.value, mpz_get_si(shift.value));
        return result;
    }

    std::istream &operator>>(std::istream &is, DynamicInteger &obj)
    {
        std::string val;
        is >> val;
        obj = DynamicInteger(val.c_str());
        return is;
    }

    DynamicInteger &DynamicInteger::operator+=(const DynamicInteger &other)
    {
        *this = *this + other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator-=(const DynamicInteger &other)
    {
        *this = *this - other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator*=(const DynamicInteger &other)
    {
        *this = *this * other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator/=(const DynamicInteger &other)
    {
        *this = *this / other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator%=(const DynamicInteger &other)
    {
        *this = *this % other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator>>=(const DynamicInteger &other)
    {
        *this = *this >> other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator<<=(const DynamicInteger &other)
    {
        *this = *this << other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator&=(const DynamicInteger &other)
    {
        *this = *this & other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator|=(const DynamicInteger &other)
    {
        *this = *this | other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator^=(const DynamicInteger &other)
    {
        *this = *this ^ other;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator++()
    {
        *this = *this + 1;
        return *this;
    }

    DynamicInteger &DynamicInteger::operator--()
    {
        *this = *this - 1;
        return *this;
    }

    DynamicInteger DynamicInteger::operator++(int)
    {
        DynamicInteger temp = *this;
        *this = *this + 1;
        return temp;
    }

    DynamicInteger DynamicInteger::operator--(int)
    {
        DynamicInteger temp = *this;
        *this = *this - 1;
        return temp;
    }

    bool operator&&(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return num1.boolGetNumber() && num2.boolGetNumber();
    }

    bool operator||(const DynamicInteger &num1, const DynamicInteger &num2)
    {
        return num1.boolGetNumber() || num2.boolGetNumber();
    }

}