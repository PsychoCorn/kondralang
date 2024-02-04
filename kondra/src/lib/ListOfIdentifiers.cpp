#include "../../headers/lib//ListOfIdentifiers.hpp"
#include <stdexcept>

std::unordered_map<std::string, Type> ListOfIdentifiers::listOfIdentifiers = {
    {"_PI_", Type::Float64},
    {"_E_", Type::Float64},
    {"_INF_", Type::Float64},
    {"_NAN_", Type::Float64},
    {"_I64_MAX_", Type::Int64},
    {"_I64_MIN_", Type::Int64},
    {"_NULL_", Type::Int64},
    {"_UI64_MAX_", Type::UInt64},
    {"_I32_MAX_", Type::Int32},
    {"_I32_MIN_", Type::Int32},
    {"_UI32_MAX_", Type::UInt32},
    {"_I16_MAX_", Type::Int16},
    {"_I16_MIN_", Type::Int16},
    {"_UI16_MAX_", Type::UInt16},
    {"_I8_MAX_", Type::Int8},
    {"_I8_MIN_", Type::Int8},
    {"_UI8_MAX_", Type::UInt8},
    {"true", Type::Bool},
    {"false", Type::Bool},
    {"_ENDL_", Type::String},
    {"_NONE_", Type::Var},
};

Type ListOfIdentifiers::getType(std::string key)
{
    if (listOfIdentifiers.find(key) != listOfIdentifiers.end())
        return listOfIdentifiers[key];
    return Type::None;
}

void ListOfIdentifiers::setType(std::string key, Type newType)
{
    listOfIdentifiers[key] = newType;
}

std::unordered_map<std::string, Type> ListOfIdentifiers::getList()
{
    return listOfIdentifiers;
}