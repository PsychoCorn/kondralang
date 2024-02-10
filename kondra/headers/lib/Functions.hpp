#ifndef Functions_HPP
#define Functions_HPP

#include "functions/functions.hpp"
#include <unordered_map>

#define ERR_MSG_UNKN_ID "Unknown identifier"

class Functions
{
private:
    static std::unordered_map<std::string, Function *> functions;
    
public:
    static Function * get(const std::string &);
    static void set(const std::string &, Function *);
    static bool isFunctionExist(const std::string &);
};

std::unordered_map<std::string, Function *> Functions::functions = {
    {"toInt", new ToInt()},
    {"toFloat", new ToFloat()},
    {"toString", new ToString()},
    {"toBoolean", new ToBoolean()},
    {"print", new Print()},
    {"input", new Input()},
};

Function *Functions::get(const std::string &key)
{
    if (isFunctionExist(key))
        return functions[key];
    throw std::runtime_error(ERR_MSG_UNKN_ID);
}

bool Functions::isFunctionExist(const std::string& key)
{
    return functions.find(key) != functions.end();
}

void Functions::set(const std::string &key, Function *func)
{
    functions[key] = func;
}

#endif