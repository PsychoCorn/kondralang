#include "../../headers/parser/Lexer.hpp"

#include <algorithm>
#include <stdexcept>

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
    else if (isalpha(current) || current == '_')
        tokenizeWord();
    else if (std::find(OperatorChars::begin, OperatorChars::end, current) != OperatorChars::end)
        tokenizeOperator();
    else //skip whitespaces
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
    else if (current == '0' && isdigit(peek(1)))
    {
        tokenizeOctNumber();
        return;
    }
    while (true)
    {
        if (current == '.')
        {
            if (buffer.find('.') != std::string::npos)
                throw std::runtime_error("Invalid float number!");
        }
        else if (!isdigit(current))
            break;
        buffer += current;
        current = next();
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

void Lexer::tokenizeOctNumber()
{
    std::string buffer = "";
    char current = next();
    while (isdigit(current))
    {
        buffer += current;
        current = next();
    }
    addToken(TokenType::OctNumber, buffer);
}

void Lexer::tokenizeWord()
{
    std::string buffer = "";
    char current = peek();
    while (true)
    {
        if (!isdigit(current) && !isalpha(current) && current != '_')
            break;
        buffer += current;
        current = next();
    }
    addToken(TokenType::Word, buffer);
}

bool Lexer::isHexDigit(char c)
{
    std::string hexNumers = "abcdef";
    return (isdigit(c) || std::find(hexNumers.begin(), hexNumers.end(), tolower(c)) != hexNumers.end());
}

void Lexer::tokenizeOperator()
{
    unsigned char position = std::distance(OperatorChars::begin, 
        std::find(OperatorChars::begin, OperatorChars::end, peek()));
    addToken(OperatorChars::tokens[position]);
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
    
    case TokenType::Lparen:
        tokens.push_back(Token(type, "("));
        break;

    case TokenType::Rparen:
        tokens.push_back(Token(type, ")"));
        break;

    case TokenType::Equal:
        tokens.push_back(Token(type, "="));
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

void Lexer::setInput(std::string input)
{
    this->input = input;
    length = input.length();
    tokens.clear();
    pos = 0;
}