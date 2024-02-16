#ifndef BlockStatement_HPP
#define BlockStatement_HPP

#include "Statement.hpp"
#include <vector>

class BlockStatement final : public Statement
{
private:
    std::vector<Statement *> statements;
public:
    BlockStatement(/* args */);
    ~BlockStatement();
    void add(Statement *);
    void execute() override;
};

BlockStatement::BlockStatement(/* args */) : statements() {}

BlockStatement::~BlockStatement()
{
    for (auto statement: statements)
    {
        delete statement;
    }
    statements.clear();
}

void BlockStatement::add(Statement * statement)
{
    statements.push_back(statement);
}

void BlockStatement::execute()
{
    for (auto statement : statements)
    {
        statement->execute();
    }
}


#endif