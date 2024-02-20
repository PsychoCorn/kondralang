#ifndef ArrayIterator_HPP
#define ArrayIterator_HPP

#include "ValueIterator.hpp"
#include "../Value.hpp"
#include "../../../types/Array.hpp"

class ArrayIterator : public Iterator
{
public:
    kondra::array<Value *>::iterator data;

    ArrayIterator(const kondra::array<Value *>::iterator &);
    IterType getType() const override;
    void setValue(Value *) override;
};

ArrayIterator::ArrayIterator(const kondra::array<Value *>::iterator &data)
{
    this->data = data;
}

IterType ArrayIterator::getType() const
{
    return IterType::ArrayIter;
}

void ArrayIterator::setValue(Value *value)
{
    (*data)->setValue(value);
}

class ReverseArrayIterator : public Iterator
{
public:
    kondra::array<Value *>::reverse_iterator data;

    ReverseArrayIterator(const kondra::array<Value *>::reverse_iterator &);
    IterType getType() const override;
    void setValue(Value *) override;
};

ReverseArrayIterator::ReverseArrayIterator(const kondra::array<Value *>::reverse_iterator &data)
{
    this->data = data;
}

IterType ReverseArrayIterator::getType() const
{
    return IterType::RArrayIter;
}

void ReverseArrayIterator::setValue(Value *value)
{
    (*data)->setValue(value);
}

#endif