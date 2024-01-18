#ifndef DynamicInteger_HPP
#define DynamicInteger_HPP

#include <gmp.h>
#include "String.hpp"

namespace kondra
{

    class DynamicInteger
    {
    private:
        mpz_t value;

    public:
        DynamicInteger();
        DynamicInteger(const int &);
        DynamicInteger(const long long &);
        DynamicInteger(const char *);
        DynamicInteger(const string &);
        DynamicInteger(const std::string &);
        DynamicInteger(const double &);
        DynamicInteger(const DynamicInteger &);
        ~DynamicInteger();
        char *strGetNumber(const size_t& = 10) const;
        double doubleGetNumber() const;
        long long longLongGetNumber() const;
        unsigned long long uLongLongGetNumber() const;
        bool boolGetNumber() const;
        DynamicInteger &operator=(const DynamicInteger &);
        DynamicInteger &operator+=(const DynamicInteger &);
        DynamicInteger &operator-=(const DynamicInteger &);
        DynamicInteger &operator*=(const DynamicInteger &);
        DynamicInteger &operator/=(const DynamicInteger &);
        DynamicInteger &operator%=(const DynamicInteger &);
        DynamicInteger &operator>>=(const DynamicInteger &);
        DynamicInteger &operator<<=(const DynamicInteger &);
        DynamicInteger &operator&=(const DynamicInteger &);
        DynamicInteger &operator|=(const DynamicInteger &);
        DynamicInteger &operator^=(const DynamicInteger &);
        DynamicInteger operator++(int);
        DynamicInteger &operator++();
        DynamicInteger operator--(int);
        DynamicInteger &operator--();
        friend DynamicInteger operator+(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator-(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator*(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator/(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator%(const DynamicInteger &, const DynamicInteger &);
        DynamicInteger operator-() const;
        bool operator!() const;
        friend bool operator&&(const DynamicInteger &, const DynamicInteger &);
        friend bool operator||(const DynamicInteger &, const DynamicInteger &);
        friend bool operator<(const DynamicInteger &, const DynamicInteger &);
        friend bool operator>(const DynamicInteger &, const DynamicInteger &);
        friend bool operator<=(const DynamicInteger &, const DynamicInteger &);
        friend bool operator>=(const DynamicInteger &, const DynamicInteger &);
        friend bool operator==(const DynamicInteger &, const DynamicInteger &);
        friend bool operator!=(const DynamicInteger &, const DynamicInteger &);
        DynamicInteger operator~() const;
        friend DynamicInteger operator&(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator|(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator^(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator<<(const DynamicInteger &, const DynamicInteger &);
        friend DynamicInteger operator>>(const DynamicInteger &, const DynamicInteger &);
        friend std::istream &operator>>(std::istream &, DynamicInteger &);
        inline explicit operator signed char() const;
        inline explicit operator unsigned char() const;
        inline explicit operator short() const;
        inline explicit operator unsigned short() const;
        inline explicit operator int() const;
        inline explicit operator unsigned int() const;
        inline explicit operator long long() const;
        inline explicit operator unsigned long long() const;
        inline explicit operator string() const;
        inline explicit operator float() const;
        inline explicit operator double() const;
        inline explicit operator long double() const;
        inline explicit operator bool() const;
    };

    inline DynamicInteger::operator signed char() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned char() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator short() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned short() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator int() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned int() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator long long() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned long long() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator string() const
    {
        return strGetNumber();
    }

    inline DynamicInteger::operator float() const
    {
        return doubleGetNumber();
    }

    inline DynamicInteger::operator double() const
    {
        return doubleGetNumber();
    }

    inline DynamicInteger::operator long double() const
    {
        return doubleGetNumber();
    }

    inline DynamicInteger::operator bool() const
    {
        return boolGetNumber();
    }

    std::ostream &operator<<(std::ostream &, const DynamicInteger &);

    typedef DynamicInteger dynamic_int;

}

#endif