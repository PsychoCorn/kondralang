#ifndef KeyWords_HPP
#define KeyWords_HPP

#include <algorithm>
#include <vector>
#include <string>

class KeyWords final
{
private:
    static std::vector<std::string> keyWords;
public:
    static bool isKeyWord(std::string);
};

#endif