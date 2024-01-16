#ifndef Lexer_HPP
#define Lexer_HPP

#include "Token.hpp"
#include <vector>
#include <unordered_map>

class Lexer final
{
private:
    class OperatorChars
    {
    public:
        static constexpr const char *begin = "+-*/()=";
        static const unsigned char size = sizeof(begin) / sizeof(char) - 1;
        static constexpr const char *end = begin + size;
        static constexpr const TokenType tokens[] = {
            TokenType::Plus, TokenType::Minus, TokenType::Star,
            TokenType::Slash, TokenType::Lparen, TokenType::Rparen,
            TokenType::Equal};
    };
    std::string input;
    std::vector<Token> tokens;
    size_t pos = 0;
    size_t length;

    void addToken(TokenType);
    void addToken(TokenType, std::string);
    char peek(int = 0);
    char next();
    void tokenizeNumber();
    void tokenizeHexNumber();
    void tokenizeOctNumber();
    void tokenizeWord();
    void tokenizeOperator();
    bool isHexDigit(char);

public:
    Lexer(std::string = "");
    void setInput(std::string);
    std::vector<Token> tokenize();
};

#endif