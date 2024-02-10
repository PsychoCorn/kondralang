#ifndef ToFloat_HPP
#define ToFloat_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToFloat : public Function
{
public:
    ToFloat();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToFloat::ToFloat() {}

Value *ToFloat::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    auto arg = *begin;
    return new VarValue(kondra::var::toFloat(arg->varGet()));
}


#endif