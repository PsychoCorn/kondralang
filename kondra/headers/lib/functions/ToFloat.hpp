#ifndef ToFloat_HPP
#define ToFloat_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToFloat0 : public Function
{
public:
    ToFloat0();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToFloat0::ToFloat0() {}

Value *ToFloat0::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new F64Value(static_cast<double>(.0f), true);
}

class ToFloat1 : public Function
{
public:
    ToFloat1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToFloat1::ToFloat1() {}

Value *ToFloat1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new F64Value(static_cast<double>((*begin)->varGet()), true);
}


#endif