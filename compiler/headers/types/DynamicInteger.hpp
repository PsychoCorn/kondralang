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
    DynamicInteger(const int&);
    DynamicInteger(const long long&);
    DynamicInteger(const char*);
    DynamicInteger(const string&);
    DynamicInteger(const std::string&);
    DynamicInteger(const double&);
    DynamicInteger(const DynamicInteger&);
    ~DynamicInteger();
    char* strGetNumber() const;
    double doubleGetNumber() const;
    long long longLongGetNumber() const;
    unsigned long long uLongLongGetNumber() const;
    bool boolGetNumber() const;
    DynamicInteger& operator=(const DynamicInteger&);
    DynamicInteger& operator+=(const DynamicInteger&);
    DynamicInteger& operator-=(const DynamicInteger&);
    DynamicInteger& operator*=(const DynamicInteger&);
    DynamicInteger& operator/=(const DynamicInteger&);
    DynamicInteger& operator%=(const DynamicInteger&);
    DynamicInteger& operator>>=(const DynamicInteger&);
    DynamicInteger& operator<<=(const DynamicInteger&);
    DynamicInteger& operator&=(const DynamicInteger&);
    DynamicInteger& operator|=(const DynamicInteger&);
    DynamicInteger& operator^=(const DynamicInteger&);
    DynamicInteger operator++(int);
    DynamicInteger& operator++();
    DynamicInteger operator--(int);
    DynamicInteger& operator--();
    friend DynamicInteger operator+(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator-(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator*(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator/(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator%(const DynamicInteger&, const DynamicInteger&);
    DynamicInteger operator-() const;
    bool operator!() const;
    friend bool operator&&(const DynamicInteger&, const DynamicInteger&);
    friend bool operator||(const DynamicInteger&, const DynamicInteger&);
    friend bool operator<(const DynamicInteger&, const DynamicInteger&);
    friend bool operator>(const DynamicInteger&, const DynamicInteger&);
    friend bool operator<=(const DynamicInteger&, const DynamicInteger&);
    friend bool operator>=(const DynamicInteger&, const DynamicInteger&);
    friend bool operator==(const DynamicInteger&, const DynamicInteger&);
    friend bool operator!=(const DynamicInteger&, const DynamicInteger&);
    DynamicInteger operator~() const;
    friend DynamicInteger operator&(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator|(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator^(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator<<(const DynamicInteger&, const DynamicInteger&);
    friend DynamicInteger operator>>(const DynamicInteger&, const DynamicInteger&);
    friend std::istream& operator>>(std::istream&, DynamicInteger&);
};

std::ostream& operator<<(std::ostream&, const DynamicInteger&);

typedef DynamicInteger dynamic_int;

}

#endif