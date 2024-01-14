#ifndef UnaryExpression_HPP
#define UnaryExpression_HPP

#include "Expression.hpp"

class UnaryExpression : public Expression
{
private:
    Expression* expr;
    char operation;
public:
    UnaryExpression(char, Expression*);
    ~UnaryExpression();
    double eval() override;
};

#endif