#ifndef FunctionDefineStatement_HPP
#define FunctionDefineStatement_HPP

#include "Statement.hpp"
#include "../lib/Functions.hpp"
#include <string>
#include <list>

class FunctionDefineStatement final : public Statement
{
private:
    std::string name;
    std::list<FunctionArg> args;
    Statement *body;

public:
    FunctionDefineStatement(const std::string &, const std::list<FunctionArg> &, 
        Statement *);
    void execute() override;
};

FunctionDefineStatement::FunctionDefineStatement(const std::string &name, 
    const std::list<FunctionArg> &args, Statement *body)
{
    this->name = name;
    this->args = args;
    this->body = body;
}

void FunctionDefineStatement::execute()
{
    Functions::set(name, args.size(), new UserDefinedFunction(args, body));
}

#endif