#ifndef IfStatement_HPP
#define IfStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../types/String.hpp"

template <class T>
class IfStatement : public Statement
{
private:
    Expression<T> *expression;
    Statement *ifStatement;
    Statement *elseStatement;
public:
    IfStatement(Expression<T> *, Statement *, Statement *);
    ~IfStatement();
    void execute() override;
};

template <class T>
IfStatement<T>::IfStatement(Expression<T> *expression, Statement *ifStatement, Statement *elseStatement)
{
    this->expression = expression;
    this->ifStatement = ifStatement;
    this->elseStatement = elseStatement;
}

template <class T>
IfStatement<T>::~IfStatement()
{
    delete expression, ifStatement, elseStatement;
}

template <class T>
void IfStatement<T>::execute()
{
    T result = expression->eval();
    if (result)
        ifStatement->execute();
    else if (elseStatement != nullptr)
        elseStatement->execute();
}

template <>
void IfStatement<kondra::string>::execute()
{
    kondra::string result = expression->eval();
    if (result == "1")
        ifStatement->execute();
    else if (elseStatement != nullptr)
        elseStatement->execute();
}

#endif