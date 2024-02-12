#ifndef I16Value_HPP
#define I16Value_HPP

#include "Value.hpp"

class I16Value final : public Value
{
private:
    short data;
    Type type = Int16;
public:
    I16Value(short);
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

I16Value::I16Value(short data)
{
    this->data = data;
}

void I16Value::setValue(Value *value)
{
    this->data = value->i16Get();
}

Type I16Value::getType() const
{
    return type;
}

signed char I16Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char I16Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short I16Value::i16Get() const
{
    return data;
}

unsigned short I16Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int I16Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int I16Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long I16Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long I16Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int I16Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I16Value::f32Get() const
{
    return static_cast<float>(data);
}

double I16Value::f64Get() const
{
    return static_cast<double>(data);
}

long double I16Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool I16Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I16Value::strGet() const
{
    throw std::runtime_error("Unable convert int16 to string");
}

kondra::var I16Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I16Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int16 to array");
}

Value *I16Value::getByIndex(long long) const
{
    throw std::runtime_error("int16 isn't iterable type");
}

void I16Value::print(std::ostream &os) const
{
    os << data;
}

#endif