#ifndef I8Value_HPP
#define I8Value_HPP

#include "Value.hpp"

class I8Value final : public Value
{
private:
    int8_t data;
    bool isConst;
public:
    I8Value(const int8_t &, const bool &);
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

I8Value::I8Value(const int8_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void I8Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->i8Get();
}

Type I8Value::getType() const
{
    return Int8;
}

bool I8Value::getIsConst() const
{
    return isConst;
}

int8_t I8Value::i8Get() const
{
    return data;
}

uint8_t I8Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t I8Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t I8Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t I8Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t I8Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t I8Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t I8Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int I8Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I8Value::f32Get() const
{
    return static_cast<float>(data);
}

double I8Value::f64Get() const
{
    return static_cast<double>(data);
}

bool I8Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I8Value::strGet() const
{
    throw std::runtime_error("Unable convert int8 to string");
}

kondra::var I8Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I8Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int8 to array");
}

void I8Value::print(std::ostream &os) const
{
    os << static_cast<int32_t>(data);
}

#endif