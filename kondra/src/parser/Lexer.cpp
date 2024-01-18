#include "../../headers/parser/Lexer.hpp"

#include <stdexcept>
#include <algorithm>
#include <string>

std::string Lexer::operatorChars = "+-*/()=";

std::unordered_map<std::string, TokenType> Lexer::operators = {
    {"+", TokenType::Plus}, {"-", TokenType::Minus}, {"*", TokenType::Star},
    {"/", TokenType::Slash}, {"(", TokenType::Lparen}, {")", TokenType::Rparen},
    {"=", TokenType::Equal} };

Lexer::Lexer(std::string input)
{
    this->input = input;
    length = input.length();
}

std::vector<Token> Lexer::tokenize()
{
    tokens.clear();
    if (pos >= length)
    {
        return tokens;
    }
    char current;
    while (pos < length)
    {
        current = peek();
        if (isdigit(current))
            tokenizeNumber();
        else if (isalpha(current) || current == '_')
            tokenizeWord();
        else if (isOperatorChar(current))
            tokenizeOperator();
        else if (current == ';')
        {
            tokenizeEndOfstatement();
            return tokens;
        }
        else // skip whitespaces
            next();
    }
    //return tokens;
    throw std::runtime_error("\";\" wasn't found");
}

void Lexer::tokenizeEndOfstatement()
{
    addToken(TokenType::Eos);
    next();
}

bool Lexer::isOperatorChar(char c)
{
    return operatorChars.find(c) != std::string::npos;
}

void Lexer::tokenizeNumber()
{
    std::string buffer = "";
    char current = peek();
    TokenType type = TokenType::IntNumber;
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
            type = TokenType::FloatNumber;
        }
        else if (!isdigit(current))
            break;
        buffer += current;
        current = next();
    }
    addToken(type, buffer);
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
    KeyWords::isKeyWord(buffer) ? addToken(TokenType::KeyWord, buffer) : 
                                  addToken(TokenType::Identifier, buffer);
}

bool Lexer::isHexDigit(char c)
{
    std::string hexNumers = "abcdef";
    return (isdigit(c) || std::find(hexNumers.begin(), hexNumers.end(), tolower(c)) != hexNumers.end());
}

void Lexer::tokenizeOperator()
{
    std::string buffer = "";
    char current = peek();
    while (true)
    {
        if (!isOperatorChar(current))
            break;
        buffer += current;
        current = next();
    }
    addToken(operators[buffer]);
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

    case TokenType::Eos:
        tokens.push_back(Token(type, ";"));
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