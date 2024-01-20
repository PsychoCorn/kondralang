#ifndef Expression_HPP
#define Expression_HPP

template <class T>
class Expression //interface
{
public:
    virtual T eval() = 0;
};

#endif