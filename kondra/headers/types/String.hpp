#ifndef String_hpp
#define String_hpp

#include <iostream>

#define ERR_MSG_CONV_TO_BOOL "Unknown conversation to boolean"

namespace kondra
{

class String : public std::string
{
public:
    String(const char*);
    String(const std::string& = "");
    String(const String&);
    inline operator const char*();
    String operator*(const size_t&) const;
    String &operator*=(const size_t&);
    constexpr String &allignString(size_t minLength, const char& symbolToFill = ' ', bool = false);
    constexpr String &centerAllignString(size_t minLength, const char& symbolToFill = ' ');
};

constexpr String &String::allignString(size_t minLength, const char& symbolToFill, bool fillRightSide)
{
    if (length() < minLength)
    {
        String padding = "";
        size_t paddingLength = minLength - length();
        padding.append(paddingLength, symbolToFill);
        if (fillRightSide)
        {
            *this += padding;
        }
        else
        {
            *this = padding + *this;
        }
    }
    return *this;
}

constexpr String &String::centerAllignString(size_t minLength, const char& symbolToFill)
{
    if (length() < minLength)
    {
        String paddingLeft = "", paddingRight = "";
        size_t paddingLength = minLength - length();
        size_t halfPaddingLengh = paddingLength >> 1; 
        paddingLeft.append(halfPaddingLengh, symbolToFill);
        paddingRight.append(paddingLength - halfPaddingLengh, symbolToFill);
        *this += paddingRight;
        *this = paddingLeft + *this;
    }
    return *this;
}

inline String::operator const char*() 
{
    return this->c_str();
}

typedef String string;
    
}

#endif