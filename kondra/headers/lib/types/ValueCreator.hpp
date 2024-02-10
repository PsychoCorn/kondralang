#ifndef ValueCreator_HPP
#define ValueCreator_HPP

#include "types.hpp"

class ValueCreator
{
public:
    static Value* createValue(Value *);
};

Value *ValueCreator::createValue(Value *value)
{
    switch (value->getType())
    {
    case Int8:
        return new I8Value(value->i8Get());
    case UInt8:
        return new UI8Value(value->ui8Get());
    case Int16:
        return new I16Value(value->i16Get());
    case UInt16:
        return new UI16Value(value->ui16Get());
    case Int32:
        return new I32Value(value->i32Get());
    case UInt32:
        return new UI32Value(value->ui32Get());
    case Int64:
        return new I64Value(value->i64Get());
    case UInt64:
        return new UI64Value(value->ui64Get());
    case Int:
        return new IValue(value->iGet());
    case Float32:
        return new F32Value(value->f32Get());
    case Float64:
        return new F64Value(value->f64Get());
    case Float80:
        return new F80Value(value->f80Get());
    case Bool:
        return new BValue(value->bGet());
    case String:
        return new StrValue(value->strGet());
    case Var:
        return new VarValue(value->varGet());
    case Array:
        return new ArrValue(value->arrGet());
    default:
        throw std::runtime_error("Unknown type");
    }
}

#endif