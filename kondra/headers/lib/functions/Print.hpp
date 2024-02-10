#ifndef Print_HPP
#define Print_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class Print : public Function
{
public:
    Print();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Print::Print() {}

Value *Print::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    switch (end - begin)
    {
    case 0:
        std::cout << std::endl;
        break;

    case 1:
        std::cout << *begin << std::endl;
        break;

    case 2:
        std::cout << *begin << *(begin + 1);
        break;
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    return new VarValue(kondra::var());
}

#endif