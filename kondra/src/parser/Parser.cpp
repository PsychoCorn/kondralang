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

Token Parser::consume(TokenType type)
{
    Token current = get();
    if (type != current.getType())
        throw std::runtime_error("Wrong token type!");
    ++pos;
    return current;
}

std::vector<Statement *> Parser::parse()
{
    std::vector<Statement *> result;
    while (!match(TokenType::Eof))
    {
        result.push_back(statement());
    }
    return result;
}

Statement *Parser::statement()
{
    return assignmentStatement();
}

Statement* Parser::assignmentStatement()
{
    Token current = get();
    if (match(TokenType::Word) && get().getType() == TokenType::Equal)
    {
        std::string variable = current.getText();
        consume(TokenType::Equal);
        return new AssignmentStatement(variable, expression());
    }
    throw std::runtime_error("Unknown operator!");
}

Expression* Parser::expression()
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
    if (match(TokenType::HexNumber))
        return new NumberExpression(std::stoull(current.getText(), nullptr, 16));
    if (match(TokenType::OctNumber))
        return new NumberExpression(std::stoull(current.getText(), nullptr, 8));
    if (match(TokenType::Word))
        return new VariablesExpression(current.getText());
    if (match(TokenType::Lparen))
    {
        Expression *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error("Unknown expression!");
        return result;
    }
    throw std::runtime_error("Unknown expression!");
}
