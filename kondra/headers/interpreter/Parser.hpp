#ifndef Parser_HPP
#define Parser_HPP

#include "Lexer.hpp"
#include "../ast/ast.hpp"
#include <stdexcept>

#define ERR_MSG_UNKNWN_OP "Unknown operator"
#define ERR_MSG_UNKNWN_EXPR "Unknown expression"
#define ERR_MSG_STR_IN_NOT_STR_STMNT "Using string in not string statement"
#define ERR_MSG_WRNG_TOKEN_TYPE "Wrong token type"
#define ERR_MSG_UNKNWN_STMNT "Unknown statement"

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
    Expression<T> *bitwise();

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
        throw std::runtime_error(ERR_MSG_WRNG_TOKEN_TYPE);
    ++pos;
    return current;
}

template <class T>
std::vector<Statement *> Parser<T>::parse()
{
    std::vector<Statement *> result;
    while (!match(TokenType::Eof))
    {
        result.push_back(statement());
    }
    return result;
}

template <class T>
Statement *Parser<T>::statement()
{
    Token current = get(); 
    switch (current.getType())
    {
    case KeyWord:
        if (current.getText() == "console_out")
        {
            consume(KeyWord);
            return new PrintStatement<T>(expression());
        }
        else
            return variableDeclarationStatement();

    case Identifier:
        return assignmentStatement();
    
    default:
        throw std::runtime_error(ERR_MSG_UNKNWN_STMNT);
    }
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
        return new VariableDeclarationStatement<T>(identifierOfVariable, new ValueExpression<T>(0));
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_OP);
}

template <>
Statement *Parser<kondra::string>::variableDeclarationStatement()
{
    std::string type = get().getText();
    std::string identifierOfVariable = get(1).getText();
    if (match(TokenType::KeyWord) && match(TokenType::Identifier))
    {
        if (match(TokenType::Equal))
            return new VariableDeclarationStatement<kondra::string>(identifierOfVariable, expression());
        return new VariableDeclarationStatement<kondra::string>(identifierOfVariable, new ValueExpression<kondra::string>(""));
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_OP);
}

template <class T>
Statement *Parser<T>::assignmentStatement()
{
    Token current = get();
    std::string identifierOfVariable;
    if (match(TokenType::Identifier))
    {
        identifierOfVariable = current.getText();
        if (match(TokenType::Equal))
            return new AssignmentStatement<T>(identifierOfVariable, expression());
        else if (match(TokenType::PlusAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("+", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::MinusAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("-", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
         else if (match(TokenType::StarAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("*", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::SlashAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("/", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::PercentageAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("%", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::AmpersandAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("&", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::CaretAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("^", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::PipeAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("|", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::LshiftAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>("<<", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
        else if (match(TokenType::RshiftAndEqual))
            return new AssignmentStatement<T>(identifierOfVariable, 
                new BinaryExpression<T>(">>", new VariablesExpression<T>(identifierOfVariable), 
                expression()));
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_OP);
}

template <class T>
Expression<T> *Parser<T>::expression()
{
    Expression<T> *result = bitwise();
    while (true)
    {
        if (match(TokenType::Question))
        {
            Expression<T> *exprIfTrue = expression();
            consume(TokenType::Colon);
            result = new TernaryExpression<T>(result, exprIfTrue, expression());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::bitwise()
{
    Expression<T> *result = additive();
    while (true)
    {
        if (match(TokenType::Lshift))
        {
            result = new BinaryExpression<T>("<<", result, additive());
            continue;
        }
        if (match(TokenType::Rshift))
        {
            result = new BinaryExpression<T>(">>", result, additive());
            continue;
        }
        if (match(TokenType::Ampersand))
        {
            result = new BinaryExpression<T>("&", result, additive());
            continue;
        }
        if (match(TokenType::Caret))
        {
            result = new BinaryExpression<T>("^", result, additive());
            continue;
        }
        if (match(TokenType::Pipe))
        {
            result = new BinaryExpression<T>("|", result, additive());
            continue;
        }
        break;
    }
    return result;
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
        if (match(TokenType::Percentage))
        {
            result = new BinaryExpression<T>("%", result, multiplicative());
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
    if (match(TokenType::Tilde))
        return new UnaryExpression<T>("~", primary());
    return primary();
}

template <class T>
Expression<T> *Parser<T>::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new ValueExpression<T>(std::stoll(current.getText()));
    if (match(TokenType::FloatNumber))
        return new ValueExpression<T>(std::stod(current.getText()));
    if (match(TokenType::HexNumber))
        return new ValueExpression<T>(std::stoull(current.getText(), nullptr, 16));
    if (match(TokenType::OctNumber))
        return new ValueExpression<T>(std::stoull(current.getText(), nullptr, 8));
    if (match(TokenType::StringValue))
        throw std::runtime_error(ERR_MSG_STR_IN_NOT_STR_STMNT);
    if (match(TokenType::Identifier))
        return new VariablesExpression<T>(current.getText());
    if (match(TokenType::Lparen))
    {
        Expression<T> *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
        return result;
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
}

template <>
Expression<kondra::string> *Parser<kondra::string>::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new ValueExpression<kondra::string>(current.getText());
    if (match(TokenType::FloatNumber))
        return new ValueExpression<kondra::string>(current.getText());
    if (match(TokenType::HexNumber))
        return new ValueExpression<kondra::string>(current.getText());
    if (match(TokenType::OctNumber))
        return new ValueExpression<kondra::string>(current.getText());
    if (match(TokenType::StringValue))
        return new ValueExpression<kondra::string>(current.getText());
    if (match(TokenType::Identifier))
        return new VariablesExpression<kondra::string>(current.getText());
    if (match(TokenType::Lparen))
    {
        Expression<kondra::string> *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
        return result;
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
}

template <>
Expression<kondra::var> *Parser<kondra::var>::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new ValueExpression<kondra::var>(kondra::dynamic_int(current.getText()));
    if (match(TokenType::FloatNumber))
        return new ValueExpression<kondra::var>(std::stod(current.getText()));
    if (match(TokenType::HexNumber))
        return new ValueExpression<kondra::var>(kondra::dynamic_int(current.getText(), 16));
    if (match(TokenType::OctNumber))
        return new ValueExpression<kondra::var>(kondra::dynamic_int(current.getText(), 8));
    if (match(TokenType::StringValue))
        return new ValueExpression<kondra::var>(current.getText());
    if (match(TokenType::Identifier))
        return new VariablesExpression<kondra::var>(current.getText());
    if (match(TokenType::Lparen))
    {
        Expression<kondra::var> *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
        return result;
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
}

template <class T>
void Parser<T>::setTokens(std::vector<Token> tokens)
{
    this->tokens = tokens;
    size = tokens.size();
    pos = 0;
}

#endif