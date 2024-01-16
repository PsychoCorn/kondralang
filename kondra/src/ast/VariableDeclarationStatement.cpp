#include "../../headers/ast/VariableDeclarationStatement.hpp"

VariableDeclarationStatement::VariableDeclarationStatement(std::string variable, Expression *expr)
{
    this->variable = variable;
    this->expr = expr;
}

VariableDeclarationStatement::~VariableDeclarationStatement()
{
    delete expr;
}

void VariableDeclarationStatement::execute()
{
    Variables::create(variable, expr->eval());
}