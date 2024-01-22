#ifndef UnaryExpression_HPP
#define UnaryExpression_HPP

#include "Expression.hpp"
#include <string>
#include <stdexcept>

#define ERR_MSG_WRNG_UN_OP "Wrong unary operator"
#define ERR_MSG_OP_FOR_NOT_INT_AND_BOOL "Operator for not int and bool is undefined"

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
    else if(operation == "~")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
signed char UnaryExpression<signed char>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
unsigned char UnaryExpression<unsigned char>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
short UnaryExpression<short>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
unsigned short UnaryExpression<unsigned short>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
int UnaryExpression<int>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
unsigned int UnaryExpression<unsigned int>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
long long UnaryExpression<long long>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
unsigned long long UnaryExpression<unsigned long long>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
kondra::dynamic_int UnaryExpression<kondra::dynamic_int>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
kondra::var UnaryExpression<kondra::var>::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return -expr->eval();
    else if(operation == "~")
        return ~expr->eval();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

template <>
kondra::string UnaryExpression<kondra::string>::eval()
{
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

#endif