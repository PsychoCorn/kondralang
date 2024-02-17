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
    FunctionalExpression *function(const std::string &);
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
    Statement *assignmentStatement(const std::string &);
    Statement *variableDeclarationStatement();
    Statement *ifElseStatement();
    Statement *whileStatement();
    Statement *doWhileStatement();
    FunctionDefineStatement *functionDefine();
    Statement *forStatement();
    Statement *block();
    Statement *statementOrBlock();

public:
    Parser(std::vector<Token> = std::vector<Token>());
    Statement *parse();
};

const Token Parser::eof = Token(TokenType::Eof);

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
        if (current.getText() == "if")
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
        else if (current.getText() == "func")
        {
            consume(KeyWord);
            return functionDefine();
        }
        else if (current.getText() == "return")
        {
            consume(KeyWord);
            return new ReturnStatement(expression());
        }
        else if (current.getText() == "free")
        {
            consume(KeyWord);
            std::string identifier = consume(TokenType::Identifier).getText();
            return new FreeStatement(identifier);
        }
        else
            return variableDeclarationStatement();

    case Identifier:
        consume(TokenType::Identifier);
        if (match(TokenType::Lparen))
            return new FunctionalStatement(function(current.getText()));
        else if (match(TokenType::DoublePlus))
            return new IncrementStatement(current.getText(), DoublePlus, false);
        else if (match(TokenType::DoubleMinus))
            return new IncrementStatement(current.getText(), DoubleMinus, false);
        return assignmentStatement(current.getText());

    case DoublePlus:
        consume(TokenType::DoublePlus);
        return new IncrementStatement(consume(Identifier).getText(), DoublePlus, true);

    case DoubleMinus:
        consume(TokenType::DoubleMinus);
        return new IncrementStatement(consume(Identifier).getText(), DoubleMinus, true);

    default:
        throw std::runtime_error(ERR_MSG_UNKNWN_STMNT);
    }
}

Statement *Parser::variableDeclarationStatement()
{
    bool isGlobal = false;
    bool isConst = false;
    std::string type = get().getText();
    if (type == "global")
    {    
        isGlobal = true;
        consume(TokenType::KeyWord);
        type = get().getText();
    }
    if (get().getText() == "const")
    {    
        isConst = true;
        consume(TokenType::KeyWord);
        type = get().getText();
    }
    std::string identifierOfVariable = get(1).getText();
    Expression *value = nullptr;
    if (match(TokenType::KeyWord) && match(TokenType::Identifier))
    {
        if (match(TokenType::Equal))
            value = expression();
        else if (isConst && value == nullptr)
            throw std::runtime_error("Constant can't be not initialized");
        return new VariableDeclarationStatement(isGlobal, isConst, type, identifierOfVariable, value);
    }
    throw std::runtime_error(ERR_MSG_UNKNWN_OP);
}

Statement *Parser::assignmentStatement(const std::string &identifierOfVariable)
{
    if (match(TokenType::Equal))
        return new AssignmentStatement(identifierOfVariable, expression());
    else if (match(TokenType::PlusAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Plus, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::MinusAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Minus, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::StarAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Star, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::SlashAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Slash, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::PercentageAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Percentage, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::AmpersandAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Ampersand, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::CaretAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Caret, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::PipeAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Pipe, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::LshiftAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Lshift, new VariablesExpression(identifierOfVariable),
                expression()));
    else if (match(TokenType::RshiftAndEqual))
        return new AssignmentStatement(identifierOfVariable,
            new BinaryExpression(TokenType::Rshift, new VariablesExpression(identifierOfVariable),
                expression()));
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

FunctionalExpression *Parser::function(const std::string &name)
{
    FunctionalExpression *function = new FunctionalExpression(name);
    while (!match(TokenType::Rparen))
    {
        function->addArgument(expression());
        match(TokenType::Comma);
    }
    return function;
}

FunctionDefineStatement *Parser::functionDefine()
{
    std::string name = consume(TokenType::Identifier).getText();
    consume(TokenType::Lparen);
    std::list<FunctionArg> args;
    while (!match(TokenType::Rparen))
    {
        bool isConst = false;
        std::string type = consume(TokenType::KeyWord).getText();
        if (type == "const")
        {
            isConst = true;
            type = consume(TokenType::KeyWord).getText();
        }
        std::string identifier = consume(TokenType::Identifier).getText();
        args.push_back(FunctionArg(type, identifier, isConst));
        match(TokenType::Comma);
    }
    Statement *body = statementOrBlock();
    return new FunctionDefineStatement(name, args, body);
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
            result = new ConditionalExpression(TokenType::DoublePipe, result, logicalAnd());
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
            result = new ConditionalExpression(TokenType::DoubleAmpersand, result, bitwiseOr());
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
            result = new BinaryExpression(TokenType::Pipe, result, bitwiseXor());
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
            result = new BinaryExpression(TokenType::Caret, result, bitwiseAnd());
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
            result = new BinaryExpression(TokenType::Ampersand, result, equality());
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
            result = new ConditionalExpression(TokenType::DoubleEqual, result, relation());
            continue;
        }
        if (match(TokenType::ExclamationAndEqual))
        {
            result = new ConditionalExpression(TokenType::ExclamationAndEqual, result, relation());
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
            result = new ConditionalExpression(TokenType::Less, result, shift());
            continue;
        }
        if (match(TokenType::More))
        {
            result = new ConditionalExpression(TokenType::More, result, shift());
            continue;
        }
        if (match(TokenType::LessOrEqual))
        {
            result = new ConditionalExpression(TokenType::LessOrEqual, result, shift());
            continue;
        }
        if (match(TokenType::MoreOrEqual))
        {
            result = new ConditionalExpression(TokenType::MoreOrEqual, result, shift());
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
            result = new BinaryExpression(TokenType::Lshift, result, additive());
            continue;
        }
        if (match(TokenType::Rshift))
        {
            result = new BinaryExpression(TokenType::Rshift, result, additive());
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
            result = new BinaryExpression(TokenType::Plus, result, multiplicative());
            continue;
        }
        if (match(TokenType::Minus))
        {
            result = new BinaryExpression(TokenType::Minus, result, multiplicative());
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
            result = new BinaryExpression(TokenType::Star, result, prefixUnary());
            continue;
        }
        if (match(TokenType::Slash))
        {
            result = new BinaryExpression(TokenType::Slash, result, prefixUnary());
            continue;
        }
        if (match(TokenType::Percentage))
        {
            result = new BinaryExpression(TokenType::Percentage, result, prefixUnary());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::prefixUnary()
{
    if (match(TokenType::Minus))
        return new UnaryExpression(TokenType::Minus, prefixUnary());
    if (match(TokenType::Plus))
        return primary();
    if (match(TokenType::Tilde))
        return new UnaryExpression(TokenType::Tilde, prefixUnary());
    if (match(TokenType::Exclamation))
        return new UnaryExpression(TokenType::Exclamation, prefixUnary());
    if (match(TokenType::DoublePlus))
    {
        std::string variable = get().getText();
        consume(TokenType::Identifier);
        return new IncrementExpression(variable, TokenType::DoublePlus, true);
    }
    if (match(TokenType::DoubleMinus))
    {
        std::string variable = get().getText();
        consume(TokenType::Identifier);
        return new IncrementExpression(variable, TokenType::DoubleMinus, true);
    }
    return postfixUnary();
}

Expression *Parser::postfixUnary()
{
    if (get().getType() == Identifier && get(1).getType() == DoublePlus)
    {
        std::string variable = get().getText();
        consume(TokenType::Identifier);
        consume(TokenType::DoublePlus);
        return new IncrementExpression(variable, TokenType::DoublePlus, false);
    }
    if (get().getType() == Identifier && get(1).getType() == DoubleMinus)
    {
        std::string variable = get().getText();
        consume(TokenType::Identifier);
        consume(TokenType::DoubleMinus);
        return new IncrementExpression(variable, TokenType::DoubleMinus, false);
    }
    return primary();
}

Expression *Parser::primary()
{
    Token current = get();
    if (match(TokenType::IntNumber))
        return new ValueExpression(new IValue(current.getText(), true));
    if (match(TokenType::FloatNumber))
        return new ValueExpression(new F64Value(std::stod(current.getText()), true));
    if (match(TokenType::HexNumber))
        return new ValueExpression(new IValue(kondra::dynamic_int(current.getText(), 16), true));
    if (match(TokenType::OctNumber))
        return new ValueExpression(new IValue(kondra::dynamic_int(current.getText(), 8), true));
    if (match(TokenType::BoolValue))
        return new ValueExpression(current.getText() == "true" ? new BValue(true, true) : 
            new BValue(false, true));
    if (match(TokenType::StringValue))
        return new ValueExpression(new StrValue(current.getText(), true));
    if (match(TokenType::FstringValue))
        return new FormatStringExpression(current.getText());
    if (match(TokenType::Identifier))
    {
        if (match(TokenType::Lparen))
            return function(current.getText());
        return new VariablesExpression(current.getText());
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