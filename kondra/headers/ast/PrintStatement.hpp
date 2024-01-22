#ifndef PrintStatement_HPP
#define PrintStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include <iostream>
#include <format>

template <class T>
class PrintStatement final : public Statement
{
private:
    Expression<T> *expr;

public:
    PrintStatement(Expression<T> *);
    ~PrintStatement();
    void execute() override;
};

template <class T>
PrintStatement<T>::PrintStatement(Expression<T> *expr)
{
    this->expr = expr;
}

template <class T>
PrintStatement<T>::~PrintStatement()
{
    delete expr;
}

template <class T>
void PrintStatement<T>::execute()
{
    std::cout << expr->eval();
}

template <>
void PrintStatement<signed char>::execute()
{
    std::cout << static_cast<int>(expr->eval());
}

template <>
void PrintStatement<unsigned char>::execute()
{
    std::cout << static_cast<int>(expr->eval());
}

template <>
void PrintStatement<bool>::execute()
{
    std::cout << std::boolalpha << expr->eval();
}

#endif