#ifndef BreakStatement_HPP
#define BreakStatement_HPP

#include <stdexcept>
#include "Statement.hpp"

class BreakStatement : public std::runtime_error, public Statement
{
public:
    BreakStatement(const std::string & = "");
    void execute() override;
};

BreakStatement::BreakStatement(const std::string &message) : std::runtime_error(message) {}

void BreakStatement::execute()
{
    throw *this;
}

#endif