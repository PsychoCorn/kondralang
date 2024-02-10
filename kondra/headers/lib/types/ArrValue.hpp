#ifndef ArrValue_HPP
#define ArrValue_HPP

#include "Value.hpp"

class ArrValue final : public Value
{
private:
    kondra::array<Value *> data;
    Type type = Array;
public:
    ArrValue(kondra::array<Value *>);
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

ArrValue::ArrValue(kondra::array<Value *> data)
{
    this->data = data;
}

void ArrValue::setValue(Value *value)
{
    this->data = value->arrGet();
}

Type ArrValue::getType() const
{
    return type;
}

signed char ArrValue::i8Get() const
{
    throw std::runtime_error("Unable convert array to int8");
}

unsigned char ArrValue::ui8Get() const
{
    throw std::runtime_error("Unable convert array to uint8");
}

short ArrValue::i16Get() const
{
    throw std::runtime_error("Unable convert array to int16");
}

unsigned short ArrValue::ui16Get() const
{
    throw std::runtime_error("Unable convert array to uint16");
}

int ArrValue::i32Get() const
{
    throw std::runtime_error("Unable convert array to int32");
}

unsigned int ArrValue::ui32Get() const
{
    throw std::runtime_error("Unable convert array to uint32");
}

long long ArrValue::i64Get() const
{
    throw std::runtime_error("Unable convert array to int64");
}

unsigned long long ArrValue::ui64Get() const
{
    throw std::runtime_error("Unable convert array to uint64");
}

kondra::dynamic_int ArrValue::iGet() const
{
    throw std::runtime_error("Unable convert array to int");
}

float ArrValue::f32Get() const
{
    throw std::runtime_error("Unable convert array to float32");
}

double ArrValue::f64Get() const
{
    throw std::runtime_error("Unable convert array to float64");
}

long double ArrValue::f80Get() const
{
    throw std::runtime_error("Unable convert array to float80");
}

bool ArrValue::bGet() const
{
    throw std::runtime_error("Unable convert array to bool");
}

kondra::string ArrValue::strGet() const
{
    throw std::runtime_error("Unable convert array to string");
}

kondra::var ArrValue::varGet() const
{
    throw std::runtime_error("Unable convert array to var");
}

kondra::array<Value *> ArrValue::arrGet() const
{
    return data;
}

Value *ArrValue::getByIndex(long long index) const
{
    return data[index];
}

void ArrValue::print(std::ostream &os) const
{
    os << data;
}

#endif