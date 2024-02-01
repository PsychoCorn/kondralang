#ifndef InputExpression_HPP
#define InputExpression_HPP

#include "Expression.hpp"
#include "../types/String.hpp"
#include <iostream>

template <class T>
class InputExpression final : public Expression<T>
{
private:

public:
    InputExpression();
    T eval() override;
};

template<class T>
InputExpression<T>::InputExpression() {}

template<class T>
T InputExpression<T>::eval()
{
    kondra::string input;
    std::cin >> input;
    T inputValue = static_cast<T>(input);
    return inputValue;
}

template<>
signed char InputExpression<signed char>::eval()
{
    kondra::string input;
    std::cin >> input;
    int inputValue = static_cast<signed char>(input);
    return inputValue;
}

template<>
unsigned char InputExpression<unsigned char>::eval()
{
    kondra::string input;
    std::cin >> input;
    int inputValue = static_cast<unsigned char>(input);
    return inputValue;
}

#endif