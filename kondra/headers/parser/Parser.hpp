#ifndef Parser_HPP
#define Parser_HPP

#include "Lexer.hpp"
#include "../ast/ast.hpp"
#include "../../headers/lib/KeyWords.hpp"
#include <stdexcept>

template <class T>
class Parser final
{
private:
    size_t pos = 0;
    size_t size;
    std::vector<Token> tokens;

    Token get(int = 0);
    bool match(TokenType);
    Token consume(TokenType);
    Expression<T> *primary();
    Expression<T> *unary();
    Expression<T> *multiplicative();
    Statement *statement();
    Expression<T> *additive();
    Statement *assignmentStatement();
    Statement *variableDeclarationStatement();
    Expression<T> *expression();

public:
    Parser(std::vector<Token> = std::vector<Token>());
    std::vector<Statement *> parse();
    void setTokens(std::vector<Token>);
};

template <class T>
Parser<T>::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
    size = tokens.size();
}

template <class T>
Token Parser<T>::get(int relativePosition)
{
    int position = pos + relativePosition;
    if (position >= size)
        return eof;
    return tokens[position];
}

template <class T>
bool Parser<T>::match(TokenType type)
{
    Token current = get();
    if (type != current.getType())
        return false;
    ++pos;
    return true;
}

template <class T>
Token Parser<T>::consume(TokenType type)
{
    Token current = get();
    if (type != current.getType())
        throw std::runtime_error("Wrong token type!");
    ++pos;
    return current;
}

template <class T>
std::vector<Statement *> Parser<T>::parse()
{
    std::vector<Statement *> result;
    while (!match(TokenType::Eos) && !match(TokenType::Eof))
    {
        result.push_back(statement());
    }
    return result;
}

template <class T>
Statement *Parser<T>::statement()
{
    if (get().getType() == TokenType::KeyWord)
        return variableDeclarationStatement();
    if (get().getType() == TokenType::Identifier)
        return assignmentStatement();
    throw std::runtime_error("Unknown statement");
}

template <class T>
Statement *Parser<T>::variableDeclarationStatement()
{
    std::string type = get().getText();
    std::string identifierOfVariable = get(1).getText();
    if (match(TokenType::KeyWord) && match(TokenType::Identifier))
    {
        if (match(TokenType::Equal))
            return new VariableDeclarationStatement<T>(identifierOfVariable, expression());
        return new VariableDeclarationStatement<T>(identifierOfVariable, new NumberExpression<T>(0));
    }
    throw std::runtime_error("Unknown operator!");
}

template <class T>
Statement *Parser<T>::assignmentStatement()
{
    Token current = get();
    if (match(TokenType::Identifier) && get().getType() == TokenType::Equal)
    {
        std::string identifierOfVariable = current.getText();
        Type typeOfVariable = ListOfVariables::getType(identifierOfVariable);
        consume(TokenType::Equal);
        return new AssignmentStatement<T>(identifierOfVariable, expression());
    }
    throw std::runtime_error("Unknown operator!");
}

template <class T>
Expression<T> *Parser<T>::expression()
{
    return additive();
}

template <class T>
Expression<T> *Parser<T>::additive()
{
    Expression<T> *result = multiplicative();
    while (true)
    {
        if (match(TokenType::Plus))
        {
            result = new BinaryExpression<T>("+", result, multiplicative());
            continue;
        }
        if (match(TokenType::Minus))
        {
            result = new BinaryExpression<T>("-", result, multiplicative());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::multiplicative()
{
    Expression<T> *result = unary();
    while (true)
    {
        if (match(TokenType::Star))
        {
            result = new BinaryExpression<T>("*", result, unary());
            continue;
        }
        if (match(TokenType::Slash))
        {
            result = new BinaryExpression<T>("/", result, unary());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::unary()
{
    if (match(TokenType::Minus))
        return new UnaryExpression<T>("-", primary());
    if (match(TokenType::Plus))
        return primary();
    return primary();
}

template <class T>
Expression<T> *Parser<T>::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new NumberExpression<T>(std::stoll(current.getText()));
    if (match(TokenType::FloatNumber))
        return new NumberExpression<T>(std::stod(current.getText()));
    if (match(TokenType::HexNumber))
        return new NumberExpression<T>(std::stoull(current.getText(), nullptr, 16));
    if (match(TokenType::OctNumber))
        return new NumberExpression<T>(std::stoull(current.getText(), nullptr, 8));
    if (match(TokenType::Identifier))
        return new VariablesExpression<T>(current.getText());
    if (match(TokenType::Lparen))
    {
        Expression<T> *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error("Unknown expression!");
        return result;
    }
    throw std::runtime_error("Unknown expression!");
}

template <class T>
void Parser<T>::setTokens(std::vector<Token> tokens)
{
    this->tokens = tokens;
    size = tokens.size();
    pos = 0;
}

#endif