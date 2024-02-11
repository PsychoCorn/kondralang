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
    std::vector<Value *> args(begin, end);
    switch (end - begin)
    {
    case 0:
        return new IValue(static_cast<kondra::dynamic_int>(0));

    case 1:
        return new IValue(static_cast<kondra::dynamic_int>(args[0]->varGet()));

    case 2:
        return new IValue(kondra::dynamic_int(args[0]->strGet(), args[1]->ui64Get()));
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
}


#endif