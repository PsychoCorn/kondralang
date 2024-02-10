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
    "float32", "float64", "float80", "boolean",
    "string", "var", "int", "auto", "console_out", 
    "if", "else", "console_in", "int_var",
    "float_var", "string_var", "boolean_var", 
    "while", "for", "break", "continue"
};

bool KeyWords::isKeyWord(std::string word)
{
    return std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end();
}

#endif