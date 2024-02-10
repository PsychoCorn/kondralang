#ifndef VarValue_HPP
#define VarValue_HPP

#include "Value.hpp"
#include "StrValue.hpp"

class VarValue final : public Value
{
private:
    kondra::var data;
    Type type = Var;
public:
    VarValue(kondra::var);
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

VarValue::VarValue(kondra::var data)
{
    this->data = data;
}

void VarValue::setValue(Value *value)
{
    this->data = value->varGet();
}

Type VarValue::getType() const
{
    return type;
}

signed char VarValue::i8Get() const
{
    return static_cast<signed char>(data);
}

unsigned char VarValue::ui8Get() const
{
    return static_cast<unsigned char>(data);
}

short VarValue::i16Get() const
{
    return static_cast<short>(data);
}

unsigned short VarValue::ui16Get() const
{
    return static_cast<unsigned short>(data);
}

int VarValue::i32Get() const
{
    return static_cast<int>(data);
}

unsigned int VarValue::ui32Get() const
{
    return static_cast<unsigned int>(data);
}

long long VarValue::i64Get() const
{
    return static_cast<long long>(data);
}

unsigned long long VarValue::ui64Get() const
{
    return static_cast<unsigned long long>(data);
}

kondra::dynamic_int VarValue::iGet() const
{
    return static_cast<kondra::dynamic_int>(data);
}

float VarValue::f32Get() const
{
    return static_cast<float>(data);
}

double VarValue::f64Get() const
{
    return static_cast<double>(data);
}

long double VarValue::f80Get() const
{
    return static_cast<long double>(data);
}

bool VarValue::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string VarValue::strGet() const
{
    return kondra::to_string(data);
}

kondra::var VarValue::varGet() const
{
    return data;
}

kondra::array<Value *> VarValue::arrGet() const
{
    throw std::runtime_error("Undefine conversation from var to array");
}

Value *VarValue::getByIndex(long long index) const
{
    switch (data.getType())
    {
    case kondra::VarType::String:
        return new StrValue(kondra::string(1, *(data.getData().stringData)[index]));
    
    default:
        throw std::runtime_error("var isn't iterable type");
    }
}

void VarValue::print(std::ostream &os) const
{
    os << data;
}

#endif