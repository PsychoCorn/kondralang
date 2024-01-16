#include "../../headers/ast/AssignmentStatement.hpp"

AssignmentStatement::AssignmentStatement(std::string variable, Expression *expr)
{
    this->variable = variable;
    this->expr = expr;
}

AssignmentStatement::~AssignmentStatement()
{
    delete expr;
}

void AssignmentStatement::execute()
{
    //double result = expr->eval();
    Variables::set(variable, expr->eval());
}