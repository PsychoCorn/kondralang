#ifndef UnaryExpression_HPP
#define UnaryExpression_HPP

#include "Expression.hpp"
#include <string>
#include <stdexcept>

template <class T>
class UnaryExpression : public Expression<T>
{
private:
    Expression<T>* expr;
    std::string operation;
public:
    UnaryExpression(std::string, Expression<T>*);
    ~UnaryExpression();
    T eval() override;
};

#define ERR_MSG_WRNG_OP "Wrong operator!"

template <class T>
UnaryExpression<T>::UnaryExpression(std::string operation, Expression<T>* expr)
{
    this->operation = operation;
    this->expr = expr;
}

template <class T>
UnaryExpression<T>::~UnaryExpression()
{
    delete expr;
}

template <class T>
T UnaryExpression<T>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_OP);
}

#endif