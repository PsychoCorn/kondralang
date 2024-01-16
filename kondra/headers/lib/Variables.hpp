#ifndef Variables_HPP
#define Variables_HPP

#include <unordered_map>
#include <string>
#include <numbers>

class Variables
{
private:
    static std::unordered_map<std::string, double> variables;
public:
    static bool isExist(std::string);
    static double get(std::string);
    static void set(std::string, double);
    static void create(std::string, double);
};

#endif