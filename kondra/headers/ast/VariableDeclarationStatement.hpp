#ifndef VariableDeclarationStatement_HPP
#define VariableDeclarationStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Scopes.hpp"
#include <string>

class VariableDeclarationStatement final : public Statement
{
private:
    bool isConst;
    bool isGlobal;
    std::string type;
    std::string variable;
    Expression *expr;

public:
    VariableDeclarationStatement(const bool &, const bool &, const std::string &, const std::string &, 
        Expression *);
    ~VariableDeclarationStatement();
    void execute() override;
};

VariableDeclarationStatement::VariableDeclarationStatement(const bool &isGlobal, const bool &isConst, 
    const std::string &type, const std::string &variable, Expression *expr)
{
    this->isGlobal = isGlobal;
    this->isConst = isConst;
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
    Scopes::create(type, variable, isGlobal, isConst, expr == nullptr ? nullptr : expr->eval());
}

#endif