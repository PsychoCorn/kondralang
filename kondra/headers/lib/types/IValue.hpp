#ifndef IValue_HPP
#define IValue_HPP

#include "Value.hpp"

class IValue final : public Value
{
private:
    kondra::dynamic_int data;
    Type type = Int;
public:
    IValue(kondra::dynamic_int);
    void setValue(Value *) override;
    Type getType() const override;
    signed char i8Get() const override;
    unsigned char ui8Get() const override;
    short i16Get() const override;
    unsigned short ui16Get() const override;
    int i32Get() const override;
    unsigned int ui32Get() const override;
    long long i64Get() const override;
    unsigned long long ui64Get() const override;
    kondra::dynamic_int iGet() const override;
    float f32Get() const override;
    double f64Get() const override;
    long double f80Get() const override;
    bool bGet() const override;
    kondra::string strGet() const override;
    kondra::var varGet() const override;
    kondra::array<Value *> arrGet() const override;
    Value *getByIndex(long long) const override;
    void print(std::ostream &) const override;
};

IValue::IValue(kondra::dynamic_int data)
{
    this->data = data;
}

void IValue::setValue(Value *value)
{
    this->data = value->iGet();
}

Type IValue::getType() const
{
    return type;
}

signed char IValue::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char IValue::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short IValue::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short IValue::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int IValue::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int IValue::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long IValue::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long IValue::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int IValue::iGet() const
{
    return data;
}

float IValue::f32Get() const
{
    return static_cast<float>(data);
}

double IValue::f64Get() const
{
    return static_cast<double>(data);
}

long double IValue::f80Get() const
{
    return static_cast<long double>(data);
}

bool IValue::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string IValue::strGet() const
{
    return kondra::to_string(data);
}

kondra::var IValue::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> IValue::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int to array");
}

Value *IValue::getByIndex(long long) const
{
    throw std::runtime_error("int isn't iterable type");
}

void IValue::print(std::ostream &os) const
{
    os << data;
}

#endif