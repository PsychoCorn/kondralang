#ifndef I8Value_HPP
#define I8Value_HPP

#include "Value.hpp"

class I8Value final : public Value
{
private:
    signed char data;
    Type type = Int8;
public:
    I8Value(signed char);
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

I8Value::I8Value(signed char data)
{
    this->data = data;
}

void I8Value::setValue(Value *value)
{
    this->data = value->i8Get();
}

Type I8Value::getType() const
{
    return type;
}

signed char I8Value::i8Get() const
{
    return data;
}

unsigned char I8Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short I8Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short I8Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int I8Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int I8Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long I8Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long I8Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int I8Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I8Value::f32Get() const
{
    return static_cast<float>(data);
}

double I8Value::f64Get() const
{
    return static_cast<double>(data);
}

long double I8Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool I8Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I8Value::strGet() const
{
    return kondra::to_string(data);
}

kondra::var I8Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I8Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int8 to array");
}

Value *I8Value::getByIndex(long long) const
{
    throw std::runtime_error("int8 isn't iterable type");
}

void I8Value::print(std::ostream &os) const
{
    os << static_cast<int>(data);
}

#endif