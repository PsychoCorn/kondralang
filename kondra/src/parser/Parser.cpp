#include "../../headers/parser/Parser.hpp"

#include <stdexcept>

Parser::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
    size = tokens.size();
}

Token Parser::get(int relativePosition)
{
    int position = pos + relativePosition;
    if (position >= size)
        return eof;
    return tokens[position];
}

bool Parser::match(TokenType type)
{
    Token current = get();
    if (type != current.getType())
        return false;
    ++pos;
    return true;
}

std::vector<Expression *> Parser::parse()
{
    std::vector<Expression *> result;
    while (!match(TokenType::Eof))
    {
        result.push_back(expression());
    }
    return result;
}

Expression *Parser::expression()
{
    return additive();
}

Expression *Parser::additive()
{
    Expression *result = multiplicative();
    while (true)
    {
        if (match(TokenType::Plus))
        {
            result = new BinaryExpression('+', result, multiplicative());
            continue;
        }
        if (match(TokenType::Minus))
        {
            result = new BinaryExpression('-', result, multiplicative());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::multiplicative()
{
    Expression *result = unary();
    while (true)
    {
        if (match(TokenType::Star))
        {
            result = new BinaryExpression('*', result, unary());
            continue;
        }
        if (match(TokenType::Slash))
        {
            result = new BinaryExpression('/', result, unary());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::unary()
{
    if (match(TokenType::Minus))
        return new UnaryExpression('-', primary());
    if (match(TokenType::Plus))
        return primary();
    return primary();
}

Expression *Parser::primary()
{
    Token current = get();
    if (match(TokenType::Number))
        return new NumberExpression(std::stod(current.getText()));
    if (match(TokenType::Lparen))
    {
        Expression *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error("Unknown expression!");
        return result;
    }
    throw std::runtime_error("Unknown expression!");
}
