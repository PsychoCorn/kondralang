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
    std::vector<Statement *> statements;
    std::vector<std::vector<Token>> tokens;
    Lexer lexer;

    std::vector<std::string> split(std::string, std::string);
    std::vector<std::vector<Token>> splitToStatements(std::vector<Token>);

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
    for (; pos < tokens.size(); ++pos)
    {
        try
        {
            statements = parsing(tokens, pos);
            std::for_each(statements.begin(), statements.end(), [](Statement *p)
                          { p->execute(); });
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << " at statement " << pos + 1;
            return;
        }
        std::for_each(statements.begin(), statements.end(), [](Statement *p)
                      { delete p; });
        statements.clear();
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

std::vector<std::vector<Token>> Interpreter::splitToStatements(std::vector<Token> tokens)
{
    std::vector<std::vector<Token>> result;
    std::vector<Token> statement;
    for (const auto &token : tokens)
    {
        if (token.getType() == TokenType::Semicolon)
        {
            result.push_back(statement);
            statement.clear();
            continue;
        }
        statement.push_back(token);
    }
    return result;
}

#endif