#include "../../headers/ast/VariablesExpression.hpp"

#include <stdexcept>

VariablesExpression::VariablesExpression(std::string name)
{
    this->name = name;
}

double VariablesExpression::eval()
{
    return Variables::get(name);
}