#ifndef BinaryExpression_HPP
#define BinaryExpression_HPP

#include "Expression.hpp"

class BinaryExpression : public Expression
{
private:
    Expression* expr1;
    Expression* expr2;
    char operation;

public:
    BinaryExpression(char, Expression*, Expression*);
    ~BinaryExpression();
    double eval() override;
};



#endif