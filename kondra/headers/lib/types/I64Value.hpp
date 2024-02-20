#ifndef I64Value_HPP
#define I64Value_HPP

#include "Value.hpp"

class I64Value final : public Value
{
private:
    int64_t data;
    bool isConst;
public:
    I64Value(const int64_t &, const bool &);
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

I64Value::I64Value(const int64_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void I64Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->i64Get();
}

Type I64Value::getType() const
{
    return Int64;
}

bool I64Value::getIsConst() const
{
    return isConst;
}

int8_t I64Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t I64Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t I64Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t I64Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t I64Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t I64Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t I64Value::i64Get() const
{
    return data;
}

uint64_t I64Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int I64Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I64Value::f32Get() const
{
    return static_cast<float>(data);
}

double I64Value::f64Get() const
{
    return static_cast<double>(data);
}

bool I64Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I64Value::strGet() const
{
    throw std::runtime_error("Unable convert int64 to string");
}

kondra::var I64Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I64Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int64 to array");
}

void I64Value::print(std::ostream &os) const
{
    os << data;
}

#endif