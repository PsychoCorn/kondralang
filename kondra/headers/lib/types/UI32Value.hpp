#ifndef UI32Value_HPP
#define UI32Value_HPP

#include "Value.hpp"

class UI32Value final : public Value
{
private:
    uint32_t data;
    bool isConst;
public:
    UI32Value(const uint32_t &, const bool &);
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

UI32Value::UI32Value(const uint32_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void UI32Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->ui32Get();
}

void UI32Value::setByIndex(Value *, const int64_t &)
{
    throw std::runtime_error("uint32 isn't iterable type");
}

Type UI32Value::getType() const
{
    return UInt32;
}

bool UI32Value::getIsConst() const
{
    return isConst;
}

int8_t UI32Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t UI32Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t UI32Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t UI32Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t UI32Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t UI32Value::ui32Get() const
{
    return data;
}

int64_t UI32Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t UI32Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int UI32Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI32Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI32Value::f64Get() const
{
    return static_cast<double>(data);
}

bool UI32Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI32Value::strGet() const
{
    throw std::runtime_error("Unable convert uint32 to string");
}

kondra::var UI32Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI32Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint32 to array");
}

Value *UI32Value::getByIndex(int64_t) const
{
    throw std::runtime_error("uint32 isn't iterable type");
}

void UI32Value::print(std::ostream &os) const
{
    os << data;
}

#endif