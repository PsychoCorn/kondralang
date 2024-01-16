#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include "kondra/headers/types/kondratypes.hpp"
#include "kondra/headers/io/kondraio.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    Lexer lexer("newVar = (2.4 + 5) / 2 \nnewVar1 = newVar + 0xf * 012");
    auto tokens = lexer.tokenize();
    std::for_each(tokens.begin(), tokens.end(), [](Token t) { 
        std::cout << std::format("({}: \"{}\") ", (int)(t.getType()), t.getText());
    }); 
    std::cout << std::endl;
    Parser parser(tokens);
    auto expressions = parser.parse();
    std::for_each(expressions.begin(), expressions.end(), [](Statement* p) { p->execute(); });
    std::for_each(expressions.begin(), expressions.end(), [](Statement* p) { delete p; });
    expressions.clear();
    std::cout << std::format("{} = {}\n", "newVar", Variables::get("newVar"));
    std::cout << std::format("{} = {}\n", "newVar1", Variables::get("newVar1"));
    std::cout << std::format("{} = {}\n", "_PI_", Variables::get("_PI_"));
    std::cout << std::format("{} = {}\n", "_E_", Variables::get("_E_"));
    return 0;
}