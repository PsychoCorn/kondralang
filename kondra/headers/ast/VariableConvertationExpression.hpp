#ifndef VariableConvertationExpression_HPP
#define VariableConvertationExpression_HPP

#include "../types/Variable.hpp"
#include "Expression.hpp"

class VariableConvertationExpression : public Expression
{
private:
    Expression *variableToConvert;
    kondra::VarType typeOfConvertation;
public:
    VariableConvertationExpression(Expression *, kondra::VarType);
    ~VariableConvertationExpression();
    Value *eval() override;
};

VariableConvertationExpression::VariableConvertationExpression(Expression *variableToConvert, 
    kondra::VarType typtypeOfConvertation)
{
    this->variableToConvert = variableToConvert;
    this->typeOfConvertation = typtypeOfConvertation;
}

VariableConvertationExpression::~VariableConvertationExpression()
{
    delete variableToConvert;
}

Value *VariableConvertationExpression::eval()
{
    switch (typeOfConvertation)
    {
    case kondra::VarType::Int:
        return new VarValue(kondra::var::toInt(variableToConvert->eval()->varGet()));

    case kondra::VarType::Float:
        return new VarValue(kondra::var::toFloat(variableToConvert->eval()->varGet()));

    case kondra::VarType::String:
        return new VarValue(kondra::var::toString(variableToConvert->eval()->varGet()));

    case kondra::VarType::Bool:
        return new VarValue(kondra::var::toBool(variableToConvert->eval()->varGet()));
    
    default:
        throw std::runtime_error("Wrong type of conversation");
    }
}

#endif