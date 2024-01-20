#ifndef Variables_HPP
#define Variables_HPP

#include "ListOfVariables.hpp"
#include "KeyWords.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>
#include <numbers>

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

#define ERR_MSG_UNKN_ID "Unknown identifier"

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
    {"_I64_MAX_", _I64_MAX},
    {"_I64_MIN_", _I64_MIN}
};

template<>
Type Variables<long long>::type = Type::Int64;

template<>
std::unordered_map<std::string, unsigned long long> Variables<unsigned long long>::variables = {
    {"_UI64_MAX_", _UI64_MAX},
};

template<>
Type Variables<unsigned long long>::type = Type::UInt64;

template<>
std::unordered_map<std::string, int> Variables<int>::variables = {
    {"_I32_MAX_", _I32_MAX},
    {"_I32_MIN_", _I32_MIN},
};

template<>
Type Variables<int>::type = Type::Int32;

template<>
std::unordered_map<std::string, unsigned int> Variables<unsigned int>::variables = {
    {"_UI32_MAX_", _UI32_MAX},
};

template<>
Type Variables<unsigned int>::type = Type::UInt32;

template<>
std::unordered_map<std::string, short int> Variables<short int>::variables = {
    {"_I16_MAX_", _I16_MAX},
    {"_I16_MIN_", _I16_MIN},
};

template<>
Type Variables<short int>::type = Type::Int16;

template<>
std::unordered_map<std::string, unsigned short int> Variables<unsigned short int>::variables = {
    {"_UI16_MAX_", _UI16_MAX},
};

template<>
Type Variables<unsigned short int>::type = Type::UInt16;

template<>
std::unordered_map<std::string, signed char> Variables<signed char>::variables = {
    {"_I8_MAX_", _I8_MAX},
    {"_I8_MIN_", _I8_MIN},
};

template<>
Type Variables<signed char>::type = Type::Int8;

template<>
std::unordered_map<std::string, unsigned char> Variables<unsigned char>::variables = {
    {"_UI8_MAX_", _UI8_MAX},
};

template<>
Type Variables<unsigned char>::type = Type::UInt8;

template<>
std::unordered_map<std::string, std::string> Variables<std::string>::variables = {
    {"_ENDL_", "\n"},
};

template<>
Type Variables<std::string>::type = Type::String;

template<class T>
T Variables<T>::get(std::string key)
{
    switch (ListOfVariables::getType(key))
    {
    case Type::None:
        throw std::runtime_error(ERR_MSG_UNKN_ID);
        break;
    
    case Type::Int64:
        if (type == Int64)
            return variables[key];
        return Variables<long long>::get(key);
        break;

    case Type::Int32:
        if (type == Int32)
            return variables[key];
        return Variables<int>::get(key);
        break;

    case Type::Int16:
        if (type == Int16)
            return variables[key];
        return Variables<short int>::get(key);
        break;

    case Type::Int8:
        if (type == Int8)
            return variables[key];
        return Variables<signed char>::get(key);
        break;

    case Type::Float32:
        if (type == Float32)
            return variables[key];
        return Variables<float>::get(key);
        break;

    case Type::Float64:
        if (type == Float64)
            return variables[key];
        return Variables<double>::get(key);
        break;

    case Type::Float80:
        if (type == Float80)
            return variables[key];
        return Variables<long double>::get(key);
        break;

    case Type::UInt64:
        if (type == UInt64)
            return variables[key];
        return Variables<unsigned long long>::get(key);
        break;

    case Type::UInt32:
        if (type == UInt32)
            return variables[key];
        return Variables<unsigned int>::get(key);
        break;

    case Type::UInt16:
        if (type == UInt16)
            return variables[key];
        return Variables<unsigned short int>::get(key);
        break;

    case Type::UInt8:
        if (type == UInt8)
            return variables[key];
        return Variables<unsigned char>::get(key);
        break;

    case Type::Bool:
        if (type == Bool)
            return variables[key];
        return Variables<bool>::get(key);
        break;
    
    default:
        return 0;
        break;
    }
}

template<>
std::string Variables<std::string>::get(std::string key)
{
    switch (ListOfVariables::getType(key))
    {
    case Type::None:
        throw std::runtime_error(ERR_MSG_UNKN_ID);
        break;
    
    case Type::Int64:
        return std::to_string(Variables<long long>::get(key));
        break;

    case Type::Int32:
        return std::to_string(Variables<int>::get(key));
        break;

    case Type::Int16:
        return std::to_string(Variables<short int>::get(key));
        break;

    case Type::Int8:
        return std::to_string(Variables<signed char>::get(key));
        break;

    case Type::Float32:
        return std::to_string(Variables<float>::get(key));
        break;

    case Type::Float64:
        return std::to_string(Variables<double>::get(key));
        break;

    case Type::Float80:
        return std::to_string(Variables<long double>::get(key));
        break;

    case Type::UInt64:
        return std::to_string(Variables<unsigned long long>::get(key));
        break;

    case Type::UInt32:
        return std::to_string(Variables<unsigned int>::get(key));
        break;

    case Type::UInt16:
        return std::to_string(Variables<unsigned short int>::get(key));
        break;

    case Type::UInt8:
        return std::to_string(Variables<unsigned char>::get(key));
        break;

    case Type::Bool:
        return std::to_string(Variables<bool>::get(key));
        break;
    
    case Type::String:
        return variables[key];
        break;
    
    default:
        return "";
        break;
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
        throw std::runtime_error("Identifier can't be redefined!");
    variables[key] = value;
    ListOfVariables::setType(key, Variables<T>::type);
}

#endif