#ifndef VariablesExpression_HPP
#define VariablesExpression_HPP

#include "Expression.hpp"
#include "../lib/Scopes.hpp"
#include <string>
#include <stdexcept>

class VariablesExpression : public Expression
{
private:
    std::string name;
public:
    VariablesExpression(std::string);
    Value *eval() override;
};

VariablesExpression::VariablesExpression(std::string name)
{
    this->name = name;
}

Value *VariablesExpression::eval()
{
    return Scopes::get(name);
}

#endif