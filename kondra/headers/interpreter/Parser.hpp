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
    Expression<T> *conditional();
    Statement *ifElseStatement();

public:
    Parser(std::vector<Token> = std::vector<Token>());
    std::vector<Statement *> parse();
    void setTokens(std::vector<Token>);
};

std::vector<Statement *> chosingParser(const std::vector<Token> &tokens, const Type &element)
{
    switch (element)
    {
    case Type::Int64:
        return Parser<long long>(tokens).parse();

    case Type::UInt64:
        return Parser<unsigned long long>(tokens).parse();

    case Type::Int32:
        return Parser<int>(tokens).parse();

    case Type::UInt32:
        return Parser<unsigned int>(tokens).parse();

    case Type::Int16:
        return Parser<short>(tokens).parse();

    case Type::UInt16:
        return Parser<unsigned short>(tokens).parse();

    case Type::Int8:
        return Parser<signed char>(tokens).parse();

    case Type::UInt8:
        return Parser<unsigned char>(tokens).parse();

    case Type::Int:
        return Parser<kondra::dynamic_int>(tokens).parse();

    case Type::Float80:
        return Parser<long double>(tokens).parse();

    case Type::Float64:
        return Parser<double>(tokens).parse();

    case Type::Float32:
        return Parser<float>(tokens).parse();

    case Type::Bool:
        return Parser<bool>(tokens).parse();

    case Type::String:
        return Parser<kondra::string>(tokens).parse();

    case Type::Var:
        return Parser<kondra::var>(tokens).parse();

    case Type::None:
        throw std::runtime_error("Unknown identifier");
    }
    throw std::runtime_error("Error!");
}

std::vector<Statement *> parsing(std::vector<std::vector<Token>> &tokens,
                                 const size_t &posOfStatement, size_t posOfToken = 0)
{
    if (tokens.empty())
    {
        return std::vector<Statement *>();
    }
    std::string textOfkeyWord;
    switch (tokens[posOfStatement][posOfToken].getType())
    {
    case TokenType::KeyWord:
        textOfkeyWord = tokens[posOfStatement][posOfToken].getText();
        if (textOfkeyWord == "int64")
            return Parser<long long>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "uint64")
            return Parser<unsigned long long>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "int32")
            return Parser<int>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "uint32")
            return Parser<unsigned int>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "int16")
            return Parser<short>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "uint16")
            return Parser<unsigned short>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "int8")
            return Parser<signed char>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "uint8")
            return Parser<unsigned char>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "int")
            return Parser<kondra::dynamic_int>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "float32")
            return Parser<float>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "float64")
            return Parser<double>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "float80")
            return Parser<long double>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "boolean")
            return Parser<bool>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "string")
            return Parser<kondra::string>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "var")
            return Parser<kondra::var>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "console_out")
            return Parser<kondra::string>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "if")
        {
            if (tokens[posOfStatement + 1][posOfToken].getText() == "else")
            {
                tokens[posOfStatement].insert(tokens[posOfStatement].end(),
                                              tokens[posOfStatement + 1].begin(), tokens[posOfStatement + 1].end());
                tokens.erase(tokens.begin() + posOfStatement + 1);
            }
            return parsing(tokens, posOfStatement, posOfToken + 1);
        }

    case TokenType::Identifier:
        return chosingParser(tokens[posOfStatement],
                             ListOfVariables::getType(tokens[posOfStatement][posOfToken].getText()));
    case TokenType::Lparen:
        return parsing(tokens, posOfStatement, posOfToken + 1);
    case TokenType::StringValue:
        return Parser<kondra::string>(tokens[posOfStatement]).parse();
    default:
        return Parser<double>(tokens[posOfStatement]).parse();
    }
    throw std::runtime_error("Error");
}

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
        else if (current.getText() == "if")
        {
            consume(KeyWord);
            return ifElseStatement();
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
Statement *Parser<T>::ifElseStatement()
{
    Expression<T> *condition = expression();
    // Statement *ifStatement = statement();
    auto posOfElse = std::find_if(tokens.begin() + pos, tokens.end(),
                               [](Token t){
                                    return t.getType() == KeyWord && t.getText() == "else";
                                }
    );
    std::vector<std::vector<Token>> tokensOfifStatement(
        1, std::vector<Token>(tokens.begin() + pos, posOfElse)
    );
    std::vector<std::vector<Token>> tokensOfElseStatement;
    Statement *ifStatement = parsing(tokensOfifStatement, 0)[0];
    Statement *elseStatement;
    if (posOfElse != tokens.end())
    {
        consume(TokenType::KeyWord);
        tokensOfElseStatement = std::vector<std::vector<Token>>(
            1, std::vector<Token>(posOfElse + 1, tokens.end())
        );
        elseStatement = parsing(tokensOfElseStatement, 0)[0];
    }
    else
        elseStatement = nullptr;
    pos = tokens.size();
    return new IfStatement<T>(condition, ifStatement, elseStatement);
}

template <class T>
Expression<T> *Parser<T>::expression()
{
    Expression<T> *result = conditional();
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
Expression<T> *Parser<T>::conditional()
{
    Expression<T> *result = bitwise();
    while (true)
    {
        if (match(TokenType::DoubleEqual))
        {
            result = new ConditionalExpression<T>("==", result, bitwise());
            continue;
        }
        if (match(TokenType::Less))
        {
            result = new ConditionalExpression<T>("<", result, bitwise());
            continue;
        }
        if (match(TokenType::More))
        {
            result = new ConditionalExpression<T>(">", result, bitwise());
            continue;
        }
        if (match(TokenType::LessOrEqual))
        {
            result = new ConditionalExpression<T>("<=", result, bitwise());
            continue;
        }
        if (match(TokenType::MoreOrEqual))
        {
            result = new ConditionalExpression<T>(">=", result, bitwise());
            continue;
        }
        if (match(TokenType::ExclamationAndEqual))
        {
            result = new ConditionalExpression<T>("!=", result, bitwise());
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
    if (match(TokenType::Exclamation))
        return new UnaryExpression<T>("!", primary());
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