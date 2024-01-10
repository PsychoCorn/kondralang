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
    char fillChar = ' ';
    char allignSide = '\0';
    bool convertToHex = false;
    bool allignLeft = false;
    bool allignRight = false;
    bool allignCenter = false;
    bool fillWithZero = false;
    std::string numOfAllignment = "";
    constexpr auto parse(std::format_parse_context& ctx)
    {
        auto pos = ctx.begin();
        if (*(pos + 1) == '<' || *(pos + 1) == '>' || *(pos + 1) == '^')
        {
            if (*(pos + 1) == '<')
            {
                allignRight = true;
            }
            else if (*(pos + 1) == '>')
            {
                allignLeft = true;
            }
            else if (*(pos + 1) == '^')
            {
                allignCenter = true;
            }
            allignSide = *(pos + 1);
            fillChar = *pos;
            numOfAllignment = std::string(pos + 2, ctx.end());
            pos += 2;
        }
        else if (*pos >= '0' && *pos <= '9')
        {
            allignLeft = true;
            fillChar = (*pos == '0') ? '0' : ' ';
            numOfAllignment = std::string(pos, ctx.end());
            ++pos;
        }
        else if (*pos == '<' || *pos == '>' || *pos == '^')
        {
            allignLeft = true;
            numOfAllignment = std::string(pos + 1, ctx.end());
        }
        while (pos != ctx.end() && *pos != '}') 
        {
            if (*pos == 'x' || *pos == 'X')
                convertToHex = true;
            ++pos;
        }
        return pos;
    }

    auto format(const kondra::dynamic_int& diNum, std::format_context& ctx) const
    {
        kondra::string sNum = (convertToHex) ? diNum.strGetNumber(16) : diNum.strGetNumber();
        if (allignLeft)
        {
            sNum.allignString(std::stoull(numOfAllignment), fillChar);
        }
        else if (allignRight)
        {
            sNum.allignString(std::stoull(numOfAllignment), fillChar, true);
        }
        else if (allignCenter)
        {
            sNum.centerAllignString(std::stoull(numOfAllignment), fillChar);
        }
        return formatter.format(sNum, ctx);
    }
};

template <>
struct std::formatter<kondra::var> : std::formatter<kondra::string>
{
    auto format(const kondra::var& v, std::format_context& ctx) const
    {
        return formatter<kondra::string>::format(
            std::format("{}", *(kondra::toString(v).getData().stringData)), ctx);
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