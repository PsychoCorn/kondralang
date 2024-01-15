#ifndef Token_HPP
#define Token_HPP

#include <string>

// https://www.youtube.com/watch?v=ot-IMy_4ENg&list=PL81SFGIHr5IJFsoWX0qTeQ9_-MFBE552C&index=1&t=1073s

enum TokenType
{
    // numbers
    Number,
    HexNumber,
    OctNumber,
    // identifiers
    Word,
    // operators
    Star,
    Plus,
    Minus,
    Slash,
    // brasckets
    Lparen, // (
    Rparen, // )
    // end of file
    Eof
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