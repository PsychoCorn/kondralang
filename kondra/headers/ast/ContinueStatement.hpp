#ifndef ContinueStatement_HPP
#define ContinueStatement_HPP

#include <stdexcept>
#include "Statement.hpp"

class ContinueStatement : public std::runtime_error, public Statement
{
private:
public:
    ContinueStatement(const std::string & = "");
    void execute() override;
};

ContinueStatement::ContinueStatement(const std::string &message) : std::runtime_error(message) {}

void ContinueStatement::execute()
{
    throw *this;
}

#endif