#ifndef UI8Value_HPP
#define UI8Value_HPP

#include "Value.hpp"

class UI8Value final : public Value
{
private:
    unsigned char data;
    Type type = UInt8;
public:
    UI8Value(unsigned char);
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

UI8Value::UI8Value(unsigned char data)
{
    this->data = data;
}

void UI8Value::setValue(Value *value)
{
    this->data = value->ui8Get();
}

Type UI8Value::getType() const
{
    return type;
}

signed char UI8Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char UI8Value::ui8Get() const
{
    return data;
}

short UI8Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short UI8Value::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int UI8Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int UI8Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long UI8Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long UI8Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int UI8Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI8Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI8Value::f64Get() const
{
    return static_cast<double>(data);
}

long double UI8Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool UI8Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI8Value::strGet() const
{
    return kondra::to_string(data);
}

kondra::var UI8Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI8Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint8 to array");
}

Value *UI8Value::getByIndex(long long) const
{
    throw std::runtime_error("uint8 isn't iterable type");
}

void UI8Value::print(std::ostream &os) const
{
    os << static_cast<unsigned int>(data);
}

#endif