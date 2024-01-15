#include "kondra/headers/parser/Lexer.hpp"
#include "kondra/headers/parser/Parser.hpp"
#include "kondra/headers/types/kondratypes.hpp"
#include "kondra/headers/io/kondraio.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    Lexer lexer("(0XA + 1) * 0xf + -012");
    auto tokens = lexer.tokenize();
    std::for_each(tokens.begin(), tokens.end(), [](Token t) { 
        std::cout << std::format("({}: {}) ", (int)(t.getType()), t.getText());
    });
    std::cout << std::endl;
    Parser parser(tokens);
    auto expressions = parser.parse();
    std::for_each(expressions.begin(), expressions.end(), [](Expression* p) { 
        std::cout << p->eval() << std::endl; 
    });
    std::for_each(expressions.begin(), expressions.end(), [](Expression* p) { delete p; });
    expressions.clear();
    return 0;
}