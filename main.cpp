#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include "kondra/headers/io/kondraio.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

void interprinting(std::string sourceCode)
{
    Lexer lexer(sourceCode);
    Parser<long long> i64Parser;
    Parser<unsigned long long> ui64Parser;
    Parser<double> f64Parser;
    std::vector<Token> tokens = lexer.tokenize();
    std::vector<Statement *> statements;
    while (tokens.size() > 0)
    {
        std::for_each(tokens.begin(), tokens.end(), [](Token p) { 
            std::cout << std::format("({} : \"{}\")", (int)p.getType(), p.getText()); 
        });
        std::cout << std::endl;
        switch (tokens[0].getType())
        {
        case TokenType::KeyWord:
            if (tokens[0].getText() == "int64")
            {
                i64Parser.setTokens(tokens);
                statements = i64Parser.parse();
            }
            else if (tokens[0].getText() == "uint64")
            {
                ui64Parser.setTokens(tokens);
                statements = ui64Parser.parse();
            }
            else if (tokens[0].getText() == "float64")
            {
                f64Parser.setTokens(tokens);
                statements = f64Parser.parse();
            }
            break;

        case TokenType::Identifier:
            switch (ListOfVariables::getType(tokens[0].getText()))
            {
            case Type::Int64:
                i64Parser.setTokens(tokens);
                statements = i64Parser.parse();
                break;

            case Type::UInt64:
                ui64Parser.setTokens(tokens);
                statements = ui64Parser.parse();
                break;
            
            case Type::Float64:
                f64Parser.setTokens(tokens);
                statements = f64Parser.parse();
                break;
            }
        }
        std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
            p->execute();
        });
        std::for_each(statements.begin(), statements.end(), [](Statement *p) { 
            delete p;
        });
        statements.clear();
        tokens = lexer.tokenize();
    }
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        std::string pathToSourceFile = argv[1];
        //pathToSourceFile = "build/main.kondra";
        std::ifstream sourceFile(pathToSourceFile);
        if (!sourceFile.is_open())
            throw std::runtime_error("File doesn't exist!");
        interprinting(std::string((std::istreambuf_iterator<char>(sourceFile)), 
                                    (std::istreambuf_iterator<char>())));
        std::cout << std::format("({} : {})\n", "five", Variables<long long>::get("five")) <<
                     std::format("({} : {})\n", "halfOfFive", Variables<double>::get("halfOfFive")) <<
                     std::format("({} : {})\n", "eight", Variables<unsigned long long>::get("eight"));
    }
    else
    {
        std::cout << "kondra works!" << std::endl;
    }
    return 0;
}