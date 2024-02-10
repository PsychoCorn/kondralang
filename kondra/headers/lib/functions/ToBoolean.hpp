#ifndef ToBoolean_HPP
#define ToBoolean_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToBoolean : public Function
{
public:
    ToBoolean();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToBoolean::ToBoolean() {}

Value *ToBoolean::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    auto arg = *begin;
    return new BValue(static_cast<bool>(arg->varGet()));
}


#endif