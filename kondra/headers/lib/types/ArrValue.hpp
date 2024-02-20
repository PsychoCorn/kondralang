#ifndef ArrValue_HPP
#define ArrValue_HPP

#include "CollectionValue.hpp"
#include "iterators/ArrayIterator.hpp"

class ArrValue final : public CollectionValue
{
private:
    kondra::array<Value *> data;
    bool isConst;
public:
    ArrValue(const kondra::array<Value *> &, const bool &);
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
    void setByIndex(Value *, const int64_t &) override;
    Value *getByIndex(int64_t) const override;
    size_t size() const override;
    IterValue *begin() override;
    IterValue *end() override;
    IterValue *rbegin() override;
    IterValue *rend() override;
};

ArrValue::ArrValue(const kondra::array<Value *> &data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void ArrValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    this->data = value->arrGet();
}

void ArrValue::setByIndex(Value *value, const int64_t &index)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    data[index]->setValue(value);
}

Type ArrValue::getType() const
{
    return Array;
}

bool ArrValue::getIsConst() const
{
    return isConst;
}

int8_t ArrValue::i8Get() const
{
    throw std::runtime_error("Unable convert array to int8");
}

uint8_t ArrValue::ui8Get() const
{
    throw std::runtime_error("Unable convert array to uint8");
}

int16_t ArrValue::i16Get() const
{
    throw std::runtime_error("Unable convert array to int16");
}

uint16_t ArrValue::ui16Get() const
{
    throw std::runtime_error("Unable convert array to uint16");
}

int32_t ArrValue::i32Get() const
{
    throw std::runtime_error("Unable convert array to int32");
}

uint32_t ArrValue::ui32Get() const
{
    throw std::runtime_error("Unable convert array to uint32");
}

int64_t ArrValue::i64Get() const
{
    throw std::runtime_error("Unable convert array to int64");
}

uint64_t ArrValue::ui64Get() const
{
    throw std::runtime_error("Unable convert array to uint64");
}

kondra::dynamic_int ArrValue::iGet() const
{
    throw std::runtime_error("Unable convert array to int32_t");
}

float ArrValue::f32Get() const
{
    throw std::runtime_error("Unable convert array to float32");
}

double ArrValue::f64Get() const
{
    throw std::runtime_error("Unable convert array to float64");
}

bool ArrValue::bGet() const
{
    throw std::runtime_error("Unable convert array to bool");
}

kondra::string ArrValue::strGet() const
{
    throw std::runtime_error("Unable convert array to string");
}

kondra::var ArrValue::varGet() const
{
    throw std::runtime_error("Unable convert array to var");
}

kondra::array<Value *> ArrValue::arrGet() const
{
    return data;
}

Value *ArrValue::getByIndex(int64_t index) const
{
    return data[index];
}

void ArrValue::print(std::ostream &os) const
{
    os << data;
}

size_t ArrValue::size() const
{
    return data.size();
}

IterValue *ArrValue::begin()
{
    return new IterValue(new ArrayIterator(data.begin()), isConst);
}

IterValue *ArrValue::end()
{
    return new IterValue(new ArrayIterator(data.end()), isConst);
}

IterValue *ArrValue::rbegin()
{
    return new IterValue(new ReverseArrayIterator(data.rbegin()), isConst);
}

IterValue *ArrValue::rend()
{
    return new IterValue(new ReverseArrayIterator(data.rend()), isConst);
}

#endif