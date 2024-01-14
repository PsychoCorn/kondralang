#include "../../headers/ast/NumberExpression.hpp"

NumberExpression::NumberExpression(double value)
{
    this->value = value;
}

double NumberExpression::eval()
{
    return value;
}