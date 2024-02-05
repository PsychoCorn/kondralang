#ifndef WhileStatement_HPP
#define WhileStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../types/String.hpp"

template <class T>
class WhileStatement : public Statement
{
private:
    Expression<T> *condition;
    Statement *statement;
public:
    WhileStatement(Expression<T> *, Statement *);
    ~WhileStatement();
    void execute() override;
};

template <class T>
WhileStatement<T>::WhileStatement(Expression<T> *condition, Statement *statement)
{
    this->condition = condition;
    this->statement = statement;
}

template <class T>
WhileStatement<T>::~WhileStatement()
{
    delete condition, statement;
}

template <class T>
void WhileStatement<T>::execute()
{
    while (static_cast<bool>(condition->eval()))
    {
        statement->execute();
    }
}

template <>
void WhileStatement<kondra::string>::execute()
{
    while (condition->eval() == "1")
    {
        statement->execute();
    }
}


#endif