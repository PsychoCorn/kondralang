#include "../../headers/lib/KeyWords.hpp"

std::vector<std::string> KeyWords::keyWords = {
    "int8", "int16", "int32", "int64", 
    "uint8", "uint16", "uint32", "uint64",
    "float32", "float64", "float80", "boolean",
    "string", "var", "int", "console_out", 
    "if", "else"
};

bool KeyWords::isKeyWord(std::string word)
{
    return std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end();
}