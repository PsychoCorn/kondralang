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
    if (current == '0' && tolower(peek(1)) == 'x')
    {
        next();
        tokenizeHexNumber();
        return;
    }
    while (isdigit(current))
    {
        buffer += current;
        current = next();
    }
    if (buffer[0] == '0' && buffer.size() > 1)
    {
        addToken(TokenType::OctNumber, buffer);
        return;
    }
    addToken(TokenType::Number, buffer);
}

void Lexer::tokenizeHexNumber()
{
    std::string buffer = "";
    char current = next();
    while (isHexDigit(current))
    {
        buffer += current;
        current = next();
    }
    addToken(TokenType::HexNumber, buffer);
}

bool Lexer::isHexDigit(char c)
{
    std::string hexNumers = "abcdef";
    return (isdigit(c) || std::find(hexNumers.begin(), hexNumers.end(), tolower(c)) != hexNumers.end());
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