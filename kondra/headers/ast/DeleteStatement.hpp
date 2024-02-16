#ifndef DeleteStatement_HPP
#define DeleteStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

class DeleteStatement final : public Statement
{
private:
    std::string variable;

public:
    DeleteStatement(std::string);
    void execute() override;
};

DeleteStatement::DeleteStatement(std::string variable)
{
    this->variable = variable;
}

void DeleteStatement::execute()
{
    // double result = expr->eval();
    Variables::deleteVar(variable);
}

#endif