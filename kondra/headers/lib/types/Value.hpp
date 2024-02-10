#ifndef Value_HPP
#define Value_HPP

#include "../../io/kondraio.hpp"
#include <iostream>

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
    Float80,
    Bool,
    String,
    Var,
    Array,
    Struct,
    None //doesn't exist
};

class Value // interface
{
public:
    virtual void setValue(Value *) = 0;
    virtual Type getType() const = 0;
    virtual signed char i8Get() const = 0;
    virtual unsigned char ui8Get() const = 0;
    virtual short i16Get() const = 0;
    virtual unsigned short ui16Get() const = 0;
    virtual int i32Get() const = 0;
    virtual unsigned int ui32Get() const = 0;
    virtual long long i64Get() const = 0;
    virtual unsigned long long ui64Get() const = 0;
    virtual kondra::dynamic_int iGet() const = 0;
    virtual float f32Get() const = 0;
    virtual double f64Get() const = 0;
    virtual long double f80Get() const = 0;
    virtual bool bGet() const = 0;
    virtual kondra::string strGet() const = 0;
    virtual kondra::var varGet() const = 0;
    virtual kondra::array<Value *> arrGet() const = 0;
    virtual Value *getByIndex(long long) const = 0;
    virtual void print(std::ostream &) const = 0;
    friend std::ostream& operator<<(std::ostream &, const Value *);
};

std::ostream& operator<<(std::ostream &os, const Value *value)
{
    value->print(os);
    return os;
}

#endif