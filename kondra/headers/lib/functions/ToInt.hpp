#ifndef ToInt_HPP
#define ToInt_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToInt0 : public Function
{
public:
    ToInt0();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToInt0::ToInt0() {}

Value *ToInt0::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new IValue(static_cast<kondra::dynamic_int>(0));
}

class ToInt1 : public Function
{
public:
    ToInt1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToInt1::ToInt1() {}

Value *ToInt1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new IValue(static_cast<kondra::dynamic_int>((*begin)->varGet()));
}

class ToInt2 : public Function
{
public:
    ToInt2();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToInt2::ToInt2() {}

Value *ToInt2::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new IValue(kondra::dynamic_int((*begin)->strGet(), (*(begin + 1))->ui64Get()));
}

#endif