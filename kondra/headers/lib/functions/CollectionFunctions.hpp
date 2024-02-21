#ifndef CollectionFunctions_HPP
#define CollectionFunctions_HPP

#include "Function.hpp"
#include "../types/CollectionValue.hpp"

class Size1 : public Function
{
public:
    Size1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Size1::Size1() {}

Value *Size1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<CollectionValue *>(*begin);
    if (arg == nullptr)
        throw std::runtime_error("Not collection in size function");
    return new IValue(arg->size(), true);
}

class IterSet2 : public Function
{
public:
    IterSet2();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

IterSet2::IterSet2() {}

Value *IterSet2::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 2)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg1 = dynamic_cast<IterValue *>(*begin);
    if (arg1 == nullptr)
    {
        arg1 = dynamic_cast<IterValue *>(dynamic_cast<RefValue *>(*begin)->getValue());
        if (arg1 == nullptr)
            throw std::runtime_error("Not iterator in iterSet function");
    }
    if (arg1->getIsConst())
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    arg1->getIter()->setValue(*(begin + 1));
    return new VarValue(kondra::var(), true);
}

class IterGet1 : public Function
{
public:
    IterGet1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

IterGet1::IterGet1() {}

Value *IterGet1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<IterValue *>(*begin);
    if (arg == nullptr)
    {
        arg = dynamic_cast<IterValue *>(dynamic_cast<RefValue *>(*begin)->getValue());
        if (arg == nullptr)
            throw std::runtime_error("Not iterator in iterGet function");
    }
    auto iter = arg->getIter();
    switch (iter->getType())
    {
    case IterType::StringIter:
        return new StrValue(kondra::string(1, *static_cast<StringIterator *>(iter)->data), true);
    case IterType::RStringIter:
        return new StrValue(kondra::string(1, *static_cast<ReverseStringIterator *>(iter)->data), true);
    case IterType::ArrayIter:
        return *static_cast<ArrayIterator *>(iter)->data;
    case IterType::RArrayIter:
        return *static_cast<ReverseArrayIterator *>(iter)->data;
    default:
        throw std::runtime_error("Unknown type of iterator");
    }
}

class Begin1 : public Function
{
public:
    Begin1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Begin1::Begin1() {}

Value *Begin1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<CollectionValue *>(*begin);
    if (arg == nullptr)
        throw std::runtime_error("Not collection in size function");
    return arg->begin();
}

class End1 : public Function
{
public:
    End1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

End1::End1() {}

Value *End1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<CollectionValue *>(*begin);
    if (arg == nullptr)
        throw std::runtime_error("Not collection in size function");
    return arg->end();
}

class RBegin1 : public Function
{
public:
    RBegin1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

RBegin1::RBegin1() {}

Value *RBegin1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<CollectionValue *>(*begin);
    if (arg == nullptr)
        throw std::runtime_error("Not collection in size function");
    return arg->rbegin();
}

class REnd1 : public Function
{
public:
    REnd1();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

REnd1::REnd1() {}

Value *REnd1::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin != 1)
    {
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    }
    auto arg = dynamic_cast<CollectionValue *>(*begin);
    if (arg == nullptr)
        throw std::runtime_error("Not collection in size function");
    return arg->rend();
}

#endif