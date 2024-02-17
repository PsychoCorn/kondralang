#ifndef PtrFunctions_HPP
#define PtrFunctions_HPP

#include "Function.hpp"
#include "../types/PtrValue.hpp"
#include "../types/VarValue.hpp"
#include "../types/BValue.hpp"
#include "../types/ValueCreator.hpp"

class Free : public Function
{
public:
    Free();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Free::Free() {}

Value *Free::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin == 0)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    for (; begin != end; begin++)
    {
        auto arg = dynamic_cast<PtrValue *>(*begin);
        if (arg == nullptr)
            throw std::runtime_error("Not ptr in free function");
        arg->free();
    }
    return new VarValue(kondra::var(), true);
}

class Delete : public Function
{
public:
    Delete();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Delete::Delete() {}

Value *Delete::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin == 0)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    for (; begin != end; begin++)
    {
        auto arg = dynamic_cast<PtrValue *>(*begin);
        if (arg == nullptr)
            throw std::runtime_error("Not ptr in delete function");
        arg->del();
    }
    return new VarValue(kondra::var(), true);
}

class IsNullPtr1 : public Function
{
public:
    IsNullPtr1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

IsNullPtr1::IsNullPtr1() {}

Value *IsNullPtr1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<PtrValue *>(*begin);
    if (arg == nullptr)
        throw std::runtime_error("Not ptr in isNullPtr function");
    return new BValue(arg->isNullPtr(), true);
}

class New1 : public Function
{
public:
    New1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

New1::New1() {}

Value *New1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    return ValueCreator::createValue((*begin), false);
}

#endif