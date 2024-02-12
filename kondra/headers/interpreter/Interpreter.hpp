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
    Scopes::initGlobalScope();
    std::string sourceCode((std::istreambuf_iterator<char>(sourceFile)), 
        (std::istreambuf_iterator<char>()));
    sourceCode.append("\n");
    sourceFile.close();
    Parser(Lexer(sourceCode).tokenize()).parse()->execute();
}

#endif