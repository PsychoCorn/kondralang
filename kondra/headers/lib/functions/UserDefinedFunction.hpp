#ifndef UserDefinedFunction_HPP
#define UserDefinedFunction_HPP

#include "Function.hpp"
#include <unordered_map>
#include "../../ast/Statement.hpp"
#include "../../ast/ReturnStatement.hpp"

struct FunctionArg
{
    std::string type;
    std::string name;
    bool isConst;

    FunctionArg(const std::string &, const std::string &, const bool &);
};

FunctionArg::FunctionArg(const std::string &type, const std::string &name, const bool &isConst)
{
    this->type = type;
    this->name = name;
    this->isConst = isConst;
}



#define functionArgsHashMap std::unordered_map<std::string, std::string>

class UserDefinedFunction : public Function
{
private:
    std::list<FunctionArg> args;
    Statement *body;
public:
    UserDefinedFunction(const std::list<FunctionArg> &, Statement *);
    size_t getNumberOfArgs();
    std::pair<std::string, std::string> getArg();
    ~UserDefinedFunction();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

UserDefinedFunction::UserDefinedFunction(const std::list<FunctionArg> &args, 
    Statement *body)
{
    this->args = args;
    this->body = body;
}

UserDefinedFunction::~UserDefinedFunction()
{
    delete body;
}

size_t UserDefinedFunction::getNumberOfArgs()
{
    return args.size();
}

Value *UserDefinedFunction::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end) 
{
    Scopes::addScope();
    for (auto arg : args)
    {
        Scopes::create(arg.type, arg.name, false, arg.isConst, (*begin));
        begin++;
    }
    if (begin != end)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    try
    {
        body->execute();
    }
    catch(const ReturnStatement &returnValue)
    {
        auto value = returnValue.getValue();
        Scopes::deleteScope();
        return value;
    }
    Scopes::deleteScope();
    return new VarValue(kondra::var(), true);
}

#endif