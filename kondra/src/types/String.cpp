#include "../../headers/types/String.hpp"

namespace kondra
{

String::String(const char* s) : std::string(s) {}

String::String(const std::string& s) : std::string(s) {}

String::String(const String& s) : std::string(s) {}

String String::operator*(const size_t& times) const
{
    String result = "";
    result.reserve(length() * times);
    for (size_t i = 0; i < times; i++)
    {
        result.append(*this);
    }
    return result;
}

String &String::operator*=(const size_t& times)
{
    *this = *this * times;
    return *this;
}

}