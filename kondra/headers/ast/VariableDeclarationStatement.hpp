#ifndef VariableDeclarationStatement_HPP
#define VariableDeclarationStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

class VariableDeclarationStatement final : public Statement
{
private:
    std::string type;
    std::string variable;
    Expression *expr;

public:
    VariableDeclarationStatement(const std::string &, const std::string &, Expression *);
    ~VariableDeclarationStatement();
    void execute() override;
};

VariableDeclarationStatement::VariableDeclarationStatement(const std::string &type, 
    const std::string &variable, Expression *expr)
{
    this->type = type;
    this->variable = variable;
    this->expr = expr;
}

VariableDeclarationStatement::~VariableDeclarationStatement()
{
    delete expr;
}

void VariableDeclarationStatement::execute()
{
    Variables::create(type, variable, expr->eval());
}

#endif