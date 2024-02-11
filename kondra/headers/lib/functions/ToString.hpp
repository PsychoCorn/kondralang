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
    switch (end - begin)
    {
    case 0:
        return new StrValue(static_cast<kondra::string>(""));

    case 1:
        return new StrValue(static_cast<kondra::string>((*begin)->varGet()));
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
}


#endif