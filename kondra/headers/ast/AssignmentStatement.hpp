#ifndef AssignmentStatement_HPP
#define AssignmentStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Scopes.hpp"
#include <string>

class AssignmentStatement final : public Statement
{
private:
    std::string variable;
    Expression *expr;

public:
    AssignmentStatement(std::string, Expression *);
    ~AssignmentStatement();
    void execute() override;
};

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
    Scopes::set(variable, expr->eval());
}

#endif