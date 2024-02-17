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

std::vector<std::string> KeyWords::keyWords = {
    "int8", "int16", "int32", "int64", 
    "uint8", "uint16", "uint32", "uint64",
    "float32", "float64", "ref", "boolean",
    "string", "var", "int", "auto", "if", 
    "else", "while", "do", "for", "break", 
    "continue", "array", "const",
    "global", "func", "return", "ptr"
};

bool KeyWords::isKeyWord(std::string word)
{
    return std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end();
}

#endif