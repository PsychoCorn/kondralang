#ifndef DynamicInteger_HPP
#define DynamicInteger_HPP

#include <gmp.h>
#include <cinttypes>
#include "String.hpp"

namespace kondra
{

    class DynamicInteger
    {
    private:
        mpz_t value;

    public:
        DynamicInteger();
        DynamicInteger(const int8_t &);
        DynamicInteger(const uint8_t &);
        DynamicInteger(const int16_t &);
        DynamicInteger(const uint16_t &);
        DynamicInteger(const int32_t &);
        DynamicInteger(const uint32_t &);
        DynamicInteger(const int64_t &);
        DynamicInteger(const uint64_t &);
        DynamicInteger(const char *, const size_t& = 10);
        DynamicInteger(const string &, const size_t& = 10);
        DynamicInteger(const std::string &, const size_t& = 10);
        DynamicInteger(const float &);
        DynamicInteger(const double &);
        DynamicInteger(const long double &);
        DynamicInteger(const DynamicInteger &);
        ~DynamicInteger();
        char *strGetNumber(const size_t& = 10) const;
        double doubleGetNumber() const;
        int64_t longLongGetNumber() const;
        uint64_t uLongLongGetNumber() const;
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
        DynamicInteger operator++(int32_t);
        DynamicInteger &operator++();
        DynamicInteger operator--(int32_t);
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
        inline explicit operator int8_t() const;
        inline explicit operator uint8_t() const;
        inline explicit operator int16_t() const;
        inline explicit operator uint16_t() const;
        inline explicit operator int32_t() const;
        inline explicit operator uint32_t() const;
        inline explicit operator int64_t() const;
        inline explicit operator uint64_t() const;
        inline explicit operator string() const;
        inline explicit operator float() const;
        inline explicit operator double() const;
        inline explicit operator long double() const;
        inline explicit operator bool() const;
    };

    inline DynamicInteger::operator int8_t() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator uint8_t() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator int16_t() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator uint16_t() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator int32_t() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator uint32_t() const
    {
        return uLongLongGetNumber();
    }

    inline DynamicInteger::operator int64_t() const
    {
        return longLongGetNumber();
    }

    inline DynamicInteger::operator uint64_t() const
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