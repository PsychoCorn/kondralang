#ifndef I16Value_HPP
#define I16Value_HPP

#include "Value.hpp"

class I16Value final : public Value
{
private:
    int16_t data;
    bool isConst;
public:
    I16Value(const int16_t &, const bool &);
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

I16Value::I16Value(const int16_t &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void I16Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->i16Get();
}

void I16Value::setByIndex(Value *, const int64_t &)
{
    throw std::runtime_error("int16 isn't iterable type");
}

Type I16Value::getType() const
{
    return Int16;
}

bool I16Value::getIsConst() const
{
    return isConst;
}

int8_t I16Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t I16Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t I16Value::i16Get() const
{
    return data;
}

uint16_t I16Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t I16Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t I16Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t I16Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t I16Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int I16Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float I16Value::f32Get() const
{
    return static_cast<float>(data);
}

double I16Value::f64Get() const
{
    return static_cast<double>(data);
}

Value **I16Value::refGet() const
{
    throw std::runtime_error("Unable convert int16 to reference");
}

bool I16Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string I16Value::strGet() const
{
    throw std::runtime_error("Unable convert int16 to string");
}

kondra::var I16Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> I16Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from int16 to array");
}

Value *I16Value::getByIndex(int64_t) const
{
    throw std::runtime_error("int16 isn't iterable type");
}

void I16Value::print(std::ostream &os) const
{
    os << data;
}

#endif