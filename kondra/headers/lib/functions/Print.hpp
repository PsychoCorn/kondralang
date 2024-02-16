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
    if (end - begin == 0)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    for (; begin != end; begin++)
    {
        std::cout << *begin;
    }
    return new VarValue(kondra::var(), true);
}

class Println0 : public Function
{
public:
    Println0();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Println0::Println0() {}

Value *Println0::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    std::cout << std::endl;
    return new VarValue(kondra::var(), true);
}

class Println : public Function
{
public:
    Println();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Println::Println() {}

Value *Println::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    for (; begin != end; begin++)
    {
        std::cout << *begin;
    }
    std::cout << std::endl;
    return new VarValue(kondra::var(), true);
}

#endif