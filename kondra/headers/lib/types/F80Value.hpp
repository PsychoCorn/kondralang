#ifndef F80Value_HPP
#define F80Value_HPP

#include "Value.hpp"

class F80Value final : public Value
{
private:
    long double data;
    Type type = Float80;
public:
    F80Value(long double);
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

F80Value::F80Value(long double data)
{
    this->data = data;
}

void F80Value::setValue(Value *value)
{
    this->data = value->f80Get();
}

Type F80Value::getType() const
{
    return type;
}

signed char F80Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char F80Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short F80Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short F80Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int F80Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int F80Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long F80Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long F80Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int F80Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float F80Value::f32Get() const
{
    return static_cast<float>(data);
}

double F80Value::f64Get() const
{
    return static_cast<double>(data);
}

long double F80Value::f80Get() const
{
    return data;
}

bool F80Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string F80Value::strGet() const
{
    throw std::runtime_error("Unable convert float80 to string");
}

kondra::var F80Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> F80Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from float80 to array");
}

Value *F80Value::getByIndex(long long) const
{
    throw std::runtime_error("float80 isn't iterable type");
}

void F80Value::print(std::ostream &os) const
{
    os << data;
}

#endif