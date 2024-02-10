#ifndef F32Value_HPP
#define F32Value_HPP

#include "Value.hpp"

class F32Value final : public Value
{
private:
    float data;
    Type type = Float32;
public:
    F32Value(float);
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

F32Value::F32Value(float data)
{
    this->data = data;
}

void F32Value::setValue(Value *value)
{
    this->data = value->f32Get();
}

Type F32Value::getType() const
{
    return type;
}

signed char F32Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char F32Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short F32Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short F32Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int F32Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int F32Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long F32Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long F32Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int F32Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float F32Value::f32Get() const
{
    return data;
}

double F32Value::f64Get() const
{
    return static_cast<double>(data);
}

long double F32Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool F32Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string F32Value::strGet() const
{
    return kondra::to_string(data);
}

kondra::var F32Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> F32Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from float32 to array");
}

Value *F32Value::getByIndex(long long) const
{
    throw std::runtime_error("float32 isn't iterable type");
}

void F32Value::print(std::ostream &os) const
{
    os << data;
}

#endif