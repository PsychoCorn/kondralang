#ifndef ConstantExpression_HPP
#define ConstantExpression_HPP

#include "Expression.hpp"
#include "../lib/Constants.hpp"
#include <string>

class ConstantExpression : public Expression
{
private:
    std::string name;
public:
    ConstantExpression(std::string);
    double eval() override;
};

#endif