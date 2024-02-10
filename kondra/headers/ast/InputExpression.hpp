#ifndef InputExpression_HPP
#define InputExpression_HPP

#include "Expression.hpp"
#include "../types/String.hpp"
#include <iostream>


class InputExpression final : public Expression
{
private:

public:
    InputExpression();
    Value *eval() override;
};

InputExpression::InputExpression() {}

Value *InputExpression::eval()
{
    kondra::string input;
    std::cin >> input;
    return new StrValue(input);
}

#endif