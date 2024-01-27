#ifndef ConditionalExpression_HPP
#define ConditionalExpression_HPP

#include "Expression.hpp"
#include <stdexcept>
#include <string>

#define ERR_MSG_WRNG_COND_OP "Wrong conditional operator"

template <class T>
class ConditionalExpression : public Expression<T>
{
private:
    Expression<T>* expr1;
    Expression<T>* expr2;
    std::string operation;
public:
    ConditionalExpression(std::string, Expression<T>*, Expression<T>*);
    ~ConditionalExpression();
    T eval() override;
};

template <class T>
ConditionalExpression<T>::ConditionalExpression(std::string operation, Expression<T>* expr1, Expression<T>* expr2)
{
    this->operation = operation;
    this->expr1 = expr1;
    this->expr2 = expr2;
}

template <class T>
ConditionalExpression<T>::~ConditionalExpression()
{
    delete expr1, expr2;
}

template<class T>
T ConditionalExpression<T>::eval()
{
    if (operation == "==")
        return expr1->eval() == expr2->eval();
    else if (operation == "<")
        return expr1->eval() < expr2->eval();
    else if (operation == ">")
        return expr1->eval() > expr2->eval();
    else if (operation == "<=")
        return expr1->eval() <= expr2->eval();
    else if (operation == ">=")
        return expr1->eval() >= expr2->eval();
    else if (operation == "!=")
        return expr1->eval() != expr2->eval();
    throw std::runtime_error(ERR_MSG_WRNG_COND_OP);
}

template<>
kondra::string ConditionalExpression<kondra::string>::eval()
{
    if (operation == "==")
        return expr1->eval() == expr2->eval() ? "1" : "0";
    else if (operation == "<")
        return expr1->eval() < expr2->eval() ? "1" : "0";
    else if (operation == ">")
        return expr1->eval() > expr2->eval() ? "1" : "0";
    else if (operation == "<=")
        return expr1->eval() <= expr2->eval() ? "1" : "0";
    else if (operation == ">=")
        return expr1->eval() >= expr2->eval() ? "1" : "0";
    else if (operation == "!=")
        return expr1->eval() != expr2->eval() ? "1" : "0";
    throw std::runtime_error(ERR_MSG_WRNG_COND_OP);
}

#endif