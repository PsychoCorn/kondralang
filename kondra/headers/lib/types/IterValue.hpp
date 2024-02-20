#ifndef IterValue_HPP
#define IterValue_HPP

#include "Value.hpp"
#include "iterators/iterators.hpp"

class IterValue final : public Value
{
private:
    Iterator *data;
    bool isConst;
public:
    IterValue(Iterator *, const bool &);
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
    Iterator *&getIter();
};

IterValue::IterValue(Iterator *data, const bool &isConst)
{
    this->data = data;
    this->isConst = isConst;
}

void IterValue::setValue(Value *value)
{
    if (isConst)
        throw std::runtime_error(ERR_MSG_CANT_CHNG_CONST);
    auto iter = dynamic_cast<IterValue *>(value);
    if (iter == nullptr)
        throw std::runtime_error("Can't assign to iterator not iterator value");
    data = iter->getIter();
}

Type IterValue::getType() const
{
    return Iter;
}

bool IterValue::getIsConst() const
{
    return isConst;
}

int8_t IterValue::i8Get() const
{
    throw std::runtime_error("Unable convert iterator to int8");
}

uint8_t IterValue::ui8Get() const
{
    throw std::runtime_error("Unable convert iterator to uint8");
}

int16_t IterValue::i16Get() const
{
    throw std::runtime_error("Unable convert iterator to int16");
}

uint16_t IterValue::ui16Get() const
{
    throw std::runtime_error("Unable convert iterator to uint16");
}

int32_t IterValue::i32Get() const
{
    throw std::runtime_error("Unable convert iterator to int32");
}

uint32_t IterValue::ui32Get() const
{
    throw std::runtime_error("Unable convert iterator to uint32");
}

int64_t IterValue::i64Get() const
{
    throw std::runtime_error("Unable convert iterator to int64");
}

uint64_t IterValue::ui64Get() const
{
    throw std::runtime_error("Unable convert iterator to uint64");
}

kondra::dynamic_int IterValue::iGet() const
{
    throw std::runtime_error("Unable convert iterator to int");
}

float IterValue::f32Get() const
{
    throw std::runtime_error("Unable convert iterator to float32");
}

double IterValue::f64Get() const
{
    throw std::runtime_error("Unable convert iterator to float64");
}

bool IterValue::bGet() const
{
    throw std::runtime_error("Unable convert iterator to boolean");
}

kondra::string IterValue::strGet() const
{
    throw std::runtime_error("Unable convert iterator to boolean");
}

kondra::var IterValue::varGet() const
{
    throw std::runtime_error("Unable convert iterator to var");
}

kondra::array<Value *> IterValue::arrGet() const
{
    throw std::runtime_error("Unable convert iterator to array");
}

void IterValue::print(std::ostream &os) const
{
    os << data;
}

Iterator *&IterValue::getIter()
{
    return data;
}

#endif