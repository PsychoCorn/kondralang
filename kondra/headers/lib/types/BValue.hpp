#ifndef BValue_HPP
#define BValue_HPP

#include "Value.hpp"

class BValue final : public Value
{
private:
    bool data;
    Type type = Bool;
public:
    BValue(bool);
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

BValue::BValue(bool data)
{
    this->data = data;
}

void BValue::setValue(Value *value)
{
    this->data = value->bGet();
}

Type BValue::getType() const
{
    return type;
}

signed char BValue::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char BValue::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short BValue::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short BValue::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int BValue::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int BValue::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long BValue::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long BValue::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int BValue::iGet() const
{
    return kondra::dynamic_int(data);
}

float BValue::f32Get() const
{
    return static_cast<float>(data);
}

double BValue::f64Get() const
{
    return static_cast<double>(data);
}

long double BValue::f80Get() const
{
    return static_cast<long double>(data);
}

bool BValue::bGet() const
{
    return data;
}

kondra::string BValue::strGet() const
{
    throw std::runtime_error("Unable convert boolean to string");
}

kondra::var BValue::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> BValue::arrGet() const
{
    throw std::runtime_error("Undefine conversation from boolean to array");
}

Value *BValue::getByIndex(long long) const
{
    throw std::runtime_error("boolean isn't iterable type");
}

void BValue::print(std::ostream &os) const
{
    os << std::boolalpha << data;
}

#endif