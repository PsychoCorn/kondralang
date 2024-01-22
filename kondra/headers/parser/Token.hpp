#ifndef Token_HPP
#define Token_HPP

#include <string>

// https://www.youtube.com/watch?v=ot-IMy_4ENg&list=PL81SFGIHr5IJFsoWX0qTeQ9_-MFBE552C&index=1&t=1073s

enum TokenType
{
    // numbers
    IntNumber,
    HexNumber,
    OctNumber,
    FloatNumber,
    StringValue, // string
    // word
    KeyWord,
    Identifier,
    // operators
    Star,
    Plus,
    Minus,
    Slash,
    Equal,
    // brasckets
    Lparen, // (
    Rparen, // )
    Eof // end of file
};

class Token final
{
private:
    TokenType type;
    std::string text;
public:
    Token(TokenType, std::string = "");
    TokenType getType() const;
    void setType(TokenType);
    std::string getText() const;
    void setText(std::string);
};

const Token eof(TokenType::Eof);

#endif