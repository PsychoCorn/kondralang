#ifndef VariableDeclarationStatement_HPP
#define VariableDeclarationStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

template <class T>
class VariableDeclarationStatement final : public Statement
{
private:
    std::string variable;
    Expression<T> *expr;

public:
    VariableDeclarationStatement(std::string, Expression<T> *);
    ~VariableDeclarationStatement();
    void execute() override;
};

template <class T>
VariableDeclarationStatement<T>::VariableDeclarationStatement(std::string variable, Expression<T> *expr)
{
    this->variable = variable;
    this->expr = expr;
}

template <class T>
VariableDeclarationStatement<T>::~VariableDeclarationStatement()
{
    delete expr;
}

template <class T>
void VariableDeclarationStatement<T>::execute()
{
    Variables<T>::create(variable, expr->eval());
}

#endif