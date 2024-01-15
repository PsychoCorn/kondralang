#include "../../headers/lib/Constants.hpp"

#include <stdexcept>

std::unordered_map<std::string, double> Constants::constants = {
    {"_PI_", std::numbers::pi},
    {"_E_", std::numbers::e},
    {"_NULL_", 0}
};

bool Constants::isExist(std::string key)
{
    return constants.find(key) != constants.end();
}

double Constants::get(std::string key)
{
    if (!isExist(key))
        throw std::runtime_error("Unknown identifier");
    return constants[key];
}