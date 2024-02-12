#ifndef I32Value_HPP
#define I32Value_HPP

#include "Value.hpp"

class I32Value final : public Value
{
private:
    int data;
    Type type = Int32;
public:
    I32Value(int);
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

I32Value::I32Value(int data)
{
    this->data = data;
}

void I32Value::setValue(Value *value)
{
    this->data = value->i32Get();
}

Type I32Value::getType() const
{
    return type;
}

signed char I32Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char I32Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short I32Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short I32Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int I32Value::i32Get() const
{
    return data;
}

unsigned int I32Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long I32Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long I32Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int I32Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I32Value::f32Get() const
{
    return static_cast<float>(data);
}

double I32Value::f64Get() const
{
    return static_cast<double>(data);
}

long double I32Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool I32Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I32Value::strGet() const
{
    throw std::runtime_error("Unable convert int32 to string");
}

kondra::var I32Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I32Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int32 to array");
}

Value *I32Value::getByIndex(long long) const
{
    throw std::runtime_error("int32 isn't iterable type");
}

void I32Value::print(std::ostream &os) const
{
    os << data;
}

#endif