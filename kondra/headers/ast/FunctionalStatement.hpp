#ifndef FunctionalStatement_HPP
#define FunctionalStatement_HPP

#include "Statement.hpp"
#include "FunctionalExpression.hpp"


class FunctionalStatement final : public Statement
{
private:
    FunctionalExpression *function;

public:
    FunctionalStatement(FunctionalExpression *);
    ~FunctionalStatement();
    void execute() override;
};

FunctionalStatement::FunctionalStatement(FunctionalExpression *function)
{
    this->function = function;
}

FunctionalStatement::~FunctionalStatement()
{
    delete function;
}

void FunctionalStatement::execute()
{
    function->eval();
}

#endif