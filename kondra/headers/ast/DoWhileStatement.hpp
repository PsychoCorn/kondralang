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
    do
    {
        try
        {
            statement->execute();
        }
        catch(const BreakStatement& e)
        {
            break;
        }
        catch (const ContinueStatement& e)
        {
            continue;
        }
    } while (condition->eval()->bGet());
}

#endif