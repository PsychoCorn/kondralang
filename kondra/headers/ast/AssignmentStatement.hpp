#ifndef AssignmentStatement_HPP
#define AssignmentStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

template <class T>
class AssignmentStatement final : public Statement
{
private:
    std::string variable;
    Expression<T> *expr;

public:
    AssignmentStatement(std::string, Expression<T> *);
    ~AssignmentStatement();
    void execute() override;
};

template <class T>
AssignmentStatement<T>::AssignmentStatement(std::string variable, Expression<T> *expr)
{
    this->variable = variable;
    this->expr = expr;
}

template <class T>
AssignmentStatement<T>::~AssignmentStatement()
{
    delete expr;
}

template <class T>
void AssignmentStatement<T>::execute()
{
    // double result = expr->eval();
    Variables<T>::set(variable, expr->eval());
}

#endif