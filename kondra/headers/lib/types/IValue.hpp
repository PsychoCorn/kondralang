#ifndef IValue_HPP
#define IValue_HPP

#include "Value.hpp"

class IValue final : public Value
{
private:
    kondra::dynamic_int data;
    bool isConst;
public:
    IValue(const kondra::dynamic_int &, const bool &);
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
    Value **refGet() const override;
    bool bGet() const override;
    kondra::string strGet() const override;
    kondra::var varGet() const override;
    kondra::array<Value *> arrGet() const override;
    Value *getByIndex(int64_t) const override;
    void print(std::ostream &) const override;
};

IValue::IValue(const kondra::dynamic_int &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void IValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->iGet();
}

void IValue::setByIndex(Value *, const int64_t &)
{
    throw std::runtime_error("int isn't iterable type");
}

Type IValue::getType() const
{
    return Int;
}

bool IValue::getIsConst() const
{
    return isConst;
}

int8_t IValue::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t IValue::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t IValue::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t IValue::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t IValue::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t IValue::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t IValue::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t IValue::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int IValue::iGet() const
{
    return data;
}

float IValue::f32Get() const
{
    return static_cast<float>(data);
}

double IValue::f64Get() const
{
    return static_cast<double>(data);
}

Value **IValue::refGet() const
{
    throw std::runtime_error("Unable convert int32_t to reference");
}

bool IValue::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string IValue::strGet() const
{
    throw std::runtime_error("Unable convert int32_t to string");
}

kondra::var IValue::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> IValue::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int32_t to array");
}

Value *IValue::getByIndex(int64_t) const
{
    throw std::runtime_error("int32_t isn't iterable type");
}

void IValue::print(std::ostream &os) const
{
    os << data;
}

#endif