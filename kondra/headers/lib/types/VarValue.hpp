#ifndef VarValue_HPP
#define VarValue_HPP

#include "Value.hpp"
#include "StrValue.hpp"

class VarValue final : public Value
{
private:
    kondra::var data;
    bool isConst;
public:
    VarValue(const kondra::var &, const bool &);
    void setValue(Value *) override;
    void setByIndex(Value *, const int64_t &) override;
    Type getType() const override;
    bool getIsConst() const override;
    int8_t i8Get() const override;
    uint8_t ui8Get() const override;
    int16_t i16Get() const override;
    uint16_t ui16Get() const override;
    int32_t i32Get() const override;
    uint32_t ui32Get() const override;
    int64_t i64Get() const override;
    uint64_t ui64Get() const override;
    kondra::dynamic_int iGet() const override;
    float f32Get() const override;
    double f64Get() const override;
    bool bGet() const override;
    kondra::string strGet() const override;
    kondra::var varGet() const override;
    kondra::array<Value *> arrGet() const override;
    Value *getByIndex(int64_t) const override;
    void print(std::ostream &) const override;
};

VarValue::VarValue(const kondra::var &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void VarValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->varGet();
}

void VarValue::setByIndex(Value *value, const int64_t &index)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    switch (data.getType())
    {
    case kondra::VarType::String:
        (*data.getData().stringData)[index] = value->strGet()[0];
        return;
    
    default:
        throw std::runtime_error("var isn't iterable type");
    }
}

Type VarValue::getType() const
{
    return Var;
}

bool VarValue::getIsConst() const
{
    return isConst;
}

int8_t VarValue::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t VarValue::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t VarValue::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t VarValue::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t VarValue::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t VarValue::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t VarValue::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t VarValue::ui64Get() const
{
    return static_cast<uint64_t>(data);
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

Value *VarValue::getByIndex(int64_t index) const
{
    switch (data.getType())
    {
    case kondra::VarType::String:
        return new StrValue(kondra::string(1, (*data.getData().stringData)[index]), isConst);
    
    default:
        throw std::runtime_error("var isn't iterable type");
    }
}

void VarValue::print(std::ostream &os) const
{
    os << data;
}

#endif