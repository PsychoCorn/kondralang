#ifndef UI32Value_HPP
#define UI32Value_HPP

#include "Value.hpp"

class UI32Value final : public Value
{
private:
    unsigned int data;
    Type type = UInt32;
public:
    UI32Value(unsigned int);
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

UI32Value::UI32Value(unsigned int data)
{
    this->data = data;
}

void UI32Value::setValue(Value *value)
{
    this->data = value->ui32Get();
}

Type UI32Value::getType() const
{
    return type;
}

signed char UI32Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char UI32Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short UI32Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short UI32Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int UI32Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int UI32Value::ui32Get() const
{
    return data;
}

long long UI32Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long UI32Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int UI32Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI32Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI32Value::f64Get() const
{
    return static_cast<double>(data);
}

long double UI32Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool UI32Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI32Value::strGet() const
{
    throw std::runtime_error("Unable convert uint32 to string");
}

kondra::var UI32Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI32Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint32 to array");
}

Value *UI32Value::getByIndex(long long) const
{
    throw std::runtime_error("uint32 isn't iterable type");
}

void UI32Value::print(std::ostream &os) const
{
    os << data;
}

#endif