#ifndef BValue_HPP
#define BValue_HPP

#include "Value.hpp"

class BValue final : public Value
{
private:
    bool data;
    bool isConst;
public:
    BValue(const bool &, const bool &);
    void setValue(Value *) override;
    Type getType() const override;
    void setByIndex(Value *, const int64_t &) override;
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

BValue::BValue(const bool &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void BValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->bGet();
}

void BValue::setByIndex(Value *, const int64_t &)
{
    throw std::runtime_error("boolean isn't iterable type");
}

Type BValue::getType() const
{
    return Bool;
}

bool BValue::getIsConst() const
{
    return isConst;
}

int8_t BValue::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t BValue::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t BValue::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t BValue::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t BValue::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t BValue::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t BValue::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t BValue::ui64Get() const
{
    return static_cast<uint64_t>(data);
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

Value **BValue::refGet() const
{
    throw std::runtime_error("Unable convert boolean to reference");
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

Value *BValue::getByIndex(int64_t) const
{
    throw std::runtime_error("boolean isn't iterable type");
}

void BValue::print(std::ostream &os) const
{
    os << std::boolalpha << data;
}

#endif