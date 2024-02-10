#ifndef I64Value_HPP
#define I64Value_HPP

#include "Value.hpp"

class I64Value final : public Value
{
private:
    long long data;
    Type type = Int64;
public:
    I64Value(long long);
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

I64Value::I64Value(long long data)
{
    this->data = data;
}

void I64Value::setValue(Value *value)
{
    this->data = value->i64Get();
}

Type I64Value::getType() const
{
    return type;
}

signed char I64Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char I64Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short I64Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short I64Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int I64Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int I64Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long I64Value::i64Get() const
{
    return data;
}

unsigned long long I64Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int I64Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I64Value::f32Get() const
{
    return static_cast<float>(data);
}

double I64Value::f64Get() const
{
    return static_cast<double>(data);
}

long double I64Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool I64Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I64Value::strGet() const
{
    return kondra::to_string(data);
}

kondra::var I64Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I64Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int64 to array");
}

Value *I64Value::getByIndex(long long) const
{
    throw std::runtime_error("int64 isn't iterable type");
}

void I64Value::print(std::ostream &os) const
{
    os << data;
}

#endif