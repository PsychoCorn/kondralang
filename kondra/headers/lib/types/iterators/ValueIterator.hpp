#ifndef ValueIterator_HPP
#define ValueIterator_HPP

#include "../Value.hpp"

enum IterType
{
    StringIter,
    RStringIter,
    ArrayIter,
    RArrayIter,
    HashMapIter,
    RHashMapIter,
    HashMultiMapIter,
    RHashMultiMapIter,
};

class Iterator {
public:
    virtual IterType getType() const = 0;
    virtual void setValue(Value *) = 0;
};

#endif