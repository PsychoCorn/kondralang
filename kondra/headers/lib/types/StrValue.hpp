#ifndef StrValue_HPP
#define StrValue_HPP

#include "Value.hpp"

class StrValue final : public Value
{
private:
    kondra::string data;
    bool isConst;
public:
    StrValue(const kondra::string &, const bool &);
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

StrValue::StrValue(const kondra::string &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void StrValue::setValue(Value *value)
{
    this->data = value->strGet();
}

void StrValue::setByIndex(Value *value, const int64_t &index)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    data[index] = value->strGet()[0];
}

Type StrValue::getType() const
{
    return String;
}

bool StrValue::getIsConst() const
{
    return isConst;
}

int8_t StrValue::i8Get() const
{
    throw std::runtime_error("Unable convert string to int8");
}

uint8_t StrValue::ui8Get() const
{
    throw std::runtime_error("Unable convert string to uint8");
}

int16_t StrValue::i16Get() const
{
    throw std::runtime_error("Unable convert string to int16");
}

uint16_t StrValue::ui16Get() const
{
    throw std::runtime_error("Unable convert string to uint16");
}

int32_t StrValue::i32Get() const
{
    throw std::runtime_error("Unable convert string to int32");
}

uint32_t StrValue::ui32Get() const
{
    throw std::runtime_error("Unable convert string to uint32");
}

int64_t StrValue::i64Get() const
{
    throw std::runtime_error("Unable convert string to int64");
}

uint64_t StrValue::ui64Get() const
{
    throw std::runtime_error("Unable convert string to uint64");
}

kondra::dynamic_int StrValue::iGet() const
{
    throw std::runtime_error("Unable convert string to int32_t");
}

float StrValue::f32Get() const
{
    throw std::runtime_error("Unable convert string to float32");
}

double StrValue::f64Get() const
{
    throw std::runtime_error("Unable convert string to float64");
}

Value **StrValue::refGet() const
{
    throw std::runtime_error("Unable convert string to reference");
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

Value *StrValue::getByIndex(int64_t index) const
{
    return new StrValue(kondra::string(1, data[index]), isConst);
}

void StrValue::print(std::ostream &os) const
{
    os << data;
}

#endif