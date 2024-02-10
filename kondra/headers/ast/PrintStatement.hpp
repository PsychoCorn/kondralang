#ifndef PrintStatement_HPP
#define PrintStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include <iostream>
#include <format>

class PrintStatement final : public Statement
{
private:
    Expression *expr;

public:
    PrintStatement(Expression *);
    ~PrintStatement();
    void execute() override;
};

PrintStatement::PrintStatement(Expression *expr)
{
    this->expr = expr;
}

PrintStatement::~PrintStatement()
{
    delete expr;
}

void PrintStatement::execute()
{
    std::cout << expr->eval();
}

#endif