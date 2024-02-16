#ifndef RefValue_HPP
#define RefValue_HPP

#include "Value.hpp"

class RefValue final : public Value
{
private:
    Value **data;
    bool isConst;
public:
    RefValue(Value **, const bool &);
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
    Value **refGet() const override;
    Value *getByIndex(int64_t) const override;
    void print(std::ostream &) const override;
};

RefValue::RefValue(Value **data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void RefValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = &value;
}

void RefValue::setByIndex(Value *value, const int64_t &index)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    data[index]->setValue(value);
}

Type RefValue::getType() const
{
    return Ref;
}

bool RefValue::getIsConst() const
{
    return isConst;
}

int8_t RefValue::i8Get() const
{
    throw std::runtime_error("Unknown conversation from reference to int8");
}

uint8_t RefValue::ui8Get() const
{
    throw std::runtime_error("Unknown conversation from reference to uint8");
}

int16_t RefValue::i16Get() const
{
    throw std::runtime_error("Unknown conversation from reference to int16");
}

uint16_t RefValue::ui16Get() const
{
    throw std::runtime_error("Unknown conversation from reference to uint16");
}

int32_t RefValue::i32Get() const
{
    throw std::runtime_error("Unknown conversation from reference to int32");
}

uint32_t RefValue::ui32Get() const
{
    throw std::runtime_error("Unknown conversation from reference to uint32");
}

int64_t RefValue::i64Get() const
{
    throw std::runtime_error("Unknown conversation from reference to int64");
}

uint64_t RefValue::ui64Get() const
{
    throw std::runtime_error("Unknown conversation from reference to uint64");
}

kondra::dynamic_int RefValue::iGet() const
{
    throw std::runtime_error("Unknown conversation from reference to int32_t");
}

float RefValue::f32Get() const
{
    throw std::runtime_error("Unknown conversation from reference to float32");
}

double RefValue::f64Get() const
{
    throw std::runtime_error("Unknown conversation from reference to float64");
}

Value **RefValue::refGet() const
{
    return data;
}

bool RefValue::bGet() const
{
    throw std::runtime_error("Unknown conversation from reference to boolean");
}

kondra::string RefValue::strGet() const
{
    throw std::runtime_error("Unable convert reference to string");
}

kondra::var RefValue::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> RefValue::arrGet() const
{
    throw std::runtime_error("Undefine conversation from reference to array");
}

Value *RefValue::getByIndex(int64_t) const
{
    throw std::runtime_error("reference isn't iterable type");
}

void RefValue::print(std::ostream &os) const
{
    os << data;
}

#endif