#ifndef NumberExpression_HPP
#define NumberExpression_HPP

#include "Expression.hpp"

class NumberExpression : public Expression
{
private:
    double value;
public:
    NumberExpression(double);

    double eval() override;
};

#endif