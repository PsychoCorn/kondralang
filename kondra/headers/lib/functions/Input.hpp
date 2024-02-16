#ifndef Input_HPP
#define Input_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class Input0 : public Function
{
public:
    Input0();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Input0::Input0() {}

Value *Input0::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    kondra::string input;
    std::cin >> input;
    return new StrValue(input, true);
}

class Input1 : public Function
{
public:
    Input1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Input1::Input1() {}

Value *Input1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    kondra::string input;
    std::cout << *begin;
    std::cin >> input;
    return new StrValue(input, true);
}

#endif