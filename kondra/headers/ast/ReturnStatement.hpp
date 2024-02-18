#ifndef ReturnStatement_HPP
#define ReturnStatement_HPP

#include <stdexcept>
#include"Expression.hpp"
#include "Statement.hpp"

class ReturnStatement : public std::runtime_error, public Statement
{
private:
    Expression *expr;
public:
    ReturnStatement(Expression *, const std::string & = "");
    Value *getValue() const;
    void execute() override;
};

ReturnStatement::ReturnStatement(Expression *expr, const std::string &message) : std::runtime_error(message) 
{
    this->expr = expr;
}

void ReturnStatement::execute()
{
    throw *this;
}

Value *ReturnStatement::getValue() const
{
    return expr->eval();
}

#endif