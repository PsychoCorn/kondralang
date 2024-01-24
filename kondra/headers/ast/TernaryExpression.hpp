#ifndef TernaryExpression_HPP
#define TernaryExpression_HPP

#include "Expression.hpp"
#include <stdexcept>

template <class T>
class TernaryExpression : public Expression<T>
{
private:
    Expression<T> *condition;
    Expression<T> *exprIfTrue;
    Expression<T> *exprIfFalse;
public:
    TernaryExpression(Expression<T>*, Expression<T>*, Expression<T>*);
    ~TernaryExpression();
    T eval() override;
};

template <class T>
TernaryExpression<T>::TernaryExpression(Expression<T>* condition, Expression<T> *exprIfTrue, Expression<T> *exprIfFalse)
{
    this->condition = condition;
    this->exprIfTrue = exprIfTrue;
    this->exprIfFalse = exprIfFalse;
}

template <class T>
TernaryExpression<T>::~TernaryExpression()
{
    delete condition, exprIfTrue, exprIfFalse;
}

template<class T>
T TernaryExpression<T>::eval()
{
    return condition->eval() ? exprIfTrue->eval() : exprIfFalse->eval();
}

#endif