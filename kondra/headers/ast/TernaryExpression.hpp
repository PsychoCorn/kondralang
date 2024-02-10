#ifndef TernaryExpression_HPP
#define TernaryExpression_HPP

#include "Expression.hpp"
#include "../lib/types/Value.hpp"
#include <stdexcept>

class TernaryExpression : public Expression
{
private:
    Expression *condition;
    Expression *exprIfTrue;
    Expression *exprIfFalse;
public:
    TernaryExpression(Expression*, Expression*, Expression*);
    ~TernaryExpression();
    Value *eval() override;
};

TernaryExpression::TernaryExpression(Expression* condition, Expression *exprIfTrue, Expression *exprIfFalse)
{
    this->condition = condition;
    this->exprIfTrue = exprIfTrue;
    this->exprIfFalse = exprIfFalse;
}

TernaryExpression::~TernaryExpression()
{
    delete condition, exprIfTrue, exprIfFalse;
}

Value *TernaryExpression::eval()
{
    return condition->eval()->bGet() ? exprIfTrue->eval() : exprIfFalse->eval();
}

#endif