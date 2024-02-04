#ifndef BinaryExpression_HPP
#define BinaryExpression_HPP

#include "Expression.hpp"
#include <stdexcept>
#include <string>

#define ERR_MSG_DIV_BY_ZERO "Division by zero"
#define ERR_MSG_WRNG_BIN_OP "Wrong binary operator"
#define ERR_MSG_NEG_SHFT "Negative shift"
#define ERR_MSG_OP_FOR_NOT_INT_AND_BOOL "Operator for not int and bool is undefined"

template <class T>
class BinaryExpression : public Expression<T>
{
private:
    Expression<T>* expr1;
    Expression<T>* expr2;
    std::string operation;

public:
    BinaryExpression(std::string, Expression<T>*, Expression<T>*);
    ~BinaryExpression();
    T eval() override;
};

template<class T>
BinaryExpression<T>::BinaryExpression(std::string operation, Expression<T>* expr1, Expression<T>* expr2)
{
    this->operation = operation;
    this->expr1 = expr1;
    this->expr2 = expr2;
}

template<class T>
BinaryExpression<T>::~BinaryExpression()
{
    delete expr1, expr2;
}

template<class T>
T BinaryExpression<T>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    else if (operation == "&")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    else if (operation == "|")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    else if (operation == "^")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    else if (operation == ">>")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    else if (operation == "<<")
        throw std::runtime_error(ERR_MSG_OP_FOR_NOT_INT_AND_BOOL);
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
signed char BinaryExpression<signed char>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
unsigned char BinaryExpression<unsigned char>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
short BinaryExpression<short>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
unsigned short BinaryExpression<unsigned short>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
int BinaryExpression<int>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
unsigned int BinaryExpression<unsigned int>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
long long BinaryExpression<long long>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
unsigned long long BinaryExpression<unsigned long long>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
kondra::dynamic_int BinaryExpression<kondra::dynamic_int>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
kondra::var BinaryExpression<kondra::var>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "-")
        return expr1->eval() - expr2->eval();
    else if (operation == "*")
        return expr1->eval() * expr2->eval();
    else if (operation == "/")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() / expr2->eval();
    }
    else if (operation == "%")
    {
        if (expr2->eval() == 0)
            throw std::runtime_error(ERR_MSG_DIV_BY_ZERO);
        return expr1->eval() % expr2->eval();
    }
    else if (operation == "&")
        return expr1->eval() & expr2->eval();
    else if (operation == "|")
        return expr1->eval() | expr2->eval();
    else if (operation == "^")
        return expr1->eval() ^ expr2->eval();
    else if (operation == ">>")
        return expr1->eval() >> expr2->eval();
    else if (operation == "<<")
        return expr1->eval() << expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

template<>
kondra::string BinaryExpression<kondra::string>::eval()
{
    if (operation == "+")
        return expr1->eval() + expr2->eval();
    else if (operation == "*")
        return expr1->eval() * std::stoull(expr2->eval());
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

#endif