#ifndef UI64Value_HPP
#define UI64Value_HPP

#include "Value.hpp"

class UI64Value final : public Value
{
private:
    unsigned long long data;
    Type type = UInt64;
public:
    UI64Value(unsigned long long);
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

UI64Value::UI64Value(unsigned long long data)
{
    this->data = data;
}

void UI64Value::setValue(Value *value)
{
    this->data = value->ui64Get();
}

Type UI64Value::getType() const
{
    return type;
}

signed char UI64Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char UI64Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short UI64Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short UI64Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int UI64Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int UI64Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long UI64Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long UI64Value::ui64Get() const
{
    return data;
}

kondra::dynamic_int UI64Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI64Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI64Value::f64Get() const
{
    return static_cast<double>(data);
}

long double UI64Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool UI64Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI64Value::strGet() const
{
    throw std::runtime_error("Unable convert uint64 to string");
}

kondra::var UI64Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI64Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint64 to array");
}

Value *UI64Value::getByIndex(long long) const
{
    throw std::runtime_error("uint64 isn't iterable type");
}

void UI64Value::print(std::ostream &os) const
{
    os << data;
}

#endif