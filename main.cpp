#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <format>

std::vector<Statement *> chosingParser(const std::vector<Token>&, const Type&);

std::vector<Statement *> parsing(const std::vector<Token>& tokens)
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
        size_t lineCounter = 0;
        while (std::getline(sourceFile, line))
        {
            lineCounter++;
            try
            {
                lexer.setInput(line);
                tokens = lexer.tokenize();
                statements = parsing(tokens);
                std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
                    p->execute();
                });
            }
            catch (std::exception& e)
            {
                std::cerr << e.what() << " at line " << lineCounter;
                return 1;
            }
            std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
                delete p;
            });
            statements.clear();
        }
    }
    else
    {
        std::cout << "kondra has been built" << std::endl;
    }
    return 0;
}