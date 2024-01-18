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
std::unordered_map<std::string, double> Variables<double>::variables = {
    {"_PI_", std::numbers::pi},
    {"_E_", std::numbers::e},
    {"_INF_", INFINITY},
    {"_NAN_", NAN}
};

template<>
Type Variables<double>::type = Type::Float64;

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

    case Type::Float64:
        if (type == Float64)
            return variables[key];
        return Variables<double>::get(key);
        break;

    case Type::UInt64:
        if (type == UInt64)
            return variables[key];
        return Variables<unsigned long long>::get(key);
        break;
    
    default:
        return 0;
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