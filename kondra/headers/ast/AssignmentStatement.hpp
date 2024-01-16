#ifndef AssignmentStatement_HPP
#define AssignmentStatement_HPP

#include "Statement.hpp"
#include "Expression.hpp"
#include "../lib/Variables.hpp"
#include <string>

class AssignmentStatement final : public Statement
{
private:
    std::string variable;
    Expression *expr;

public:
    AssignmentStatement(std::string, Expression *);
    ~AssignmentStatement();
    void execute();
};

#endif