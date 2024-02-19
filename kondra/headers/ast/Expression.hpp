#ifndef Expression_HPP
#define Expression_HPP

#include "../lib/types/ValueCreator.hpp"

class Expression //interface
{
public:
    virtual ~Expression() {}
    virtual Value *eval() = 0;
};

#endif