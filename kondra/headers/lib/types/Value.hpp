#ifndef Value_HPP
#define Value_HPP

#include "../../io/kondraio.hpp"
#include <iostream>

#define ERR_MSG_CANT_CHNG_CONST "Can't change constant value"

enum Type
{
    Int8,
    Int16,
    Int32,
    Int64,
    UInt8,
    UInt16,
    UInt32,
    UInt64,
    Int,
    Float32,
    Float64,
    Bool,
    String,
    Var,
    Array,
    Iter,
    Pair,
    HashMap,
    HashMultiMap,
    Struct,
    None //doesn't exist
};

class Value // interface
{
public:
    virtual void setValue(Value *) = 0;
    virtual Type getType() const = 0;
    virtual bool getIsConst() const = 0;
    virtual int8_t i8Get() const = 0;
    virtual uint8_t ui8Get() const = 0;
    virtual int16_t i16Get() const = 0;
    virtual uint16_t ui16Get() const = 0;
    virtual int32_t i32Get() const = 0;
    virtual uint32_t ui32Get() const = 0;
    virtual int64_t i64Get() const = 0;
    virtual uint64_t ui64Get() const = 0;
    virtual kondra::dynamic_int iGet() const = 0;
    virtual float f32Get() const = 0;
    virtual double f64Get() const = 0;
    virtual bool bGet() const = 0;
    virtual kondra::string strGet() const = 0;
    virtual kondra::var varGet() const = 0;
    virtual kondra::array<Value *> arrGet() const = 0;
    virtual void print(std::ostream &) const = 0;
    friend std::ostream& operator<<(std::ostream &, const Value *);
};

std::ostream& operator<<(std::ostream &os, const Value *value)
{
    value->print(os);
    return os;
}

#endif