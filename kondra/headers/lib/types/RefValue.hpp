#ifndef RefValue_HPP
#define RefValue_HPP

#include "CollectionValue.hpp"

#define ERR_MSG_NULL_REF "Null reference"

class RefValue final : public CollectionValue
{
private:
    Value *data;
    bool isConst;
    bool isHaveData;
public:
    RefValue(Value *, const bool &);
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
    size_t size() const override;
    IterValue *begin() override;
    IterValue *end() override;
    IterValue *rbegin() override;
    IterValue *rend() override;
    void free();
    void del();
    bool isNullRef();
};

RefValue::RefValue(Value *data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
    this->isHaveData = data == nullptr ? false : true;
}

void RefValue::setValue(Value *value)
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

void RefValue::setByIndex(Value *value, const int64_t &index)
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto collection = dynamic_cast<CollectionValue *>(data);
    if (collection != nullptr)
    {
        collection->setByIndex(value, index);
        data = collection;
    }
    else
        throw std::runtime_error("reference has not collection type");
}

Type RefValue::getType() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->getType();
}

bool RefValue::getIsConst() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->getIsConst();
}

int8_t RefValue::i8Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->i8Get();
}

uint8_t RefValue::ui8Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->ui8Get();
}

int16_t RefValue::i16Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->i16Get();
}

uint16_t RefValue::ui16Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->ui16Get();
}

int32_t RefValue::i32Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->i32Get();
}

uint32_t RefValue::ui32Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->ui32Get();
}

int64_t RefValue::i64Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->i64Get();
}

uint64_t RefValue::ui64Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->ui64Get();
}

kondra::dynamic_int RefValue::iGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->iGet();
}

float RefValue::f32Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->f32Get();
}

double RefValue::f64Get() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->f64Get();
}

bool RefValue::bGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->bGet();
}

kondra::string RefValue::strGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->strGet();
}

kondra::var RefValue::varGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->varGet();
}

kondra::array<Value *> RefValue::arrGet() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->arrGet();
}

Value *RefValue::getByIndex(int64_t index) const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto collection = dynamic_cast<CollectionValue *>(data);
    if (collection != nullptr)
        return collection->getByIndex(index);
    throw std::runtime_error("reference has not collection type");
}

void RefValue::print(std::ostream &os) const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    return data->print(os);
}

size_t RefValue::size() const
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto value = dynamic_cast<CollectionValue *>(data);
    if (value == nullptr)
        throw std::runtime_error("referece has not collection value");
    return value->size();
}

IterValue *RefValue::begin()
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto value = dynamic_cast<CollectionValue *>(data);
    if (value == nullptr)
        throw std::runtime_error("referece has not collection value");
    return value->begin();
}

IterValue *RefValue::end()
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto value = dynamic_cast<CollectionValue *>(data);
    if (value == nullptr)
        throw std::runtime_error("referece has not collection value");
    return value->end();
}

IterValue *RefValue::rbegin()
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto value = dynamic_cast<CollectionValue *>(data);
    if (value == nullptr)
        throw std::runtime_error("referece has not collection value");
    return value->rbegin();
}

IterValue *RefValue::rend()
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    auto value = dynamic_cast<CollectionValue *>(data);
    if (value == nullptr)
        throw std::runtime_error("referece has not collection value");
    return value->rend();
}

void RefValue::del()
{
    if (!isHaveData)
        throw std::runtime_error(ERR_MSG_NULL_REF);
    delete data;
    isHaveData = false;
}

void RefValue::free()
{
    data = nullptr;
    isHaveData = false;
}

bool RefValue::isNullRef()
{
    return !isHaveData;
}

#endif