#ifndef ToInt_HPP
#define ToInt_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToInt : public Function
{
public:
    ToInt();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToInt::ToInt() {}

Value *ToInt::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    auto arg = *begin;
    return new IValue(static_cast<kondra::dynamic_int>(arg->varGet()));
}


#endif