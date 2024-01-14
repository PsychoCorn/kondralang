#include "../../headers/parser/Lexer.hpp"
#include <algorithm>

Lexer::Lexer(std::string input)
{
    this->input = input;
    length = input.length();
}

std::vector<Token> Lexer::tokenize()
{
    char current;
    while (pos < length)
    {
        current = peek();
    if (isdigit(current))
        tokenizeNumber();
    else if (std::find(OPERATOR_CHARS, OPERATOR_CHARS_END, current) != OPERATOR_CHARS_END)
        tokenizeOperator();
    else
        next();
    }
    return tokens;
}

void Lexer::tokenizeNumber()
{
    std::string buffer = "";
    char current = peek();
    while (isdigit(current))
    {
        buffer += current;
        current = next();
    }
    addToken(TokenType::Number, buffer);
}

void Lexer::tokenizeOperator()
{
    unsigned char position = std::distance(OPERATOR_CHARS, 
        std::find(OPERATOR_CHARS, OPERATOR_CHARS_END, peek()));
    addToken(OPERATOR_TOKENS[position]);
    next();
}

void Lexer::addToken(TokenType type, std::string text)
{
    tokens.push_back(Token(type, text));
}

void Lexer::addToken(TokenType type)
{
    switch (type)
    {
    case TokenType::Plus:
        tokens.push_back(Token(type, "+"));
        break;
    
    case TokenType::Minus:
        tokens.push_back(Token(type, "-"));
        break;

    case TokenType::Star:
        tokens.push_back(Token(type, "*"));
        break;
    
    case TokenType::Slash:
        tokens.push_back(Token(type, "/"));
        break;

    default:
        tokens.push_back(Token(type, "\0"));
        break;
    }
}

char Lexer::peek(int relativePosition)
{
    int position = pos + relativePosition;
    if (position >= length)
        return '\0';
    return input[position];
}

char Lexer::next()
{
    ++pos;
    return peek();
}