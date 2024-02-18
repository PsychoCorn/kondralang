#ifndef ToBoolean_HPP
#define ToBoolean_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"
#include "../types/BValue.hpp"

class ToBoolean0 : public Function
{
public:
    ToBoolean0();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToBoolean0::ToBoolean0() {}

Value *ToBoolean0::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new BValue(static_cast<bool>(false), true);
}

class ToBoolean1 : public Function
{
public:
    ToBoolean1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToBoolean1::ToBoolean1() {}

Value *ToBoolean1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new BValue(static_cast<bool>((*begin)->varGet()), true);
}

#endif