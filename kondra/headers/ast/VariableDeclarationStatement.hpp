#ifndef VariableDeclarationStatement_HPP
#define VariableDeclarationStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

class VariableDeclarationStatement final : public Statement
{
private:
    std::string variable;
    Expression *expr;

public:
    VariableDeclarationStatement(std::string, Expression *);
    ~VariableDeclarationStatement();
    void execute() override;
};

#endif