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
        Variable(const int &);
        Variable(const double &);
        Variable(const long long &);
        Variable(const char *);
        Variable(const std::string &);
        Variable(const string &);
        Variable(const bool &);
        Variable(const Variable &);
        ~Variable();
        VarType getType() const;
        VarData getData() const;
        Variable &operator=(const Variable &);
        Variable &toInt();
        Variable &toFloat();
        Variable &toString();
        Variable &toBool();
        char &at(const Variable &);
        char &operator[](const Variable &);
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
        explicit operator long long() const;
        explicit operator unsigned long long() const;
        explicit operator string() const;
        explicit operator bool() const;
        explicit operator double() const;
        explicit operator dynamic_int() const;
    };

    Variable toInt(const Variable & = 0);
    Variable toFloat(const Variable & = .0f);
    Variable toString(const Variable & = "");
    Variable toBool(const Variable & = false);

    typedef Variable var;

}

#endif