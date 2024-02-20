#ifndef UI8Value_HPP
#define UI8Value_HPP

#include "Value.hpp"

class UI8Value final : public Value
{
private:
    uint8_t data;
    bool isConst;
public:
    UI8Value(const uint8_t &, const bool &);
    void setValue(Value *) override;
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
    void print(std::ostream &) const override;
};

UI8Value::UI8Value(const uint8_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void UI8Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->ui8Get();
}

Type UI8Value::getType() const
{
    return UInt8;
}

bool UI8Value::getIsConst() const
{
    return isConst;
}

int8_t UI8Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t UI8Value::ui8Get() const
{
    return data;
}

int16_t UI8Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t UI8Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t UI8Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t UI8Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t UI8Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t UI8Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int UI8Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI8Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI8Value::f64Get() const
{
    return static_cast<double>(data);
}

bool UI8Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI8Value::strGet() const
{
    throw std::runtime_error("Unable convert uint8 to string");
}

kondra::var UI8Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI8Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint8 to array");
}

void UI8Value::print(std::ostream &os) const
{
    os << static_cast<uint32_t>(data);
}

#endif