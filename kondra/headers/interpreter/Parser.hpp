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

class Parser final
{
private:
    static const Token eof;
    size_t pos = 0;
    size_t size;
    std::vector<Token> tokens;

    Token get(size_t = 0);
    bool match(TokenType);
    Token consume(TokenType);
    Expression *expression();
    Expression *primary(); // #1
    Expression *postfixUnary(); // #2
    Expression *prefixUnary(); // #3
    Expression *multiplicative(); // #4
    Expression *additive(); // #5
    Expression *shift(); // #6
    Expression *relation(); // #7
    Expression *equality(); // #8
    Expression *bitwiseAnd(); // #9
    Expression *bitwiseXor(); // #10
    Expression *bitwiseOr(); // #11
    Expression *logicalAnd(); // #12
    Expression *logicalOr(); // #13
    Expression *ternary(); // #14
    Statement *statement();
    Statement *assignmentStatement();
    Statement *variableDeclarationStatement();
    Statement *ifElseStatement();
    Statement *whileStatement();
    Statement *doWhileStatement();
    Statement *forStatement();
    Statement *block();
    Statement *statementOrBlock();

public:
    Parser(std::vector<Token> = std::vector<Token>());
    Statement *parse();
};

const Token Parser::eof = Token(TokenType::Eof);

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

Parser::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
    size = tokens.size();
}

Token Parser::get(size_t relativePosition)
{
    size_t position = pos + relativePosition;
    if (position >= size)
        return eof;
    return tokens[position];
}

bool Parser::match(TokenType type)
{
    Token current = get();
    if (type != current.getType())
        return false;
    ++pos;
    return true;
}

Token Parser::consume(TokenType type)
{
    Token current = get();
    if (type != current.getType())
        throw std::runtime_error(ERR_MSG_WRNG_TOKEN_TYPE);
    ++pos;
    return current;
}

Statement *Parser::parse()
{
    BlockStatement *result = new BlockStatement();
    while (!match(TokenType::Eof)) {
        result->add(statement());
    }
    return result;
}

Statement *Parser::block()
{
    BlockStatement *block = new BlockStatement();
    consume(TokenType::Lbrace);
    while (!match(TokenType::Rbrace)) {
        block->add(statement());
    }
    return block;
}

Statement *Parser::statementOrBlock()
{
    if (get().getType() == TokenType::Lbrace)
        return block();
    return statement();
}

Statement *Parser::statement()
{
    Token current = get();
    switch (current.getType())
    {
    case KeyWord:
        if (current.getText() == "console_out")
        {
            consume(KeyWord);
            return new PrintStatement(expression());
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
        else if (current.getText() == "do")
        {
            consume(KeyWord);
            return doWhileStatement();
        }
        else if (current.getText() == "for")
        {
            consume(KeyWord);
            return forStatement();
        }
        else if (current.getText() == "break")
        {
            consume(KeyWord);
            return new BreakStatement();
        }
        else if (current.getText() == "continue")
        {
            consume(KeyWord);
            return new ContinueStatement();
        }
        else
            return variableDeclarationStatement();

    case Identifier:
        return assignmentStatement();

    default:
        throw std::runtime_error(ERR_MSG_UNKNWN_STMNT);
    }
}

Statement *Parser::variableDeclarationStatement()
{
    std::string type = get().getText();
    std::string identifierOfVariable = get(1).getText();
    Expression *value = nullptr;
    if (match(TokenType::KeyWord) && match(TokenType::Identifier))
    {
        if (match(TokenType::Equal))
            value = expression();
        return new VariableDeclarationStatement(type, identifierOfVariable, value);
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_OP);
}

Statement *Parser::assignmentStatement()
{
    Token current = get();
    std::string identifierOfVariable;
    if (match(TokenType::Identifier))
    {
        identifierOfVariable = current.getText();
        if (match(TokenType::Equal))
            return new AssignmentStatement(identifierOfVariable, expression());
        else if (match(TokenType::PlusAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("+", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::MinusAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("-", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::StarAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("*", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::SlashAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("/", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::PercentageAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("%", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::AmpersandAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("&", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::CaretAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("^", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::PipeAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("|", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::LshiftAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression("<<", new VariablesExpression(identifierOfVariable),
                    expression()));
        else if (match(TokenType::RshiftAndEqual))
            return new AssignmentStatement(identifierOfVariable,
                new BinaryExpression(">>", new VariablesExpression(identifierOfVariable),
                    expression()));
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_OP);
}

Statement *Parser::ifElseStatement()
{
    Expression *condition = expression();
    Statement *ifStatement = statementOrBlock();
    Statement *elseStatement = nullptr;
    if (get().getText() == "else")
    {
        consume(TokenType::KeyWord);
        elseStatement = statementOrBlock();
    }
    return new IfStatement(condition, ifStatement, elseStatement);
}

Statement *Parser::whileStatement()
{
    Expression *condition = expression();
    Statement *statement = statementOrBlock();
    return new WhileStatement(condition, statement);
}

Statement *Parser::doWhileStatement()
{
    Statement *statement = statementOrBlock();
    if (get().getText() != "while")
        throw std::runtime_error("Missing while key word");
    consume(TokenType::KeyWord);
    Expression *condition = expression();
    return new DoWhileStatement(condition, statement);
}

Statement *Parser::forStatement()
{
    Statement *initialization = statement();
    consume(TokenType::Semicolon);
    Expression *termination = expression();
    consume(TokenType::Semicolon);
    Statement *increment = statement();
    Statement *block = statementOrBlock();
    return new ForStatement(initialization, termination, increment, block);
}

Expression *Parser::expression()
{
    return ternary();
}

Expression *Parser::ternary()
{
    Expression *result = logicalOr();
    while (true)
    {
        if (match(TokenType::Question))
        {
            Expression *exprIfTrue = ternary();
            consume(TokenType::Colon);
            result = new TernaryExpression(result, exprIfTrue, ternary());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::logicalOr()
{
    Expression *result = logicalAnd();
    while (true)
    {
        if (match(TokenType::DoublePipe))
        {
            result = new ConditionalExpression("||", result, logicalAnd());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::logicalAnd()
{
    Expression *result = bitwiseOr();
    while (true)
    {
        if (match(TokenType::DoubleAmpersand))
        {
            result = new ConditionalExpression("&&", result, bitwiseOr());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::bitwiseOr()
{
    Expression *result = bitwiseXor();
    while (true)
    {
        if (match(TokenType::Pipe))
        {
            result = new BinaryExpression("|", result, bitwiseXor());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::bitwiseXor()
{
    Expression *result = bitwiseAnd();
    while (true)
    {
        if (match(TokenType::Caret))
        {
            result = new BinaryExpression("^", result, bitwiseAnd());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::bitwiseAnd()
{
    Expression *result = equality();
    while (true)
    {
        if (match(TokenType::Ampersand))
        {
            result = new BinaryExpression("&", result, equality());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::equality()
{
    Expression *result = relation();
    while (true)
    {
        if (match(TokenType::DoubleEqual))
        {
            result = new ConditionalExpression("==", result, relation());
            continue;
        }
        if (match(TokenType::ExclamationAndEqual))
        {
            result = new ConditionalExpression("!=", result, relation());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::relation()
{
    Expression *result = shift();
    while (true)
    {
        if (match(TokenType::Less))
        {
            result = new ConditionalExpression("<", result, shift());
            continue;
        }
        if (match(TokenType::More))
        {
            result = new ConditionalExpression(">", result, shift());
            continue;
        }
        if (match(TokenType::LessOrEqual))
        {
            result = new ConditionalExpression("<=", result, shift());
            continue;
        }
        if (match(TokenType::MoreOrEqual))
        {
            result = new ConditionalExpression(">=", result, shift());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::shift()
{
    Expression *result = additive();
    while (true)
    {
        if (match(TokenType::Lshift))
        {
            result = new BinaryExpression("<<", result, additive());
            continue;
        }
        if (match(TokenType::Rshift))
        {
            result = new BinaryExpression(">>", result, additive());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::additive()
{
    Expression *result = multiplicative();
    while (true)
    {
        if (match(TokenType::Plus))
        {
            result = new BinaryExpression("+", result, multiplicative());
            continue;
        }
        if (match(TokenType::Minus))
        {
            result = new BinaryExpression("-", result, multiplicative());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::multiplicative()
{
    Expression *result = prefixUnary();
    while (true)
    {
        if (match(TokenType::Star))
        {
            result = new BinaryExpression("*", result, prefixUnary());
            continue;
        }
        if (match(TokenType::Slash))
        {
            result = new BinaryExpression("/", result, prefixUnary());
            continue;
        }
        if (match(TokenType::Percentage))
        {
            result = new BinaryExpression("%", result, prefixUnary());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::prefixUnary()
{
    if (match(TokenType::Minus))
        return new UnaryExpression("-", prefixUnary());
    if (match(TokenType::Plus))
        return primary();
    if (match(TokenType::Tilde))
        return new UnaryExpression("~", prefixUnary());
    if (match(TokenType::Exclamation))
        return new UnaryExpression("!", prefixUnary());
    return postfixUnary();
}

Expression *Parser::postfixUnary()
{
    return primary();
}

Expression *Parser::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new ValueExpression(new IValue(current.getText()));
    if (match(TokenType::FloatNumber))
        return new ValueExpression(new F64Value(std::stod(current.getText())));
    if (match(TokenType::HexNumber))
        return new ValueExpression(new IValue(kondra::dynamic_int(current.getText(), 16)));
    if (match(TokenType::OctNumber))
        return new ValueExpression(new IValue(kondra::dynamic_int(current.getText(), 8)));
    if (match(TokenType::BoolValue))
        return new ValueExpression(current.getText() == "true" ? new BValue(true) : new BValue(false));
    if (match(TokenType::StringValue))
        return new ValueExpression(new StrValue(current.getText()));
    if (match(TokenType::FstringValue))
        return new FormatStringExpression(current.getText());
    if (match(TokenType::Identifier))
        return new VariablesExpression(current.getText());
    if (match(TokenType::KeyWord))
    {
        if (current.getText() == "console_in")
            return new InputExpression();
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
        Expression *result = expression();
        if (!match(TokenType::Rparen))
            throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
        return result;
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_EXPR);
}

#endif