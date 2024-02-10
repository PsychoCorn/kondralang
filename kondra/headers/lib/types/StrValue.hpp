#ifndef StrValue_HPP
#define StrValue_HPP

#include "Value.hpp"

class StrValue final : public Value
{
private:
    kondra::string data;
    Type type = String;
public:
    StrValue(kondra::string);
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

StrValue::StrValue(kondra::string data)
{
    this->data = data;
}

void StrValue::setValue(Value *value)
{
    this->data = value->strGet();
}

Type StrValue::getType() const
{
    return type;
}

signed char StrValue::i8Get() const
{
    throw std::runtime_error("Unable convert string to int8");
}

unsigned char StrValue::ui8Get() const
{
    throw std::runtime_error("Unable convert string to uint8");
}

short StrValue::i16Get() const
{
    throw std::runtime_error("Unable convert string to int16");
}

unsigned short StrValue::ui16Get() const
{
    throw std::runtime_error("Unable convert string to uint16");
}

int StrValue::i32Get() const
{
    throw std::runtime_error("Unable convert string to int32");
}

unsigned int StrValue::ui32Get() const
{
    throw std::runtime_error("Unable convert string to uint32");
}

long long StrValue::i64Get() const
{
    throw std::runtime_error("Unable convert string to int64");
}

unsigned long long StrValue::ui64Get() const
{
    throw std::runtime_error("Unable convert string to uint64");
}

kondra::dynamic_int StrValue::iGet() const
{
    return kondra::dynamic_int(data);
}

float StrValue::f32Get() const
{
    throw std::runtime_error("Unable convert string to float32");
}

double StrValue::f64Get() const
{
    throw std::runtime_error("Unable convert string to float64");
}

long double StrValue::f80Get() const
{
    throw std::runtime_error("Unable convert string to float80");
}

bool StrValue::bGet() const
{
    throw std::runtime_error("Unable convert string to boolean");
}

kondra::string StrValue::strGet() const
{
    return data;
}

kondra::var StrValue::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> StrValue::arrGet() const
{
    throw std::runtime_error("Undefine conversation from string to array");
}

Value *StrValue::getByIndex(long long index) const
{
    return new StrValue(kondra::string(1, data[index]));
}

void StrValue::print(std::ostream &os) const
{
    os << data;
}

#endif