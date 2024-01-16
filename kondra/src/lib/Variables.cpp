#include "../../headers/lib/Variables.hpp"

#include <stdexcept>

std::unordered_map<std::string, double> Variables::variables = {
    {"_PI_", std::numbers::pi},
    {"_E_", std::numbers::e},
    {"_NULL_", 0}
};

bool Variables::isExist(std::string key)
{
    return variables.find(key) != variables.end();
}

double Variables::get(std::string key)
{
    if (!isExist(key))
        throw std::runtime_error("Unknown identifier");
    return variables[key];
}

void Variables::set(std::string key, double value)
{
    if (!isExist(key))
        throw std::runtime_error("Unknown identifier");
    variables[key] = value;
}

void Variables::create(std::string key, double value)
{
    variables[key] = value;
}