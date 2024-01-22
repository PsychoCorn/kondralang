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
    size_t numberOfLine = 0ull;
    std::string pathToSourceFile;
    std::vector<Statement *> statements;
    std::vector<Token> tokens;
    Lexer lexer;
    std::vector<Statement *> chosingParser(const Type&);
    std::vector<Statement *> parsing();

public:
    Interpreter(std::string);
    void interpretation();
};

Interpreter::Interpreter(std::string pathToSourceFile)
{
    this->pathToSourceFile = pathToSourceFile;
}


std::vector<Statement *> Interpreter::chosingParser(const Type& element)
{
    switch (element)
    {
    case Type::Int64:
        return Parser<long long>(tokens).parse();

    case Type::UInt64:
        return Parser<unsigned long long>(tokens).parse();

    case Type::Int32:
        return Parser<int>(tokens).parse();

    case Type::UInt32:
        return Parser<unsigned int>(tokens).parse();

    case Type::Int16:
        return Parser<short>(tokens).parse();

    case Type::UInt16:
        return Parser<unsigned short>(tokens).parse();

    case Type::Int8:
        return Parser<signed char>(tokens).parse();

    case Type::UInt8:
        return Parser<unsigned char>(tokens).parse();

    case Type::Int:
        return Parser<kondra::dynamic_int>(tokens).parse();
    
    case Type::Float80:
        return Parser<long double>(tokens).parse();

    case Type::Float64:
        return Parser<double>(tokens).parse();

    case Type::Float32:
        return Parser<float>(tokens).parse();

    case Type::Bool:
        return Parser<bool>(tokens).parse();

    case Type::String:
        return Parser<kondra::string>(tokens).parse();

    case Type::Var:
        return Parser<kondra::var>(tokens).parse();

    case Type::None:
        throw std::runtime_error("Unknown identifier");
    }
    throw std::runtime_error("Error!");
}

std::vector<Statement *> Interpreter::parsing()
{
    if (tokens.empty())
    {
        return std::vector<Statement *>();
    }
    std::string textOfkeyWord;
    switch (tokens[0].getType())
    {
    case TokenType::KeyWord:
        textOfkeyWord = tokens[0].getText();
        if (textOfkeyWord == "int64")
            return Parser<long long>(tokens).parse();
        else if (textOfkeyWord == "uint64")
            return Parser<unsigned long long>(tokens).parse();
        else if (textOfkeyWord == "int32")
            return Parser<int>(tokens).parse();
        else if (textOfkeyWord == "uint32")
            return Parser<unsigned int>(tokens).parse();
        else if (textOfkeyWord == "int16")
            return Parser<short>(tokens).parse();
        else if (textOfkeyWord == "uint16")
            return Parser<unsigned short>(tokens).parse();
        else if (textOfkeyWord == "int8")
            return Parser<signed char>(tokens).parse();
        else if (textOfkeyWord == "uint8")
            return Parser<unsigned char>(tokens).parse();
        else if (textOfkeyWord == "int")
            return Parser<kondra::dynamic_int>(tokens).parse();
        else if (textOfkeyWord == "float64")
            return Parser<double>(tokens).parse();
        else if (textOfkeyWord == "boolean")
            return Parser<bool>(tokens).parse();
        else if (textOfkeyWord == "string")
            return Parser<kondra::string>(tokens).parse();
        else if (textOfkeyWord == "var")
            return Parser<kondra::var>(tokens).parse();
        else if (textOfkeyWord == "console_out")
            return Parser<kondra::string>(tokens).parse();

    case TokenType::Identifier:
        return chosingParser(ListOfVariables::getType(tokens[0].getText()));
    }
    throw std::runtime_error("Error!");
}

void Interpreter::interpretation()
{
    std::ifstream sourceFile(pathToSourceFile);
    if (!sourceFile.is_open())
        throw std::runtime_error("File doesn't exist!");
    std::string line;
    size_t lineCounter = 0;
    while (std::getline(sourceFile, line))
    {
        lineCounter++;
        try
        {
            lexer.setInput(line);
            tokens = lexer.tokenize();
            statements = parsing();
            std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
                p->execute();
            });
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << " at line " << lineCounter;
            return;
        }
        std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
            delete p;
        });
        statements.clear();
    }
}

#endif