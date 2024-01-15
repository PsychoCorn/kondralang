#ifndef Consts_HPP
#define Consts_HPP

#include <unordered_map>
#include <string>
#include <numbers>

class Constants
{
private:
    static std::unordered_map<std::string, double> constants;
public:
    static bool isExist(std::string);
    static double get(std::string);
};

#endif