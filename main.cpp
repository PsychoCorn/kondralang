#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include "kondra/headers/types/kondratypes.hpp"
#include "kondra/headers/io/kondraio.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        std::string pathToSourceFile = argv[1];
        //pathToSourceFile = "build/main.txt";
        std::ifstream sourceFile(pathToSourceFile);
        if (!sourceFile.is_open())
            throw std::runtime_error("File doesn't exist!");
        std::string line;
        Lexer lexer;
        Parser parser;
        std::vector<Statement *> statements;
        while (std::getline(sourceFile, line)) 
        {
            lexer.setInput(line);
            parser.setTokens(lexer.tokenize());
            statements = parser.parse();
            std::for_each(statements.begin(), statements.end(), [](Statement* p) { p->execute(); });
            std::for_each(statements.begin(), statements.end(), [](Statement* p) { delete p; });
            statements.clear();
        }
        std::cout << std::format("{} = {}\n", "radius", Variables::get("radius"));
        std::cout << std::format("{} = {}\n", "SOfCircle1", Variables::get("SOfCircle1"));
        std::cout << std::format("{} = {}\n", "SOfCircle2", Variables::get("SOfCircle2"));
        std::cout << std::format("{} = {}\n", "_PI_", Variables::get("_PI_"));
        std::cout << std::format("{} = {}\n", "_E_", Variables::get("_E_"));
        std::cout << std::format("{} = {}\n", "_NULL_", Variables::get("_NULL_"));
    }
    else
    {
        std::cout << "kondra works!" << std::endl;
    }
    return 0;
}