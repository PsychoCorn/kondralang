#ifndef FreeStatement_HPP
#define FreeStatement_HPP

#include "Statement.hpp"
#include "../lib/Scopes.hpp"
#include <string>

class FreeStatement : public Statement
{
private:
    std::string variable;
public:
    FreeStatement(const std::string &);
    void execute() override;
};

FreeStatement::FreeStatement(const std::string &variable)
{
    this->variable = variable;
}

void FreeStatement::execute()
{
    auto value = dynamic_cast<PtrValue *>(Scopes::get(variable));
    if (value == nullptr)
        throw std::runtime_error("Can't use free statement with not ptr variable");
    value->free();
}

#endif