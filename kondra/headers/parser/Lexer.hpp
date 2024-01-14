#ifndef Lexer_HPP
#define Lexer_HPP

#include "Token.hpp"
#include <vector>
#include <unordered_map>

class Lexer final
{
private:
    static const unsigned char OPERATOR_CHARS_SIZE = 6;
    static constexpr const char *OPERATOR_CHARS = "+-*/()";
    static constexpr const char *OPERATOR_CHARS_END = OPERATOR_CHARS + OPERATOR_CHARS_SIZE;
    static constexpr const TokenType OPERATOR_TOKENS[] = {
        TokenType::Plus, TokenType::Minus, TokenType::Star, 
        TokenType::Slash, TokenType::Lparen, TokenType::Rparen
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
    void tokenizeOperator();

public:
    Lexer(std::string);
    std::vector<Token> tokenize();
};

#endif