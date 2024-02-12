#ifndef UI16Value_HPP
#define UI16Value_HPP

#include "Value.hpp"

class UI16Value final : public Value
{
private:
    unsigned short data;
    Type type = UInt16;
public:
    UI16Value(unsigned short);
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

UI16Value::UI16Value(unsigned short data)
{
    this->data = data;
}

void UI16Value::setValue(Value *value)
{
    this->data = value->ui16Get();
}

Type UI16Value::getType() const
{
    return type;
}

signed char UI16Value::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char UI16Value::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short UI16Value::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short UI16Value::ui16Get() const
{
    return data;
}

int UI16Value::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int UI16Value::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long UI16Value::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long UI16Value::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int UI16Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI16Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI16Value::f64Get() const
{
    return static_cast<double>(data);
}

long double UI16Value::f80Get() const
{
    return static_cast<long double>(data);
}

bool UI16Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI16Value::strGet() const
{
    throw std::runtime_error("Unable convert uint16 to string");
}

kondra::var UI16Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI16Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint16 to array");
}

Value *UI16Value::getByIndex(long long) const
{
    throw std::runtime_error("uint16 isn't iterable type");
}

void UI16Value::print(std::ostream &os) const
{
    os << data;
}

#endif