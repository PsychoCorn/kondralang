#ifndef ToString_HPP
#define ToString_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class ToString : public Function
{
public:
    ToString();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToString::ToString() {}

Value *ToString::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    auto arg = *begin;
    return new VarValue(kondra::var::toString(arg->varGet()));
}


#endif