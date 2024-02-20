#ifndef UI16Value_HPP
#define UI16Value_HPP

#include "Value.hpp"

class UI16Value final : public Value
{
private:
    uint16_t data;
    bool isConst;
public:
    UI16Value(const uint16_t &, const bool &);
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

UI16Value::UI16Value(const uint16_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void UI16Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->ui16Get();
}

Type UI16Value::getType() const
{
    return UInt16;
}

bool UI16Value::getIsConst() const
{
    return isConst;
}

int8_t UI16Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t UI16Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t UI16Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t UI16Value::ui16Get() const
{
    return data;
}

int32_t UI16Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t UI16Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t UI16Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t UI16Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int UI16Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float UI16Value::f32Get() const
{
    return static_cast<float>(data);
}

double UI16Value::f64Get() const
{
    return static_cast<double>(data);
}

bool UI16Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string UI16Value::strGet() const
{
    throw std::runtime_error("Unable convert uint16 to string");
}

kondra::var UI16Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> UI16Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from uint16 to array");
}

void UI16Value::print(std::ostream &os) const
{
    os << data;
}

#endif