#ifndef String_hpp
#define String_hpp

#include <iostream>

#define ERR_MSG_CONV_TO_BOOL "Unknown conversation to boolean"

namespace kondra
{

    class String : public std::string
    {
    public:
        using std::string::string;
        String(const char*);
        String(const std::string& = "");
        String(const String&);
        inline operator const char*();
        String operator*(const size_t&) const;
        String &operator*=(const size_t&);
        constexpr String &allignString(size_t minLength, const char& symbolToFill = ' ', bool = false);
        constexpr String &centerAllignString(size_t minLength, const char& symbolToFill = ' ');
        inline explicit operator signed char() const;
        inline explicit operator unsigned char() const;
        inline explicit operator short() const;
        inline explicit operator unsigned short() const;
        inline explicit operator int() const;
        inline explicit operator unsigned int() const;
        inline explicit operator long long() const;
        inline explicit operator unsigned long long() const;
        inline explicit operator float() const;
        inline explicit operator double() const;
        inline explicit operator long double() const;
        inline explicit operator bool() const;
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

    inline String::operator signed char() const
    {
        return std::stoi(*this);
    }

    inline String::operator unsigned char() const
    {
        return std::stoi(*this);
    }

    inline String::operator short() const
    {
        return std::stoi(*this);
    }

    inline String::operator unsigned short() const
    {
        return std::stoi(*this);
    }

    inline String::operator int() const
    {
        return std::stoi(*this);
    }

    inline String::operator unsigned int() const
    {
        return std::stoi(*this);
    }

    inline String::operator long long() const
    {
        return std::stoll(*this);
    }

    inline String::operator unsigned long long() const
    {
        return std::stoull(*this);
    }

    inline String::operator float() const
    {
        return std::stof(*this);
    }

    inline String::operator double() const
    {
        return std::stod(*this);
    }

    inline String::operator long double() const
    {
        return std::stold(*this);
    }

    inline String::operator bool() const
    {
        return std::stoi(*this);
    }

    typedef String string;
    
}

#endif