#ifndef DoWhileStatement_HPP
#define DoWhileStatement_HPP

#include "Statement.hpp"
#include "BreakStatement.hpp"
#include "ContinueStatement.hpp"
#include "Expression.hpp"
#include "../types/String.hpp"

class DoWhileStatement : public Statement
{
private:
    Expression *condition;
    Statement *statement;
public:
    DoWhileStatement(Expression *, Statement *);
    ~DoWhileStatement();
    void execute() override;
};

DoWhileStatement::DoWhileStatement(Expression *condition, Statement *statement)
{
    this->condition = condition;
    this->statement = statement;
}

DoWhileStatement::~DoWhileStatement()
{
    delete condition, statement;
}

void DoWhileStatement::execute()
{
    Scopes::addScope();
    do
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
    } while (condition->eval()->bGet());
    Scopes::deleteScope();
}

#endif