#ifndef kondraio_HPP
#define kondraio_HPP

#include "../types/String.hpp"

namespace kondra
{

inline void println()
{
    std::cout << std::endl;
}

template <typename T, typename... Args>
inline void println(T first, Args... args)
{
    std::cout << first << " ";
    println(args...);
}

template <typename T>
inline void print(T arg)
{
    std::cout << arg;
}

template <typename T, typename... Args>
inline void print(T first, Args... args)
{
    std::cout << first << " ";
    print(args...);
}

inline kondra::string input(const kondra::string& prompt = "") 
{
    kondra::string userInput;
    std::cout << prompt;
    std::getline(std::cin, userInput);
    return userInput;
}

template<typename... Args>
inline void printf(const kondra::string& fstring, Args... args)
{
    std::printf(fstring.c_str(), args...);
}

}

#endif