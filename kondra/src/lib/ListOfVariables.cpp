#include "../../headers/lib//ListOfVariables.hpp"
#include <stdexcept>

std::unordered_map<std::string, Type> ListOfVariables::listOfVariables = {
    {"_PI_", Type::Float64},
    {"_E_", Type::Float64},
    {"_INF_", Type::Float64},
    {"_NAN_", Type::Float64},
    {"_I64_MAX_", Type::Int64},
    {"_I64_MIN_", Type::Int64},
    {"_NULL_", Type::Int64},
    {"_UI64_MAX_", Type::UInt64}
};

Type ListOfVariables::getType(std::string key)
{
    if (listOfVariables.find(key) != listOfVariables.end())
        return listOfVariables[key];
    return Type::None;
}

void ListOfVariables::setType(std::string key, Type newType)
{
    listOfVariables[key] = newType;
}

std::unordered_map<std::string, Type> ListOfVariables::getList()
{
    return listOfVariables;
}