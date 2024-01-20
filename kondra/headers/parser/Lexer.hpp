#ifndef Lexer_HPP
#define Lexer_HPP

#include "Token.hpp"
#include "../lib/KeyWords.hpp"
#include <vector>
#include <unordered_map>

class Lexer final
{
private:
    static std::string operatorChars;
    static std::unordered_map<std::string, TokenType> operators;
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
    void tokenizeStringValue();
    bool isHexDigit(char);
    bool isOperatorChar(char);

public:
    Lexer(std::string = "");
    void setInput(std::string);
    std::vector<Token> tokenize();
};

#endif