#ifndef ForStatement_HPP
#define ForStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "BreakStatement.hpp"
#include "ContinueStatement.hpp"
#include "../types/String.hpp"

class ForStatement : public Statement
{
private:
    Statement *initialization;
    Expression *termination;
    Statement *increment;
    Statement *block;
public:
    ForStatement(Statement *, Expression *, Statement *, Statement *);
    ~ForStatement();
    void execute() override;
};

ForStatement::ForStatement(Statement *initialization, Expression *termination, 
    Statement *increment, Statement *block)
{
    this->initialization = initialization;
    this->termination = termination;
    this->increment = increment;
    this->block = block;
}

ForStatement::~ForStatement()
{
    delete initialization, termination, increment, block;
}

void ForStatement::execute()
{
    Scopes::addScope();
    for (initialization->execute(); termination->eval()->bGet(); increment->execute())
    {
        try
        {
            Scopes::addScope();
            block->execute();
            Scopes::deleteScope();
        }
        catch (const BreakStatement& e)
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