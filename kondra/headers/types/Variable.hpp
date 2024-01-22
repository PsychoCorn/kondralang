#ifndef Variable_HPP
#define Variable_HPP

#include "DynamicInteger.hpp"
#include <vector>

namespace kondra
{

    union VarData
    {
        dynamic_int *intData;
        double *floatData;
        string *stringData;
        bool *boolData;
    };

    enum class VarType
    {
        None,
        Int,
        Float,
        String,
        Bool
    };

    class Variable
    {
    private:
        VarData data;
        VarType type;

        void clearData();
        void copyDataFromOther(const Variable &);

    public:
        Variable();
        Variable(const dynamic_int &);
        Variable(const signed char &);
        Variable(const unsigned char &);
        Variable(const short &);
        Variable(const unsigned short &);
        Variable(const int &);
        Variable(const unsigned int &);
        Variable(const long long &);
        Variable(const unsigned long long &);
        Variable(const float &);
        Variable(const double &);
        Variable(const long double &);
        Variable(const char *);
        Variable(const std::string &);
        Variable(const string &);
        Variable(const bool &);
        Variable(const Variable &);
        ~Variable();
        VarType getType() const;
        VarData getData() const;
        Variable &operator=(const Variable &);
        friend std::ostream &operator<<(std::ostream &, const Variable &);
        friend std::istream &operator>>(std::istream &, Variable &);
        Variable operator-() const;
        friend Variable operator+(const Variable &, const Variable &);
        Variable &operator+=(const Variable &);
        Variable operator++(int);
        Variable &operator++();
        Variable operator--(int);
        Variable &operator--();
        friend Variable operator-(const Variable &, const Variable &);
        Variable &operator-=(const Variable &);
        friend Variable operator*(const Variable &, const Variable &);
        Variable &operator*=(const Variable &);
        friend Variable operator/(const Variable &, const Variable &);
        Variable &operator/=(const Variable &);
        friend Variable operator%(const Variable &, const Variable &);
        Variable &operator%=(const Variable &);
        bool operator!() const;
        friend bool operator&&(const Variable &, const Variable &);
        friend bool operator||(const Variable &, const Variable &);
        friend bool operator<(const Variable &, const Variable &);
        friend bool operator>(const Variable &, const Variable &);
        friend bool operator<=(const Variable &, const Variable &);
        friend bool operator>=(const Variable &, const Variable &);
        friend bool operator==(const Variable &, const Variable &);
        friend bool operator!=(const Variable &, const Variable &);
        inline explicit operator signed char() const;
        inline explicit operator unsigned char() const;
        inline explicit operator short() const;
        inline explicit operator unsigned short() const;
        inline explicit operator int() const;
        inline explicit operator unsigned int() const;
        inline explicit operator long long() const;
        inline explicit operator unsigned long long() const;
        inline explicit operator string() const;
        inline explicit operator bool() const;
        inline explicit operator double() const;
        inline explicit operator float() const;
        inline explicit operator long double() const;
        inline explicit operator dynamic_int() const;
        static Variable toInt(const Variable & = 0);
        static Variable toFloat(const Variable & = .0f);
        static Variable toString(const Variable & = "");
        static Variable toBool(const Variable & = false);
    };

    inline Variable::operator signed char() const
    {
        return Variable::toInt(*this).data.intData->longLongGetNumber();
    }

    inline Variable::operator unsigned char() const
    {
        return Variable::toInt(*this).data.intData->uLongLongGetNumber();
    }

    inline Variable::operator short() const
    {
        return Variable::toInt(*this).data.intData->longLongGetNumber();
    }

    inline Variable::operator unsigned short() const
    {
        return Variable::toInt(*this).data.intData->uLongLongGetNumber();
    }

    inline Variable::operator int() const
    {
        return Variable::toInt(*this).data.intData->longLongGetNumber();
    }

    inline Variable::operator unsigned int() const
    {
        return Variable::toInt(*this).data.intData->uLongLongGetNumber();
    }

    inline Variable::operator long long() const
    {
        return Variable::toInt(*this).data.intData->longLongGetNumber();
    }

    inline Variable::operator unsigned long long() const
    {
        return Variable::toInt(*this).data.intData->uLongLongGetNumber();
    }

    inline Variable::operator bool() const
    {
        return *(Variable::toBool(*this).data.boolData);
    }

    inline Variable::operator string() const
    {
        return *(Variable::toString(*this).data.stringData);
    }

    inline Variable::operator double() const
    {
        return *(Variable::toFloat(*this).data.floatData);
    }

    inline Variable::operator float() const
    {
        return *(Variable::toFloat(*this).data.floatData);
    }

    inline Variable::operator long double() const
    {
        return *(Variable::toFloat(*this).data.floatData);
    }

    inline Variable::operator dynamic_int() const
    {
        return *(Variable::toInt(*this).data.intData);
    }

    typedef Variable var;

}

#endif