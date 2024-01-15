#ifndef Parser_HPP
#define Parser_HPP

#include "Lexer.hpp"
#include "../ast/NumberExpression.hpp"
#include "../ast/BinaryExpression.hpp"
#include "../ast/UnaryExpression.hpp"
#include "../ast/ConstantExpression.hpp"

class Parser final
{
private:
    size_t pos = 0;
    size_t size;
    std::vector<Token> tokens;

    Token get(int = 0);
    bool match(TokenType);
    Expression* primary();
    Expression* unary();
    Expression* multiplicative();
    Expression* expression();
    Expression* additive();
public:
    Parser(std::vector<Token>);
    std::vector<Expression*> parse();
};

#endif