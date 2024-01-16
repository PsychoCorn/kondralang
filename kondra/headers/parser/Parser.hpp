#ifndef Parser_HPP
#define Parser_HPP

#include "Lexer.hpp"
#include "../ast/NumberExpression.hpp"
#include "../ast/BinaryExpression.hpp"
#include "../ast/UnaryExpression.hpp"
#include "../ast/VariablesExpression.hpp"
#include "../ast/AssignmentStatement.hpp"

class Parser final
{
private:
    size_t pos = 0;
    size_t size;
    std::vector<Token> tokens;

    Token get(int = 0);
    bool match(TokenType);
    Token consume(TokenType);
    Expression* primary();
    Expression* unary();
    Expression* multiplicative();
    Statement* statement();
    Expression* additive();
    Statement* assignmentStatement();
    Expression* expression();
public:
    Parser(std::vector<Token>);
    std::vector<Statement*> parse();
};

#endif