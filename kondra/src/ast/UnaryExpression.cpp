#include "../../headers/ast/UnaryExpression.hpp"

#include <stdexcept>

UnaryExpression::UnaryExpression(char operation, Expression* expr)
{
    this->operation = operation;
    this->expr = expr;
}

UnaryExpression::~UnaryExpression()
{
    delete expr;
}

double UnaryExpression::eval()
{
    switch (operation)
    {
    case '+':
        return expr->eval();
        break;

    case '-':
        return -expr->eval();
        break;

    default:
        throw std::runtime_error("Wrong operator!");
        break;
    }
}