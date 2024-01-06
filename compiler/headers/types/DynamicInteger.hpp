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
        char *strGetNumber() const;
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
        inline explicit operator signed char();
        inline explicit operator unsigned char();
        inline explicit operator short();
        inline explicit operator unsigned short();
        inline explicit operator int();
        inline explicit operator unsigned int();
        inline explicit operator long long();
        inline explicit operator unsigned long long();
        inline explicit operator string();
        inline explicit operator float();
        inline explicit operator double();
        inline explicit operator long double();
        inline explicit operator bool();
    };

    inline DynamicInteger::operator signed char()
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned char()
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator short()
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned short()
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator int()
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned int()
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator long long()
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator unsigned long long()
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator string()
    {
        return strGetNumber();
    }

    inline DynamicInteger::operator float()
    {
        return doubleGetNumber();
    }

    inline DynamicInteger::operator double()
    {
        return doubleGetNumber();
    }

    inline DynamicInteger::operator long double()
    {
        return doubleGetNumber();
    }

    inline DynamicInteger::operator bool()
    {
        return boolGetNumber();
    }

    std::ostream &operator<<(std::ostream &, const DynamicInteger &);

    typedef DynamicInteger dynamic_int;

}

#endif