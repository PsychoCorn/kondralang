#ifndef Variables_HPP
#define Variables_HPP

#include "types/ValueCreator.hpp"
#include "../io/kondraio.hpp"
#include "KeyWords.hpp"
#include <stdexcept>
#include <limits>
#include <unordered_map>
#include <numbers>

#define ERR_MSG_UNKN_ID "Unknown identifier"
#define ERR_MSG_ID_CANT_BE_REDEF "Identifier can't be redefined"

class Variables
{
private:
    static std::unordered_map<std::string, Value *> variables;
    
public:
    static Value * get(const std::string &);
    static void set(const std::string &, Value *);
    static void create(const std::string &, const std::string &, Value *);
    static void free(const std::string &);
    static bool isVariableExist(const std::string &);
};

std::unordered_map<std::string, Value *> Variables::variables = {
    {"_I8_MAX_", new I8Value(std::numeric_limits<signed char>::max())},
    {"_I8_MIN_", new I8Value(std::numeric_limits<signed char>::min())},
    {"_I16_MAX_", new I16Value(std::numeric_limits<short>::max())},
    {"_I16_MIN_", new I16Value(std::numeric_limits<short>::min())},
    {"_I32_MAX_", new I32Value(std::numeric_limits<int>::max())},
    {"_I32_MIN_", new I32Value(std::numeric_limits<int>::min())},
    {"_I64_MAX_", new I64Value(std::numeric_limits<long long>::max())},
    {"_I64_MIN_", new I64Value(std::numeric_limits<long long>::min())},
    {"_UI8_MAX_", new UI8Value(std::numeric_limits<unsigned char>::max())},
    {"_UI16_MAX_", new UI16Value(std::numeric_limits<unsigned short>::max())},
    {"_UI32_MAX_", new UI32Value(std::numeric_limits<unsigned int>::max())},
    {"_UI64_MAX_", new UI64Value(std::numeric_limits<unsigned long long>::max())},
    {"_INF_", new F64Value(std::numeric_limits<double>::infinity())},
    {"_NAN_", new F64Value(std::numeric_limits<double>::quiet_NaN())},
    {"_NULL_", new I64Value(0ull)},
    {"_ENDL_", new StrValue("\n")},
    {"_NONE_", new VarValue(kondra::var())},
};

Value *Variables::get(const std::string &key)
{
    if (isVariableExist(key))
        return variables[key];
    throw std::runtime_error(ERR_MSG_UNKN_ID);
}

void Variables::set(const std::string &key, Value *value)
{
    if (!isVariableExist(key))
        throw std::runtime_error(ERR_MSG_UNKN_ID);
    variables[key]->setValue(value);
}

void Variables::create(const std::string &type, const std::string &key, Value *value)
{
    if (isVariableExist(key))
        set(key, value);
    else if (type == "int8")
        variables[key] = new I8Value(value == nullptr ? 0 : value->i8Get());
    else if (type == "int16")
        variables[key] = new I16Value(value == nullptr ? 0 : value->i16Get());
    else if (type == "int32")
        variables[key] = new I32Value(value == nullptr ? 0 : value->i32Get());
    else if (type == "int64")
        variables[key] = new I64Value(value == nullptr ? 0 : value->i64Get());
    else if (type == "uint8")
        variables[key] = new UI8Value(value == nullptr ? 0 : value->ui8Get());
    else if (type == "uint16")
        variables[key] = new UI16Value(value == nullptr ? 0 : value->ui16Get());
    else if (type == "uint32")
        variables[key] = new UI32Value(value == nullptr ? 0 : value->ui32Get());
    else if (type == "uint64")
        variables[key] = new UI64Value(value == nullptr ? 0 : value->ui64Get());
    else if (type == "int")
        variables[key] = new IValue(value == nullptr ? 0 : value->iGet());
    else if (type == "float32")
        variables[key] = new F32Value(value == nullptr ? .0f : value->f32Get());
    else if (type == "float64")
        variables[key] = new F64Value(value == nullptr ? .0f : value->f64Get());
    else if (type == "float80")
        variables[key] = new F80Value(value == nullptr ? .0f : value->f80Get());
    else if (type == "boolean")
        variables[key] = new BValue(value == nullptr ? .0f : value->bGet());
    else if (type == "string")
        variables[key] = new StrValue(value == nullptr ? "" : value->strGet());
    else if (type == "var")
        variables[key] = new VarValue(value == nullptr ? kondra::var() : value->varGet());
    else if (type == "auto")
        variables[key] = ValueCreator::createValue(value == nullptr ? new VarValue(kondra::var()) : value);
    else
        throw std::runtime_error("Unkmown type");
}

void Variables::free(const std::string &key)
{
    if (!isVariableExist(key))
        throw std::runtime_error(ERR_MSG_UNKN_ID);
    delete variables[key];
    variables.erase(key);
}

bool Variables::isVariableExist(const std::string& key)
{
    return variables.find(key) != variables.end();
}

#endif