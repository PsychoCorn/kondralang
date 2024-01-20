#ifndef VariablesExpression_HPP
#define VariablesExpression_HPP

#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>
#include <stdexcept>

template <class T>
class VariablesExpression : public Expression<T>
{
private:
    std::string name;
public:
    VariablesExpression(std::string);
    T eval() override;
};

template <class T>
VariablesExpression<T>::VariablesExpression(std::string name)
{
    this->name = name;
}

template <class T>
T VariablesExpression<T>::eval()
{
    return Variables<T>::get(name);
}

#endif