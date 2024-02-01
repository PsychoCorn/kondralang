#ifndef Variables_HPP
#define Variables_HPP

#include "ListOfVariables.hpp"
#include "../types/kondratypes.hpp"
#include "../io/kondraio.hpp"
#include "KeyWords.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>
#include <numbers>

#define ERR_MSG_UNKN_ID "Unknown identifier"
#define ERR_MSG_ID_CANT_BE_REDEF "Identifier can't be redefined"

template <class T>
class Variables
{
private:
    static std::unordered_map<std::string, T> variables;
    static Type type;
    
public:
    static T get(std::string);
    static void set(std::string, T);
    static void create(std::string, T);
};

template<>
std::unordered_map<std::string, bool> Variables<bool>::variables = {
    {"true", true},
    {"false", false}
};

template<>
Type Variables<bool>::type = Type::Bool;

template<>
std::unordered_map<std::string, double> Variables<double>::variables = {
    {"_PI_", std::numbers::pi},
    {"_E_", std::numbers::e},
    {"_INF_", INFINITY},
    {"_NAN_", NAN}
};

template<>
Type Variables<double>::type = Type::Float64;

template<>
std::unordered_map<std::string, float> Variables<float>::variables = {};

template<>
Type Variables<float>::type = Type::Float32;

template<>
std::unordered_map<std::string, long double> Variables<long double>::variables = {};

template<>
Type Variables<long double>::type = Type::Float80;

template<>
std::unordered_map<std::string, long long> Variables<long long>::variables = {
    {"_NULL_", 0},
    {"_I64_MAX_", std::numeric_limits<long long>::max()},
    {"_I64_MIN_", std::numeric_limits<long long>::min()}
};

template<>
Type Variables<long long>::type = Type::Int64;

template<>
std::unordered_map<std::string, unsigned long long> Variables<unsigned long long>::variables = {
    {"_UI64_MAX_", std::numeric_limits<unsigned long long>::max()},
};

template<>
Type Variables<unsigned long long>::type = Type::UInt64;

template<>
std::unordered_map<std::string, int> Variables<int>::variables = {
    {"_I32_MAX_", std::numeric_limits<int>::max()},
    {"_I32_MIN_", std::numeric_limits<int>::min()},
};

template<>
Type Variables<int>::type = Type::Int32;

template<>
std::unordered_map<std::string, unsigned int> Variables<unsigned int>::variables = {
    {"_UI32_MAX_", std::numeric_limits<unsigned int>::max()},
};

template<>
Type Variables<unsigned int>::type = Type::UInt32;

template<>
std::unordered_map<std::string, short> Variables<short>::variables = {
    {"_I16_MAX_", std::numeric_limits<short>::max()},
    {"_I16_MIN_", std::numeric_limits<short>::min()},
};

template<>
Type Variables<short>::type = Type::Int16;

template<>
std::unordered_map<std::string, unsigned short> Variables<unsigned short>::variables = {
    {"_UI16_MAX_", std::numeric_limits<unsigned short>::max()},
};

template<>
Type Variables<unsigned short>::type = Type::UInt16;

template<>
std::unordered_map<std::string, signed char> Variables<signed char>::variables = {
    {"_I8_MAX_", std::numeric_limits<signed char>::max()},
    {"_I8_MIN_", std::numeric_limits<signed char>::min()},
};

template<>
Type Variables<signed char>::type = Type::Int8;

template<>
std::unordered_map<std::string, unsigned char> Variables<unsigned char>::variables = {
    {"_UI8_MAX_", std::numeric_limits<unsigned char>::max()},
};

template<>
Type Variables<unsigned char>::type = Type::UInt8;

template<>
std::unordered_map<std::string, kondra::dynamic_int> Variables<kondra::dynamic_int>::variables = {};

template<>
Type Variables<kondra::dynamic_int>::type = Type::Int;

template<>
std::unordered_map<std::string, kondra::string> Variables<kondra::string>::variables = {
    {"_ENDL_", "\n"},
};

template<>
Type Variables<kondra::string>::type = Type::String;

template<>
std::unordered_map<std::string, kondra::var> Variables<kondra::var>::variables = {};

template<>
Type Variables<kondra::var>::type = Type::Var;

template<>
kondra::string Variables<kondra::string>::get(std::string key)
{
    switch (ListOfVariables::getType(key))
    {
    case Type::None:
        throw std::runtime_error(ERR_MSG_UNKN_ID);
    
    case Type::Int64:
        return kondra::to_string(Variables<long long>::get(key));

    case Type::Int32:
        return kondra::to_string(Variables<int>::get(key));

    case Type::Int16:
        return kondra::to_string(Variables<short>::get(key));

    case Type::Int8:
        return kondra::to_string(Variables<signed char>::get(key));

    case Type::Float32:
        return kondra::to_string(Variables<float>::get(key));

    case Type::Float64:
        return kondra::to_string(Variables<double>::get(key));

    case Type::Float80:
        return kondra::to_string(Variables<long double>::get(key));

    case Type::UInt64:
        return kondra::to_string(Variables<unsigned long long>::get(key));

    case Type::UInt32:
        return kondra::to_string(Variables<unsigned int>::get(key));

    case Type::UInt16:
        return kondra::to_string(Variables<unsigned short>::get(key));

    case Type::UInt8:
        return kondra::to_string(Variables<unsigned char>::get(key));

    case Type::Int:
        return kondra::to_string(Variables<kondra::dynamic_int>::get(key));

    case Type::Bool:
        return kondra::to_string(Variables<bool>::get(key));

    case Type::Var:
        return kondra::to_string(Variables<kondra::var>::get(key));
    
    case Type::String:
        return variables[key];
    
    default:
        return "";
    }
}

template<class T>
T Variables<T>::get(std::string key)
{
    switch (ListOfVariables::getType(key))
    {
    case Type::None:
        throw std::runtime_error(ERR_MSG_UNKN_ID);
    
    case Type::Int64:
        if (type == Int64)
            return variables[key];
        return static_cast<T>(Variables<long long>::get(key));

    case Type::Int32:
        if (type == Int32)
            return variables[key];
        return static_cast<T>(Variables<int>::get(key));

    case Type::Int16:
        if (type == Int16)
            return variables[key];
        return static_cast<T>(Variables<short>::get(key));

    case Type::Int8:
        if (type == Int8)
            return variables[key];
        return static_cast<T>(Variables<signed char>::get(key));

    case Type::Float32:
        if (type == Float32)
            return variables[key];
        return static_cast<T>(Variables<float>::get(key));

    case Type::Float64:
        if (type == Float64)
            return variables[key];
        return static_cast<T>(Variables<double>::get(key));

    case Type::Float80:
        if (type == Float80)
            return variables[key];
        return static_cast<T>(Variables<long double>::get(key));

    case Type::UInt64:
        if (type == UInt64)
            return variables[key];
        return static_cast<T>(Variables<unsigned long long>::get(key));

    case Type::UInt32:
        if (type == UInt32)
            return variables[key];
        return static_cast<T>(Variables<unsigned int>::get(key));

    case Type::UInt16:
        if (type == UInt16)
            return variables[key];
        return static_cast<T>(Variables<unsigned short>::get(key));

    case Type::UInt8:
        if (type == UInt8)
            return variables[key];
        return static_cast<T>(Variables<unsigned char>::get(key));

    case Type::Int:
        if (type == Int)
            return variables[key];
        return static_cast<T>(Variables<kondra::dynamic_int>::get(key));

    case Type::Bool:
        if (type == Bool)
            return variables[key];
        return static_cast<T>(Variables<bool>::get(key));

    case Type::Var:
        if (type == Var)
            return variables[key];
        return static_cast<T>(Variables<kondra::var>::get(key));

    case Type::String:
        if (type == String)
            return variables[key];
        return static_cast<T>(Variables<kondra::string>::get(key));
    
    default:
        return static_cast<T>(0);
    }
}

template <class T>
void Variables<T>::set(std::string key, T value)
{
    if (ListOfVariables::getType(key) != Variables<T>::type)
        throw std::runtime_error(ERR_MSG_UNKN_ID);
    variables[key] = value;
}

template <class T>
void Variables<T>::create(std::string key, T value)
{
    Type typeOfVar = ListOfVariables::getType(key);
    if (typeOfVar != Variables<T>::type && typeOfVar != Type::None)
        throw std::runtime_error(ERR_MSG_ID_CANT_BE_REDEF);
    variables[key] = value;
    ListOfVariables::setType(key, Variables<T>::type);
}

#endif