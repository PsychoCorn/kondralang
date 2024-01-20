#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <format>

std::vector<Statement *> chosingParser(const std::vector<Token>&, const Type&);

std::vector<Statement *> parsing(const std::vector<Token>& tokens)
{
    switch (tokens[0].getType())
    {
    case TokenType::KeyWord:
        if (tokens[0].getText() == "int64")
            return Parser<long long>(tokens).parse();
        else if (tokens[0].getText() == "uint64")
            return Parser<unsigned long long>(tokens).parse();
        else if (tokens[0].getText() == "int32")
            return Parser<int>(tokens).parse();
        else if (tokens[0].getText() == "uint32")
            return Parser<unsigned int>(tokens).parse();
        else if (tokens[0].getText() == "int16")
            return Parser<short int>(tokens).parse();
        else if (tokens[0].getText() == "uint16")
            return Parser<unsigned short int>(tokens).parse();
        else if (tokens[0].getText() == "int8")
            return Parser<signed char>(tokens).parse();
        else if (tokens[0].getText() == "uint8")
            return Parser<unsigned char>(tokens).parse();
        else if (tokens[0].getText() == "float64")
            return Parser<double>(tokens).parse();
        else if (tokens[0].getText() == "boolean")
            return Parser<bool>(tokens).parse();
        else if (tokens[0].getText() == "string")
            return Parser<std::string>(tokens).parse();
        else if (tokens[0].getText() == "print")
        {
            switch (tokens[1].getType())
            {
            case Identifier:
                return chosingParser(tokens, ListOfVariables::getType(tokens[1].getText()));
                break;

            case StringValue:
                return Parser<std::string>(tokens).parse();
                break;
            
            default:
                return Parser<double>(tokens).parse();
                break;
            }
        }
        break;

    case TokenType::Identifier:
        return chosingParser(tokens, ListOfVariables::getType(tokens[0].getText()));
    }
    throw std::runtime_error("Error!");
}

std::vector<Statement *> chosingParser(const std::vector<Token>& tokens, const Type& element)
{
    switch (element)
    {
    case Type::Int64:
        return Parser<long long>(tokens).parse();
        break;

    case Type::UInt64:
        return Parser<unsigned long long>(tokens).parse();
        break;

    case Type::Int32:
        return Parser<int>(tokens).parse();
        break;

    case Type::UInt32:
        return Parser<unsigned int>(tokens).parse();
        break;

    case Type::Int16:
        return Parser<short int>(tokens).parse();
        break;

    case Type::UInt16:
        return Parser<unsigned short int>(tokens).parse();
        break;

    case Type::Int8:
        return Parser<signed char>(tokens).parse();
        break;

    case Type::UInt8:
        return Parser<unsigned char>(tokens).parse();
        break;
    
    case Type::Float80:
        return Parser<long double>(tokens).parse();
        break;

    case Type::Float64:
        return Parser<double>(tokens).parse();
        break;

    case Type::Float32:
        return Parser<float>(tokens).parse();
        break;

    case Type::Bool:
        return Parser<bool>(tokens).parse();
        break;

    case Type::String:
        return Parser<std::string>(tokens).parse();
        break;
    }
    throw std::runtime_error("Error!");
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        std::string pathToSourceFile = argv[1];
        std::ifstream sourceFile(pathToSourceFile);
        if (!sourceFile.is_open())
            throw std::runtime_error("File doesn't exist!");
        Lexer lexer;
        std::vector<Token> tokens;
        std::vector<Statement *> statements;
        std::string line;
        while (std::getline(sourceFile, line))
        {
            lexer.setInput(line);
            tokens = lexer.tokenize();
            statements = parsing(tokens);
            std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
                p->execute();
            });
            std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
                delete p;
            });
            statements.clear();
        }
    }
    else
    {
        std::cout << "kondra works!" << std::endl;
    }
    return 0;
}