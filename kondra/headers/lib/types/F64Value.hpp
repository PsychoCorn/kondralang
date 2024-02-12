#ifndef F64Value_HPP
#define F64Value_HPP

#include "Value.hpp"

class F64Value final : public Value
{
private:
    double data;
    Type type = Float64;
public:
    F64Value(double);
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

F64Value::F64Value(double data)
{
    this->data = data;
}

void F64Value::setValue(Value *value)
{
    this->data = value->f64Get();
}

Type F64Value::getType() const
{
    return type;
}

signed char F64Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char F64Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short F64Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short F64Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int F64Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int F64Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long F64Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long F64Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int F64Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float F64Value::f32Get() const
{
    return static_cast<float>(data);
}

double F64Value::f64Get() const
{
    return data;
}

long double F64Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool F64Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string F64Value::strGet() const
{
    throw std::runtime_error("Unable convert float64 to string");
}

kondra::var F64Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> F64Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from float64 to array");
}

Value *F64Value::getByIndex(long long) const
{
    throw std::runtime_error("float64 isn't iterable type");
}

void F64Value::print(std::ostream &os) const
{
    os << data;
}

#endif