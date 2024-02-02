#ifndef VariableConvertationExpression_HPP
#define VariableConvertationExpression_HPP

#include "../types/Variable.hpp"
#include "../lib/ListOfVariables.hpp"
#include "Expression.hpp"

class VariableConvertationExpression : public Expression<kondra::var>
{
private:
    Expression<kondra::var> *variableToConvert;
    kondra::VarType typeOfConvertation;
public:
    VariableConvertationExpression(Expression<kondra::var> *, kondra::VarType);
    ~VariableConvertationExpression();
    kondra::var eval() override;
};

VariableConvertationExpression::VariableConvertationExpression(Expression<kondra::var> *variableToConvert, 
    kondra::VarType typtypeOfConvertation)
{
    this->variableToConvert = variableToConvert;
    this->typeOfConvertation = typtypeOfConvertation;
}

VariableConvertationExpression::~VariableConvertationExpression()
{
    delete variableToConvert;
}

kondra::var VariableConvertationExpression::eval()
{
    switch (typeOfConvertation)
    {
    case kondra::VarType::Int:
        return kondra::var::toInt(variableToConvert->eval());

    case kondra::VarType::Float:
        return kondra::var::toFloat(variableToConvert->eval());

    case kondra::VarType::String:
        return kondra::var::toString(variableToConvert->eval());

    case kondra::VarType::Bool:
        return kondra::var::toBool(variableToConvert->eval());
    
    default:
        throw std::runtime_error("Wrong type of conversation");
    }
}

#endif