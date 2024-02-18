#ifndef PtrValue_HPP
#define PtrValue_HPP

#include "Value.hpp"

#define ERR_MSG_NULL_PTR "Null pointer"

class PtrValue final : public Value
{
private:
    Value *data;
    bool isConst;
    bool isHaveData;
public:
    PtrValue(Value *, const bool &);
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
    void free();
    void del();
    bool isNullPtr();
};

PtrValue::PtrValue(Value *data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
    this->isHaveData = data == nullptr ? false : true;
}

void PtrValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    if (isHaveData)
        data->setValue(value);
    else
    {
        data = value;
        isHaveData = value == nullptr ? false : true;
    }
}

void PtrValue::setByIndex(Value *value, const int64_t &index)
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    data->setByIndex(value, index);
}

Type PtrValue::getType() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->getType();
}

bool PtrValue::getIsConst() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->getIsConst();
}

int8_t PtrValue::i8Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->i8Get();
}

uint8_t PtrValue::ui8Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->ui8Get();
}

int16_t PtrValue::i16Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->i16Get();
}

uint16_t PtrValue::ui16Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->ui16Get();
}

int32_t PtrValue::i32Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->i32Get();
}

uint32_t PtrValue::ui32Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->ui32Get();
}

int64_t PtrValue::i64Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->i64Get();
}

uint64_t PtrValue::ui64Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->ui64Get();
}

kondra::dynamic_int PtrValue::iGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->iGet();
}

float PtrValue::f32Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->f32Get();
}

double PtrValue::f64Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->f64Get();
}

bool PtrValue::bGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->bGet();
}

kondra::string PtrValue::strGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->strGet();
}

kondra::var PtrValue::varGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->varGet();
}

kondra::array<Value *> PtrValue::arrGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->arrGet();
}

Value *PtrValue::getByIndex(int64_t index) const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->getByIndex(index);
}

void PtrValue::print(std::ostream &os) const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    return data->print(os);
}

void PtrValue::del()
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_PTR);
    delete data;
    isHaveData = false;
}

void PtrValue::free()
{
    data = nullptr;
    isHaveData = false;
}

bool PtrValue::isNullPtr()
{
    return !isHaveData;
}

#endif