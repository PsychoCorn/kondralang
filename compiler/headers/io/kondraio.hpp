#ifndef kondraio_HPP
#define kondraio_HPP

#include <format>
#include "../types/kondratypes.hpp"

#define ERR_MSG_NUM_ARG "Wrong number of arguments!"

template <>
struct std::formatter<kondra::string> : public std::formatter<std::string>{};

template <>
struct std::formatter<kondra::dynamic_int>
{
    std::formatter<kondra::string> formatter;
    constexpr auto parse(std::format_parse_context& ctx)
    {
        return formatter.parse(ctx);
    }

    auto format(const kondra::dynamic_int& s, std::format_context& ctx) const
    {
        return formatter.format(s.strGetNumber(), ctx);
    }
};

template <>
struct std::formatter<kondra::var>
{
    std::formatter<kondra::string> formatter;
    constexpr auto parse(std::format_parse_context& ctx)
    {
        return formatter.parse(ctx);
    }

    auto format(const kondra::var& v, std::format_context& ctx) const
    {
        return formatter.format(*(toString(v).getData().stringData), ctx);
    }
};

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

    inline kondra::string input(const kondra::string &prompt = "")
    {
        kondra::string userInput;
        std::cout << prompt;
        std::getline(std::cin, userInput);
        return userInput;
    }

    template <typename... Args>
    inline void printf(const char* fstring, Args... args)
    {
        std::printf(fstring, args...);
    }

    template <typename T>
    inline string to_string(const T& arg)
    {
        return string(std::to_string(arg));
    }

    inline string to_string(const dynamic_int& arg)
    {
        return string(arg.strGetNumber());
    }

    inline string to_string(const var& arg)
    {
        return string(*(toString(arg).getData().stringData));
    }

}

#endif