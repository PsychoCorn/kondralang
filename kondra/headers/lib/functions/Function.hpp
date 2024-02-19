#ifndef Function_HPP
#define Function_HPP

#include <stdexcept>
#include <vector>
#include "../types/Value.hpp"

#define ERR_MSG_WRNG_ARGS "Wrong arguments"

class Function // interface. Naming of functions = name with capital first sign + number of arguments
{
public:
    virtual Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) = 0;
};

#endif