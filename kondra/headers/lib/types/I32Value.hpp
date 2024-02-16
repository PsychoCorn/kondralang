#ifndef I32Value_HPP
#define I32Value_HPP

#include "Value.hpp"

class I32Value final : public Value
{
private:
    int32_t data;
    bool isConst;
public:
    I32Value(const int32_t &, const bool &);
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

I32Value::I32Value(const int32_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void I32Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->i32Get();
}

void I32Value::setByIndex(Value *, const int64_t &)
{
    throw std::runtime_error("int32 isn't iterable type");
}

Type I32Value::getType() const
{
    return Int32;
}

bool I32Value::getIsConst() const
{
    return isConst;
}

int8_t I32Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t I32Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t I32Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t I32Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t I32Value::i32Get() const
{
    return data;
}

uint32_t I32Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t I32Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t I32Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int I32Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I32Value::f32Get() const
{
    return static_cast<float>(data);
}

double I32Value::f64Get() const
{
    return static_cast<double>(data);
}

Value **I32Value::refGet() const
{
    throw std::runtime_error("Unable convert int32 to reference");
}

bool I32Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I32Value::strGet() const
{
    throw std::runtime_error("Unable convert int32 to string");
}

kondra::var I32Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I32Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int32 to array");
}

Value *I32Value::getByIndex(int64_t) const
{
    throw std::runtime_error("int32 isn't iterable type");
}

void I32Value::print(std::ostream &os) const
{
    os << data;
}

#endif