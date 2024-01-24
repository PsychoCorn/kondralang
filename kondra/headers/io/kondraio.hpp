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
    bool convertToHex = false;
    bool convertToOct = false;
    bool convertToBin = false;
    bool allignLeft = false;
    bool allignRight = false;
    bool allignCenter = false;
    bool fillWithZero = false;
    std::string numOfAllignment = "";
    constexpr auto parse(std::format_parse_context& ctx)
    {
        auto pos = ctx.begin();
        if ((*(pos + 1) == '<' || *(pos + 1) == '>' || *(pos + 1) == '^') && pos != ctx.end())
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
            fillChar = *pos;
            numOfAllignment = std::string(pos + 2, ctx.end());
            pos += 2;
        }
        else if ((*pos >= '0' && *pos <= '9') && pos != ctx.end())
        {
            allignLeft = true;
            fillChar = (*pos == '0') ? '0' : ' ';
            numOfAllignment = std::string(pos, ctx.end());
            ++pos;
        }
        else if ((*pos == '<' || *pos == '>' || *pos == '^') && pos != ctx.end())
        {
            allignLeft = true;
            numOfAllignment = std::string(pos + 1, ctx.end());
        }
        while (pos != ctx.end() && *pos != '}') 
        {
            if (*pos == 'x' || *pos == 'X')
            {
                convertToHex = true;
                convertToOct = false;
                convertToBin = false;
            }
            else if (*pos == 'o' || *pos == 'O')
            {
                convertToHex = false;
                convertToOct = true;
                convertToBin = false;
            }
            else if (*pos == 'b' || *pos == 'B')
            {
                convertToHex = false;
                convertToOct = false;
                convertToBin = true;
            }
            else if (*pos == 'd' || *pos == 'D')
            {
                convertToHex = false;
                convertToOct = false;
                convertToBin = false;
            }
            ++pos;
        }
        return pos;
    }

    auto format(const kondra::dynamic_int& diNum, std::format_context& ctx) const
    {
        kondra::string sNum;
        if (convertToHex)
            sNum = diNum.strGetNumber(16);
        else if (convertToOct)
            sNum = diNum.strGetNumber(8);
        else if (convertToBin)
            sNum = diNum.strGetNumber(2);
        else
            sNum = diNum.strGetNumber();
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
            std::format("{}", *(kondra::var::toString(v).getData().stringData)), ctx);
    }
};

namespace kondra
{

    inline void println()
    {
        std::cout << std::endl;
    }

    template <typename... Args>
    inline void println(bool first, Args... args)
    {
        std::cout << std::boolalpha << first << " ";
        println(args...);
    }

    template <typename... Args>
    inline void println(signed char first, Args... args)
    {
        std::cout << static_cast<int>(first) << " ";
        println(args...);
    }

    template <typename... Args>
    inline void println(unsigned char first, Args... args)
    {
        std::cout << static_cast<int>(first) << " ";
        println(args...);
    }

    template <typename T, typename... Args>
    inline void println(T first, Args... args)
    {
        std::cout << first << " ";
        println(args...);
    }

    inline void print(bool arg)
    {
        std::cout << std::boolalpha << arg;
    }

    inline void print(signed char arg)
    {
        std::cout << static_cast<int>(arg);
    }

    inline void print(unsigned char arg)
    {
        std::cout << static_cast<int>(arg);
    }

    template <typename... Args>
    inline void print(bool first, Args... args)
    {
        std::cout << std::boolalpha << first << " ";
        print(args...);
    }

    template <typename... Args>
    inline void print(signed char first, Args... args)
    {
        std::cout << static_cast<int>(first) << " ";
        print(args...);
    }

    template <typename... Args>
    inline void print(unsigned char first, Args... args)
    {
        std::cout << static_cast<int>(first) << " ";
        print(args...);
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

    inline string to_string(const dynamic_int& arg)
    {
        return string(arg.strGetNumber());
    }

    inline string to_string(const var& arg)
    {
        return string(*(var::toString(arg).getData().stringData));
    }

    inline string to_string(const string& arg)
    {
        return arg;
    }

    inline string to_string(const bool& arg)
    {
        return arg ? "true" : "false";
    }

    template <typename T>
    inline string to_string(const T& arg)
    {
        return string(std::to_string(arg));
    }

}

#endif