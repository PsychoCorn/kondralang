#include "../../headers/interpreter/Token.hpp"

Token::Token(TokenType type, std::string text)
{
    this->type = type;
    this->text = text;
}

TokenType Token::getType() const
{
    return type;
}

void Token::setType(TokenType type)
{
    this->type = type;
}

std::string Token::getText() const
{
    return text;
}

void Token::setText(std::string text)
{
    this->text = text;
}

std::ostream &operator<<(std::ostream &os, const Token &token)
{
    auto type = token.getType();
    auto text = token.getText();
    switch (type)
    {
    case StringValue:
        text = "\"" + text + "\"";
        break;

    case FstringValue:
        text = "f\"" + text + "\"";
        break;
    }
    os << text;
    return os;
}