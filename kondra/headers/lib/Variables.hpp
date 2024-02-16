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

#define variablesHashMap std::unordered_map<std::string, Value *>

class Variables
{
private:
    variablesHashMap variables;
    
public:
    Variables(const variablesHashMap &);
    ~Variables();
    Value * get(const std::string &);
    void set(const std::string &, Value *);
    void create(const std::string &, const std::string &, const bool &, Value *);
    bool isVariableExist(const std::string &);
};

Variables::Variables(const variablesHashMap &variables = variablesHashMap())
{
    this->variables = variables;
}

Variables::~Variables()
{
    for (auto v : variables)
    {
        delete v.second;
    }
    variables.clear();
}

Value *Variables::get(const std::string &key)
{
    return variables[key];
}

void Variables::set(const std::string &key, Value *value)
{
    variables[key]->setValue(value);
}

void Variables::create(const std::string &type, const std::string &key, const bool &isConst, Value *value)
{
    if (type == "int8")
        variables[key] = new I8Value(value == nullptr ? 0 : value->i8Get(), isConst);
    else if (type == "int16")
        variables[key] = new I16Value(value == nullptr ? 0 : value->i16Get(), isConst);
    else if (type == "int32")
        variables[key] = new I32Value(value == nullptr ? 0 : value->i32Get(), isConst);
    else if (type == "int64")
        variables[key] = new I64Value(value == nullptr ? 0 : value->i64Get(), isConst);
    else if (type == "uint8")
        variables[key] = new UI8Value(value == nullptr ? 0 : value->ui8Get(), isConst);
    else if (type == "uint16")
        variables[key] = new UI16Value(value == nullptr ? 0 : value->ui16Get(), isConst);
    else if (type == "uint32")
        variables[key] = new UI32Value(value == nullptr ? 0 : value->ui32Get(), isConst);
    else if (type == "uint64")
        variables[key] = new UI64Value(value == nullptr ? 0 : value->ui64Get(), isConst);
    else if (type == "int")
        variables[key] = new IValue(value == nullptr ? 0 : value->iGet(), isConst);
    else if (type == "float32")
        variables[key] = new F32Value(value == nullptr ? .0f : value->f32Get(), isConst);
    else if (type == "float64")
        variables[key] = new F64Value(value == nullptr ? .0f : value->f64Get(), isConst);
    else if (type == "ref")
        variables[key] = new RefValue(value == nullptr ? nullptr : &value, isConst);
    else if (type == "boolean")
        variables[key] = new BValue(value == nullptr ? .0f : value->bGet(), isConst);
    else if (type == "string")
        variables[key] = new StrValue(value == nullptr ? "" : value->strGet(), isConst);
    else if (type == "var")
        variables[key] = new VarValue(value == nullptr ? kondra::var() : value->varGet(), isConst);
    else if (type == "auto")
        variables[key] = ValueCreator::createValue(value == nullptr ? new VarValue(kondra::var(), isConst) : 
            value, isConst);
    else
        throw std::runtime_error("Unkmown type");
}

bool Variables::isVariableExist(const std::string& key)
{
    return variables.find(key) != variables.end();
}

#endif