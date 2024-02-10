#ifndef FunctionalExpression_HPP
#define FunctionalExpression_HPP

#include "Expression.hpp"
#include "../lib/Functions.hpp"
#include <string>
#include <vector>

class FunctionalExpression : public Expression
{
private:
    std::string name;
    std::vector<Expression *> args;

public:
    FunctionalExpression(std::string, std::vector<Expression *> = std::vector<Expression *>());
    ~FunctionalExpression();
    void addArgument(Expression *);
    Value *eval() override;
};

FunctionalExpression::FunctionalExpression(std::string name, std::vector<Expression *> args)
{
    this->name = name;
    this->args = args;
}

FunctionalExpression::~FunctionalExpression()
{
    for (auto expr : args)
    {
        delete expr;
    }
}

void FunctionalExpression::addArgument(Expression *arg)
{
    args.push_back(arg);
}

Value *FunctionalExpression::eval()
{
    std::vector<Value *> values;
    values.reserve(args.size());
    for (auto arg : args)
    {
        values.push_back(arg->eval());
    }
    return Functions::get(name)->execute(values.begin(), values.end());
}

#endif