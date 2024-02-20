#ifndef StringIterator_HPP
#define StringIterator_HPP

#include "ValueIterator.hpp"
#include "../../../types/String.hpp"

class StringIterator : public Iterator
{
public:
    kondra::string::iterator data;

    StringIterator(const kondra::string::iterator &);
    IterType getType() const override;
    void setValue(Value *) override;
};

StringIterator::StringIterator(const kondra::string::iterator &data)
{
    this->data = data;
}

IterType StringIterator::getType() const
{
    return IterType::StringIter;
}

void StringIterator::setValue(Value *value)
{
    *data = value->strGet()[0];
}

class ReverseStringIterator : public Iterator
{
public:
    kondra::string::reverse_iterator data;

    ReverseStringIterator(const kondra::string::reverse_iterator &);
    IterType getType() const override;
    void setValue(Value *) override;
};

ReverseStringIterator::ReverseStringIterator(const kondra::string::reverse_iterator &data)
{
    this->data = data;
}

IterType ReverseStringIterator::getType() const
{
    return IterType::RStringIter;
}

void ReverseStringIterator::setValue(Value *value)
{
    *data = value->strGet()[0];
}

#endif