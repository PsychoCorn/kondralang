#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include "kondra/headers/types/kondratypes.hpp"
#include "kondra/headers/io/kondraio.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    Lexer lexer("(3 + 2) * 6 / 2");
    auto tokens = lexer.tokenize();
    Parser parser(tokens);
    auto expressions = parser.parse();
    std::for_each(expressions.begin(), expressions.end(), [](Expression* p) { 
        std::cout << p->eval() << std::endl; 
    });
    std::for_each(expressions.begin(), expressions.end(), [](Expression* p) { delete p; });
    expressions.clear();
    kondra::var n = "24";
    n = kondra::var::toFloat(n) + .5f;
    kondra::println(std::format("n = {:.3f}", (float)n));
    return 0;
}