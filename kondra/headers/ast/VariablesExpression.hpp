#ifndef VariablesExpression_HPP
#define VariablesExpression_HPP

#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

class VariablesExpression : public Expression
{
private:
    std::string name;
public:
    VariablesExpression(std::string);
    double eval() override;
};

#endif