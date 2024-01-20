#ifndef ValueExpression_HPP
#define ValueExpression_HPP

#include "Expression.hpp"

template <class T>
class ValueExpression : public Expression<T>
{
private:
    T value;
public:
    ValueExpression(T);
    T eval() override;
};

template <class T>
ValueExpression<T>::ValueExpression(T value)
{
    this->value = value;
}

template <class T>
T ValueExpression<T>::eval()
{
    return value;
}

#endif