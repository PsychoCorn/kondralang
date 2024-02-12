#ifndef ToBase_HPP
#define ToBase_HPP

class ToBase2 : public Function
{
public:
    ToBase2();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

ToBase2::ToBase2() {}

Value *ToBase2::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    return new StrValue(
        (*begin)->iGet().strGetNumber((*(begin + 1))->ui64Get())
    );
}

#endif