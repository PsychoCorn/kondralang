#include "../../headers/ast/ConstantExpression.hpp"

#include <stdexcept>

ConstantExpression::ConstantExpression(std::string name)
{
    this->name = name;
}

double ConstantExpression::eval()
{
    return Constants::get(name);
}