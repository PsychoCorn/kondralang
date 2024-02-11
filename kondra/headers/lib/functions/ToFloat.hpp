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
    switch (end - begin)
    {
    case 0:
        return new F64Value(static_cast<double>(.0f));

    case 1:
        return new F64Value(static_cast<double>((*begin)->varGet()));
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
}


#endif