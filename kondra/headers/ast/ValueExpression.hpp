#ifndef ValueExpression_HPP
#define ValueExpression_HPP

#include "Expression.hpp"

class ValueExpression : public Expression
{
private:
    Value *value;
public:
    ValueExpression(Value *);
    Value *eval() override;
};

ValueExpression::ValueExpression(Value *value)
{
    this->value = value;
}


Value *ValueExpression::eval()
{
    return value;
}

#endif