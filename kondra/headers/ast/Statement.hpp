#ifndef Statement_HPP
#define Statement_HPP

class Statement // interface
{
public:
    virtual ~Statement() {}
    virtual void execute() = 0;
};

#endif