#ifndef IncrementStatement_HPP
#define IncrementStatement_HPP

#include "Statement.hpp"
#include "IncrementExpression.hpp"

class IncrementStatement final : public Statement
{
private:
    std::string variable;
    TokenType operation;
    bool isPrefix;

public:
    IncrementStatement(const std::string &, const TokenType &, const bool &);
    void execute() override;
};

IncrementStatement::IncrementStatement(const std::string &variable, 
    const TokenType &operation, const bool &isPrefix)
{
    this->variable = variable;
    this->operation = operation;
    this->isPrefix = isPrefix;
}

void IncrementStatement::execute()
{
    auto increment = new IncrementExpression(variable, operation, isPrefix);
    auto value = increment->eval();
    delete value, increment;
}

#endif