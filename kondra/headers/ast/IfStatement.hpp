#ifndef IfStatement_HPP
#define IfStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../types/String.hpp"

class IfStatement : public Statement
{
private:
    Expression *expression;
    Statement *ifStatement;
    Statement *elseStatement;
public:
    IfStatement(Expression *, Statement *, Statement *);
    ~IfStatement();
    void execute() override;
};

IfStatement::IfStatement(Expression *expression, Statement *ifStatement, Statement *elseStatement)
{
    this->expression = expression;
    this->ifStatement = ifStatement;
    this->elseStatement = elseStatement;
}

IfStatement::~IfStatement()
{
    delete expression, ifStatement, elseStatement;
}

void IfStatement::execute()
{
    if (expression->eval()->bGet())
        ifStatement->execute();
    else if (elseStatement != nullptr)
        elseStatement->execute();
}

#endif