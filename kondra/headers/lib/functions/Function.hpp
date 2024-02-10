#ifndef Function_HPP
#define Function_HPP

#include <stdexcept>
#include <vector>
#include "../types/Value.hpp"

#define ERR_MSG_WRNG_ARGS "Wrong arguments"

class Function // interface
{
public:
    virtual Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) = 0;
};

#endif