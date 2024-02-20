#ifndef F64Value_HPP
#define F64Value_HPP

#include "Value.hpp"

class F64Value final : public Value
{
private:
    double data;
    bool isConst;
public:
    F64Value(const double &, const bool &);
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

F64Value::F64Value(const double &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void F64Value::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->f64Get();
}

Type F64Value::getType() const
{
    return Float64;
}


bool F64Value::getIsConst() const
{
    return isConst;
}

int8_t F64Value::i8Get() const
{
    return static_cast<int8_t>(data);
}

uint8_t F64Value::ui8Get() const
{
    return static_cast<uint8_t>(data);
}

int16_t F64Value::i16Get() const
{
    return static_cast<int16_t>(data);
}

uint16_t F64Value::ui16Get() const
{
    return static_cast<uint16_t>(data);
}

int32_t F64Value::i32Get() const
{
    return static_cast<int32_t>(data);
}

uint32_t F64Value::ui32Get() const
{
    return static_cast<uint32_t>(data);
}

int64_t F64Value::i64Get() const
{
    return static_cast<int64_t>(data);
}

uint64_t F64Value::ui64Get() const
{
    return static_cast<uint64_t>(data);
}

kondra::dynamic_int F64Value::iGet() const
{
    return kondra::dynamic_int(data);
}

float F64Value::f32Get() const
{
    return static_cast<float>(data);
}

double F64Value::f64Get() const
{
    return data;
}

bool F64Value::bGet() const
{
    return static_cast<bool>(data);
}

kondra::string F64Value::strGet() const
{
    throw std::runtime_error("Unable convert float64 to string");
}

kondra::var F64Value::varGet() const
{
    return kondra::var(data);
}

kondra::array<Value *> F64Value::arrGet() const
{
    throw std::runtime_error("Undefine conversation from float64 to array");
}

void F64Value::print(std::ostream &os) const
{
    os << data;
}

#endif