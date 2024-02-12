#ifndef ToString_HPP
#define ToString_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToString0 : public Function
{
public:
    ToString0();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToString0::ToString0() {}

Value *ToString0::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new StrValue(static_cast<kondra::string>(""));
}

class ToString1 : public Function
{
public:
    ToString1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToString1::ToString1() {}

Value *ToString1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new StrValue(static_cast<kondra::string>((*begin)->varGet()));
}

#endif