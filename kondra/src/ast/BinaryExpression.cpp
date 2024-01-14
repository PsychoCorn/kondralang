#include "../../headers/ast/BinaryExpression.hpp"

#include <stdexcept>

BinaryExpression::BinaryExpression(char operation, Expression* expr1, Expression* expr2)
{
    this->operation = operation;
    this->expr1 = expr1;
    this->expr2 = expr2;
}

BinaryExpression::~BinaryExpression()
{
    delete expr1, expr2;
}

double BinaryExpression::eval()
{
    switch (operation)
    {
    case '+':
        return expr1->eval() + expr2->eval();
        break;

    case '-':
        return expr1->eval() - expr2->eval();
        break;

    case '*':
        return expr1->eval() * expr2->eval();
        break;

    case '/':
        if (expr2->eval() == 0)
            throw std::runtime_error("Division by zero!");
        return expr1->eval() / expr2->eval();
        break;
    
    default:
        throw std::runtime_error("Wrong operator!");
        break;
    }
}