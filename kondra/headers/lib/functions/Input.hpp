#ifndef Input_HPP
#define Input_HPP

#include "Function.hpp"
#include "../types/VarValue.hpp"

class Input : public Function
{
public:
    Input();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Input::Input() {}

Value *Input::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    switch (end - begin)
    {
    case 0:
        break;

    case 1:
        std::cout << *begin;
        break;
        
    default:
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    kondra::string input;
    std::cin >> input;
    return new StrValue(input);
}

#endif