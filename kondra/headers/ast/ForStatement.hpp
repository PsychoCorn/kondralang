#ifndef ForStatement_HPP
#define ForStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "BreakStatement.hpp"
#include "ContinueStatement.hpp"
#include "../types/String.hpp"

template <class T>
class ForStatement : public Statement
{
private:
    Statement *initialization;
    Expression<T> *termination;
    Statement *increment;
    Statement *block;
public:
    ForStatement(Statement *, Expression<T> *, Statement *, Statement *);
    ~ForStatement();
    void execute() override;
};

template <class T>
ForStatement<T>::ForStatement(Statement *initialization, Expression<T> *termination, 
    Statement *increment, Statement *block)
{
    this->initialization = initialization;
    this->termination = termination;
    this->increment = increment;
    this->block = block;
}

template <class T>
ForStatement<T>::~ForStatement()
{
    delete initialization, termination, increment, block;
}

template <class T>
void ForStatement<T>::execute()
{
    for (; termination->eval(); increment->execute())
    {
        try
        {
            block->execute();
        }
        catch (const BreakStatement& e)
        {
            break;
        }
        catch (const ContinueStatement& e)
        {
            continue;
        }
    }
}

template <>
void ForStatement<kondra::string>::execute()
{
    for (; termination->eval() == "1"; increment->execute())
    {
        try
        {
            block->execute();
        }
        catch(const BreakStatement& e)
        {
            break;
        }
        catch (const ContinueStatement& e)
        {
            continue;
        }
    }
}


#endif