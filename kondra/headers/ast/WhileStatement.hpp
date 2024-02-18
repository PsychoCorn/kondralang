#ifndef WhileStatement_HPP
#define WhileStatement_HPP

#include "Statement.hpp"
#include "BreakStatement.hpp"
#include "ContinueStatement.hpp"
#include "Expression.hpp"
#include "../types/String.hpp"

class WhileStatement : public Statement
{
private:
    Expression *condition;
    Statement *statement;
public:
    WhileStatement(Expression *, Statement *);
    ~WhileStatement();
    void execute() override;
};

WhileStatement::WhileStatement(Expression *condition, Statement *statement)
{
    this->condition = condition;
    this->statement = statement;
}

WhileStatement::~WhileStatement()
{
    delete condition, statement;
}

void WhileStatement::execute()
{
    Scopes::addScope();
    while (condition->eval()->bGet())
    {
        try
        {
            Scopes::addScope();
            statement->execute();
            Scopes::deleteScope();
        }
        catch(const BreakStatement& e)
        {
            Scopes::deleteScope();
            break;
        }
        catch (const ContinueStatement& e)
        {
            Scopes::deleteScope();
            continue;
        }
    }
    Scopes::deleteScope();
}

#endif