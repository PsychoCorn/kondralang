#ifndef CollectionValue_HPP
#define CollectionValue_HPP

#include "IterValue.hpp"

class CollectionValue : public Value // interface
{
public:
    virtual size_t size() const = 0;
    virtual IterValue *begin() = 0;
    virtual IterValue *end() = 0;
    virtual IterValue *rbegin() = 0;
    virtual IterValue *rend() = 0;
    virtual void setByIndex(Value *, const int64_t &) = 0;
    virtual Value *getByIndex(long long) const = 0;
    
};

#endif