#ifndef String_hpp
#define String_hpp

#include <iostream>

namespace kondra
{

class String : public std::string
{
public:
    String(const char*);
    String(const std::string& = "");
    String(const String&);
    inline operator const char*();
};

inline String::operator const char*() 
{
    return this->c_str();
}

typedef String string;
    
}

#endif