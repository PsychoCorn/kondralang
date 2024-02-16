#ifndef Lexer_HPP
#define Lexer_HPP

#include "Token.hpp"
#include "../lib/KeyWords.hpp"
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <string>

#define ERR_MSG_INVLD_F_NUM "Invalid float number"
#define ERR_MSG_UNKNWN_ESC_CHAR "Unknown escape-character"
#define ERR_MSG_UNKNWN_OP "Unknown operator"

class Lexer final
{
private:
    static std::string operatorChars;
    static std::unordered_map<std::string, TokenType> operators;
    std::string input;
    std::vector<Token> tokens;
    size_t pos = 0;
    size_t length;

    void addToken(TokenType, std::string);
    char peek(size_t = 0);
    char next();
    void tokenizeNumber();
    void tokenizeHexNumber();
    void tokenizeOctNumber();
    void tokenizeWord();
    void tokenizeOperator();
    void tokenizeLineComment();
    void tokenizeBlockComment();
    void tokenizeStringValue(const char&, const bool& = false);
    bool isHexDigit(char);
    bool isOperatorChar(char);
    bool isOperator(const std::string&);

public:
    Lexer(const std::string & = "");
    std::vector<Token> tokenize();
};

std::string Lexer::operatorChars = "+-*/(){}=%&^|~<>?:!,;";

std::unordered_map<std::string, TokenType> Lexer::operators = {
    {"+", TokenType::Plus}, {"-", TokenType::Minus}, {"*", TokenType::Star},
    {"/", TokenType::Slash}, {"(", TokenType::Lparen}, {")", TokenType::Rparen},
    {"=", TokenType::Equal}, {"+=", TokenType::PlusAndEqual}, {"%", TokenType::Percentage},
    {"&", TokenType::Ampersand}, {"|", TokenType::Pipe}, {"^", TokenType::Caret},
    {"~", TokenType::Tilde}, {"<<", TokenType::Lshift}, {">>", TokenType::Rshift},
    {"*=", TokenType::StarAndEqual}, {"/=", TokenType::SlashAndEqual}, {"-=", TokenType::MinusAndEqual},
    {"%=", TokenType::PercentageAndEqual}, {"&=", TokenType::AmpersandAndEqual}, {"^=", TokenType::CaretAndEqual},
    {"|=", TokenType::PipeAndEqual}, {"<<=", TokenType::LshiftAndEqual}, {">>=", TokenType::RshiftAndEqual},
    {"?", TokenType::Question}, {":", TokenType::Colon}, {"==", TokenType::DoubleEqual},
    {"<", TokenType::Less}, {">", TokenType::More}, {"<=", TokenType::LessOrEqual},
    {">=", TokenType::MoreOrEqual}, {"!=", TokenType::ExclamationAndEqual}, {"!", TokenType::Exclamation},
    {"{", TokenType::Lbrace}, {"}", TokenType::Rbrace}, {"&&", TokenType::DoubleAmpersand},
    {"||", TokenType::DoublePipe}, {",", TokenType::Comma}, {";", TokenType::Semicolon},
    {"++", TokenType::DoublePlus}, {"--", TokenType::DoubleMinus}};

Lexer::Lexer(const std::string &input)
{
    this->input = input;
    length = input.length();
}

std::vector<Token> Lexer::tokenize()
{
    tokens.clear();
    char current;
    while (pos < length)
    {
        current = peek();
        if (isdigit(current))
            tokenizeNumber();
        else if (isalpha(current) || current == '_')
        {
            if (current == 'f' && (peek(1) == '\'' || peek(1) == '\"'))
                tokenizeStringValue(next(), true);
            else
                tokenizeWord();
        }
        else if (current == '\"' || current == '\'')
            tokenizeStringValue(current);
        else if (isOperatorChar(current))
            if (current == '/')
            {
                char nextChar = peek(1);
                switch (nextChar)
                {
                case '/':
                    next();
                    tokenizeLineComment();
                    break;

                case '*':
                    next();
                    tokenizeBlockComment();
                    break;
                
                default:
                    tokenizeOperator();
                    break;
                }
            }
            else
                tokenizeOperator();
        else // skip whitespaces
            next();
    }
    return tokens;
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
                throw std::runtime_error(ERR_MSG_INVLD_F_NUM);
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
    if (buffer == "true" || buffer == "false")
        addToken(TokenType::BoolValue, buffer);
    else
        KeyWords::isKeyWord(buffer) ? addToken(TokenType::KeyWord, buffer) : 
                                    addToken(TokenType::Identifier, buffer);
}

void Lexer::tokenizeStringValue(const char &quotationMark, const bool &isFstring)
{
    std::string buffer = "";
    char current = next();
    while (true)
    {
        if (current == '\\')
        {
            current = next();
            switch (current)
            {
            case 'a':
                current = next();
                buffer += '\a';
                continue;
            
            case 'b':
                current = next();
                buffer += '\b';
                continue;

            case 't':
                current = next();
                buffer += '\t';
                continue;
            
            case 'n':
                current = next();
                buffer += '\n';
                continue;

            case 'v':
                current = next();
                buffer += '\v';
                continue;
            
            case 'f':
                current = next();
                buffer += '\f';
                continue;

            case 'r':
                current = next();
                buffer += '\r';
                continue;
            
            case 'e':
                current = next();
                buffer += '\e';
                continue;

            case '"':
                current = next();
                buffer += '"';
                continue;

            case '\\':
                current = next();
                buffer += '\\';
                continue;
            
            case '\?':
                current = next();
                buffer += '\?';
                continue;

            case '\'':
                current = next();
                buffer += '\'';
                continue;

            case '\0':
                current = next();
                buffer += '\0';
                continue;
            
            default:
                throw std::runtime_error(ERR_MSG_UNKNWN_ESC_CHAR);
                break;
            }
        }
        if (current == quotationMark)
            break;
        buffer += current;
        current = next();
    }
    next(); // skip closing quotation mark
    isFstring ? addToken(TokenType::FstringValue, buffer) : addToken(TokenType::StringValue, buffer);
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
        if (!isOperator(buffer + current))
            break;
        buffer += current;
        current = next();
    }
    addToken(operators[buffer], buffer);
}

void Lexer::addToken(TokenType type, std::string text)
{
    tokens.push_back(Token(type, text));
}

char Lexer::peek(size_t relativePosition)
{
    size_t position = pos + relativePosition;
    if (position >= length)
        return '\0';
    return input[position];
}

char Lexer::next()
{
    ++pos;
    return peek();
}

bool Lexer::isOperator(const std::string& op)
{
    return operators.find(op) != operators.end();
}

void Lexer::tokenizeLineComment()
{
    char current = next();
    for (;;)
    {
        if (current == '\n')
            break;
        current = next();
    }
}

void Lexer::tokenizeBlockComment()
{
    char current = next();
    for (;;)
    {
        if (current == '*' && next() == '/')
        {
            next();
            break;
        }
        current = next();
    }
}

#endif