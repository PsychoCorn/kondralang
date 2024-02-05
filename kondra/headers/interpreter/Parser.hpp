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
#define ERR_MSG_UNKNWN_KW_IN_EXP "Unknown keyword in expression"

template <class T>
class Parser final
{
private:
    size_t pos = 0;
    size_t size;
    std::vector<Token> tokens;

    Token get(size_t = 0);
    bool match(TokenType);
    Token consume(TokenType);
    Expression<T> *expression();
    Expression<T> *primary(); // #1
    Expression<T> *postfixUnary(); // #2
    Expression<T> *prefixUnary(); // #3
    Expression<T> *multiplicative(); // #4
    Expression<T> *additive(); // #5
    Expression<T> *shift(); // #6
    Expression<T> *relation(); // #7
    Expression<T> *equality(); // #8
    Expression<T> *bitwiseAnd(); // #9
    Expression<T> *bitwiseXor(); // #10
    Expression<T> *bitwiseOr(); // #11
    Expression<T> *logicalAnd(); // #12
    Expression<T> *logicalOr(); // #13
    Expression<T> *ternary(); // #14
    Statement *statement();
    Statement *assignmentStatement();
    Statement *variableDeclarationStatement();
    Statement *ifElseStatement();
    Statement *whileStatement();
    Statement *forStatement();
    Statement *block();
    Statement *statementOrBlock();

public:
    Parser(std::vector<Token> = std::vector<Token>());
    Statement *parse();
    void setTokens(std::vector<Token>);
};

std::vector<Token> getTokensOfBlockStatement(std::vector<Token> tokens, 
    std::vector<Token>::iterator& iter)
{
    std::vector<Token> result;
    result.push_back(*iter);
    iter++;
    for (; iter != tokens.end(); iter++)
    {
        if (iter->getType() == TokenType::Lbrace)
        {
            auto blockStatement = getTokensOfBlockStatement(tokens, iter);
            result.insert(result.end(), blockStatement.begin(), blockStatement.end());
            continue;
        }
        result.push_back(*iter);
        if (iter->getType() == TokenType::Rbrace)
            return result;
    }
    throw std::runtime_error("End of block statement wasn't reached");
}

std::vector<std::vector<Token>> splitToStatements(std::vector<Token> tokens)
{
    std::vector<std::vector<Token>> result;
    std::vector<Token> statement;
    for (auto token = tokens.begin(); token != tokens.end(); token++)
    {
        if (token->getType() == TokenType::Semicolon)
        {
            result.push_back(statement);
            statement.clear();
            continue;
        }
        else if (token->getType() == TokenType::Lbrace)
        {
            auto blockStatement = getTokensOfBlockStatement(tokens, token);
            statement.insert(statement.end(), blockStatement.begin(), blockStatement.end());
            result.push_back(statement);
            statement.clear();
            continue;
        }
        statement.push_back(*token);
    }
    return result;
}

Statement *chosingParser(const std::vector<Token> &tokens, const Type &element)
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

Statement *parsing(std::vector<std::vector<Token>> &tokens,
                   const size_t &posOfStatement, size_t posOfToken = 0)
{
    if (tokens.empty())
    {
        return nullptr;
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
        else if (textOfkeyWord == "string" || textOfkeyWord == "console_out" || textOfkeyWord == "break" ||
            textOfkeyWord == "continue")
            return Parser<kondra::string>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "var" || textOfkeyWord == "int_var" || 
            textOfkeyWord == "float_var" || textOfkeyWord == "string_var" || 
                textOfkeyWord == "bool_var")
            return Parser<kondra::var>(tokens[posOfStatement]).parse();
        else if (textOfkeyWord == "console_in" || textOfkeyWord == "while" || textOfkeyWord == "for")
            return parsing(tokens, posOfStatement, posOfToken + 1);
        else if (textOfkeyWord == "if")
        {
            while (posOfStatement + 1 < tokens.size() && 
                tokens[posOfStatement + 1][posOfToken].getText() == "else")
            {
                tokens[posOfStatement].insert(tokens[posOfStatement].end(),
                    tokens[posOfStatement + 1].begin(), tokens[posOfStatement + 1].end());
                tokens.erase(tokens.begin() + posOfStatement + 1);
            }
            return parsing(tokens, posOfStatement, posOfToken + 1);
        }

    case TokenType::Identifier:
        return chosingParser(tokens[posOfStatement],
            ListOfIdentifiers::getType(tokens[posOfStatement][posOfToken].getText()));
    case TokenType::Lparen:
        return parsing(tokens, posOfStatement, posOfToken + 1);
    case TokenType::Lbrace:
        return parsing(tokens, posOfStatement, posOfToken + 1);
    case TokenType::StringValue:
        return Parser<kondra::string>(tokens[posOfStatement]).parse();
    case TokenType::FstringValue:
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
Token Parser<T>::get(size_t relativePosition)
{
    size_t position = pos + relativePosition;
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
Statement *Parser<T>::parse()
{
    if (!match(TokenType::Eof))
        return statementOrBlock();
    return nullptr;
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
        else if (current.getText() == "while")
        {
            consume(KeyWord);
            return whileStatement();
        }
        else if (current.getText() == "for")
        {
            consume(KeyWord);
            return forStatement();
        }
        else if (current.getText() == "break")
            return new BreakStatement();
        else if (current.getText() == "continue")
            return new ContinueStatement();
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
Statement *Parser<kondra::var>::variableDeclarationStatement()
{
    std::string type = get().getText();
    std::string identifierOfVariable = get(1).getText();
    if (match(TokenType::KeyWord) && match(TokenType::Identifier))
    {
        if (match(TokenType::Equal))
            return new VariableDeclarationStatement<kondra::var>(identifierOfVariable, expression());
        return new VariableDeclarationStatement<kondra::var>(identifierOfVariable, 
            new ValueExpression<kondra::var>(kondra::var()));
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
            return new VariableDeclarationStatement<kondra::string>(identifierOfVariable, 
                expression());
        return new VariableDeclarationStatement<kondra::string>(identifierOfVariable, 
            new ValueExpression<kondra::string>(""));
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
    consume(TokenType::Colon);
    auto posOfElse = std::find_if(tokens.begin() + pos, tokens.end(),
        [](Token t)
        {
            return t.getType() == KeyWord && t.getText() == "else";
        });
    std::vector<std::vector<Token>> tokensOfifStatement(
        1, std::vector<Token>(tokens.begin() + pos, posOfElse));
    std::vector<std::vector<Token>> tokensOfElseStatement;
    Statement *ifStatement = parsing(tokensOfifStatement, 0);
    Statement *elseStatement;
    if (posOfElse != tokens.end())
    {
        if ((posOfElse + 1)->getType() != Colon)
            throw std::runtime_error(ERR_MSG_WRNG_TOKEN_TYPE);
        tokensOfElseStatement = std::vector<std::vector<Token>>(
            1, std::vector<Token>(posOfElse + 2, tokens.end()));
        elseStatement = parsing(tokensOfElseStatement, 0);
    }
    else
        elseStatement = nullptr;
    // pos = tokens.size();
    return new IfStatement<T>(condition, ifStatement, elseStatement);
}

template <class T>
Statement *Parser<T>::whileStatement()
{
    Expression<T> *condition = expression();
    consume(TokenType::Colon);
    std::vector<std::vector<Token>> tokensOfStatement(
        1, std::vector<Token>(tokens.begin() + pos, tokens.end()));
    Statement *statement = parsing(tokensOfStatement, 0);
    return new WhileStatement<T>(condition, statement);
}

template <class T>
Statement *Parser<T>::forStatement()
{
    // find and parsing initialization statement
    auto posOfComma = std::find_if(tokens.begin() + pos, tokens.end(),
        [](Token t)
        {
            return t.getType() == Comma;
        });
    Statement *initialization = Parser<T>(std::vector<Token>(tokens.begin() + pos, posOfComma)).parse();
    initialization->execute();
    // parsing termination expression
    pos = std::distance(tokens.begin(), posOfComma + 1);
    Expression<T> *termination = expression();
    // find and parsing increment statement
    auto posOfColon = std::find_if(tokens.begin() + pos + 1, tokens.end(),
        [](Token t)
        {
            return t.getType() == Colon;
        });
    if (posOfColon == tokens.end())
        throw std::runtime_error(ERR_MSG_WRNG_TOKEN_TYPE);
    Statement *increment = 
        Parser<T>(std::vector<Token>(tokens.begin() + pos + 1, posOfColon)).parse();
    // find and parsing block statement
    std::vector<std::vector<Token>> tokensOfBlock(
        1, std::vector<Token>(posOfColon + 1, tokens.end()));
    Statement *block = parsing(tokensOfBlock, 0);
    return new ForStatement<T>(initialization, termination, increment, block);
}

template <class T>
Expression<T> *Parser<T>::expression()
{
    return ternary();
}

template <class T>
Expression<T> *Parser<T>::ternary()
{
    Expression<T> *result = logicalOr();
    while (true)
    {
        if (match(TokenType::Question))
        {
            Expression<T> *exprIfTrue = ternary();
            consume(TokenType::Colon);
            result = new TernaryExpression<T>(result, exprIfTrue, ternary());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::logicalOr()
{
    Expression<T> *result = logicalAnd();
    while (true)
    {
        if (match(TokenType::DoublePipe))
        {
            result = new ConditionalExpression<T>("||", result, logicalAnd());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::logicalAnd()
{
    Expression<T> *result = bitwiseOr();
    while (true)
    {
        if (match(TokenType::DoubleAmpersand))
        {
            result = new ConditionalExpression<T>("&&", result, bitwiseOr());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::bitwiseOr()
{
    Expression<T> *result = bitwiseXor();
    while (true)
    {
        if (match(TokenType::Pipe))
        {
            result = new BinaryExpression<T>("|", result, bitwiseXor());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::bitwiseXor()
{
    Expression<T> *result = bitwiseAnd();
    while (true)
    {
        if (match(TokenType::Caret))
        {
            result = new BinaryExpression<T>("^", result, bitwiseAnd());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::bitwiseAnd()
{
    Expression<T> *result = equality();
    while (true)
    {
        if (match(TokenType::Ampersand))
        {
            result = new BinaryExpression<T>("&", result, equality());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::equality()
{
    Expression<T> *result = relation();
    while (true)
    {
        if (match(TokenType::DoubleEqual))
        {
            result = new ConditionalExpression<T>("==", result, relation());
            continue;
        }
        if (match(TokenType::ExclamationAndEqual))
        {
            result = new ConditionalExpression<T>("!=", result, relation());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::relation()
{
    Expression<T> *result = shift();
    while (true)
    {
        if (match(TokenType::Less))
        {
            result = new ConditionalExpression<T>("<", result, shift());
            continue;
        }
        if (match(TokenType::More))
        {
            result = new ConditionalExpression<T>(">", result, shift());
            continue;
        }
        if (match(TokenType::LessOrEqual))
        {
            result = new ConditionalExpression<T>("<=", result, shift());
            continue;
        }
        if (match(TokenType::MoreOrEqual))
        {
            result = new ConditionalExpression<T>(">=", result, shift());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::shift()
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
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::multiplicative()
{
    Expression<T> *result = prefixUnary();
    while (true)
    {
        if (match(TokenType::Star))
        {
            result = new BinaryExpression<T>("*", result, prefixUnary());
            continue;
        }
        if (match(TokenType::Slash))
        {
            result = new BinaryExpression<T>("/", result, prefixUnary());
            continue;
        }
        if (match(TokenType::Percentage))
        {
            result = new BinaryExpression<T>("%", result, prefixUnary());
            continue;
        }
        break;
    }
    return result;
}

template <class T>
Expression<T> *Parser<T>::prefixUnary()
{
    if (match(TokenType::Minus))
        return new UnaryExpression<T>("-", prefixUnary());
    if (match(TokenType::Plus))
        return primary();
    if (match(TokenType::Tilde))
        return new UnaryExpression<T>("~", prefixUnary());
    if (match(TokenType::Exclamation))
        return new UnaryExpression<T>("!", prefixUnary());
    return postfixUnary();
}

template <class T>
Expression<T> *Parser<T>::postfixUnary()
{
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
    if (match(TokenType::StringValue) || match(TokenType::FstringValue))
        throw std::runtime_error(ERR_MSG_STR_IN_NOT_STR_STMNT);
    if (match(TokenType::Identifier))
        return new VariablesExpression<T>(current.getText());
    if (match(TokenType::KeyWord))
    {
        if (current.getText() == "console_in")
            return new InputExpression<T>();
        else
            throw std::runtime_error(ERR_MSG_UNKNWN_KW_IN_EXP);
    }
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
    if (match(TokenType::FstringValue))
        return new FormatStringExpression<kondra::string>(current.getText());
    if (match(TokenType::Identifier))
        return new VariablesExpression<kondra::string>(current.getText());
    if (match(TokenType::KeyWord))
    {
        if (current.getText() == "console_in")
            return new InputExpression<kondra::string>();
        else
            throw std::runtime_error(ERR_MSG_UNKNWN_KW_IN_EXP);
    }
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
    if (match(TokenType::FstringValue))
        return new FormatStringExpression<kondra::var>(current.getText());
    if (match(TokenType::Identifier))
        return new VariablesExpression<kondra::var>(current.getText());
    if (match(TokenType::KeyWord))
    {
        if (current.getText() == "console_in")
            return new InputExpression<kondra::var>();
        else if (current.getText() == "int_var")
            return new VariableConvertationExpression(expression(), kondra::VarType::Int);
        else if (current.getText() == "float_var")
            return new VariableConvertationExpression(expression(), kondra::VarType::Float);
        else if (current.getText() == "string_var")
            return new VariableConvertationExpression(expression(), kondra::VarType::String);
        else if (current.getText() == "boolean_var")
            return new VariableConvertationExpression(expression(), kondra::VarType::Bool);
        else
            throw std::runtime_error(ERR_MSG_UNKNWN_KW_IN_EXP);
    }
    if (match(TokenType::Lparen))
    {
        Expression<kondra::var> *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
        return result;
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
}

template <>
Expression<kondra::dynamic_int> *Parser<kondra::dynamic_int>::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new ValueExpression<kondra::dynamic_int>(current.getText());
    if (match(TokenType::FloatNumber))
        return new ValueExpression<kondra::dynamic_int>(current.getText());
    if (match(TokenType::HexNumber))
        return new ValueExpression<kondra::dynamic_int>(kondra::dynamic_int(current.getText(), 16));
    if (match(TokenType::OctNumber))
        return new ValueExpression<kondra::dynamic_int>(kondra::dynamic_int(current.getText(), 8));
    if (match(TokenType::StringValue) || match(TokenType::FstringValue))
        throw std::runtime_error(ERR_MSG_STR_IN_NOT_STR_STMNT);
    if (match(TokenType::Identifier))
        return new VariablesExpression<kondra::dynamic_int>(current.getText());
    if (match(TokenType::KeyWord))
    {
        if (current.getText() == "console_in")
            return new InputExpression<kondra::dynamic_int>();
        else
            throw std::runtime_error(ERR_MSG_UNKNWN_KW_IN_EXP);
    }
    if (match(TokenType::Lparen))
    {
        Expression<kondra::dynamic_int> *result = expression();
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

template <class T>
Statement *Parser<T>::block()
{
    BlockStatement *block = new BlockStatement();
    // consume(TokenType::Lbrace);
    std::vector<std::vector<Token>> statementsOfBlockStatement = 
        splitToStatements(std::vector<Token>(tokens.begin() + 1, tokens.end() - 1));
    for (size_t posOfStatement = 0; posOfStatement < statementsOfBlockStatement.size(); 
            posOfStatement++)
        block->add(parsing(statementsOfBlockStatement, posOfStatement));
    return block;
}

template <class T>
Statement *Parser<T>::statementOrBlock()
{
    if (get().getType() == TokenType::Lbrace)
        return block();
    return statement();
}

#endif