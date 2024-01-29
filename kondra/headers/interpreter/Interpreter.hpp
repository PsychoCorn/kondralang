#ifndef Interpreter_HPP
#define Interpreter_HPP

#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <format>

class Interpreter
{
private:
    size_t pos = 0ull;
    std::string pathToSourceFile;
    Statement *statement;
    std::vector<std::vector<Token>> tokens;
    Lexer lexer;

    std::vector<std::string> split(std::string, std::string);

public:
    Interpreter(std::string);
    void interpretation();
};

Interpreter::Interpreter(std::string pathToSourceFile)
{
    this->pathToSourceFile = pathToSourceFile;
}

void Interpreter::interpretation()
{
    std::ifstream sourceFile(pathToSourceFile);
    if (!sourceFile.is_open())
        throw std::runtime_error("File doesn't exist!");
    std::string sourceCode((std::istreambuf_iterator<char>(sourceFile)), 
        (std::istreambuf_iterator<char>()));
    sourceFile.close();
    lexer.setInput(sourceCode);
    tokens = splitToStatements(lexer.tokenize());
    try
    {
        for (; pos < tokens.size(); ++pos)
        {
            statement = parsing(tokens, pos);
            statement->execute();
            delete statement;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << " at statement " << pos + 1;
        return;
    }
}

std::vector<std::string> Interpreter::split(std::string text, std::string delim) // https://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring (https://stackoverflow.com/users/13965871/roach)
{
    std::vector<std::string> vec;
    size_t pos = 0, prevPos = 0;
    while (true)
    {
        pos = text.find(delim, prevPos);
        if (pos == std::string::npos)
        {
            vec.push_back(text.substr(prevPos));
            return vec;
        }

        vec.push_back(text.substr(prevPos, pos - prevPos));
        prevPos = pos + delim.length();
    }
}

#endif