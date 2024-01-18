#ifndef NumberExpression_HPP
#define NumberExpression_HPP

#include "Expression.hpp"

template <class T>
class NumberExpression : public Expression<T>
{
private:
    T value;
public:
    NumberExpression(T);
    T eval() override;
};

template <class T>
NumberExpression<T>::NumberExpression(T value)
{
    this->value = value;
}

template <class T>
T NumberExpression<T>::eval()
{
    return value;
}

#endif