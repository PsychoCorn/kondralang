#ifndef ValueCreator_HPP
#define ValueCreator_HPP

#include "types.hpp"

class ValueCreator
{
public:
    static Value* createValue(Value *, const bool &);
};

Value *ValueCreator::createValue(Value *value, const bool &isConst)
{
    switch (value->getType())
    {
    case Int8:
        return new I8Value(value->i8Get(), isConst);
    case UInt8:
        return new UI8Value(value->ui8Get(), isConst);
    case Int16:
        return new I16Value(value->i16Get(), isConst);
    case UInt16:
        return new UI16Value(value->ui16Get(), isConst);
    case Int32:
        return new I32Value(value->i32Get(), isConst);
    case UInt32:
        return new UI32Value(value->ui32Get(), isConst);
    case Int64:
        return new I64Value(value->i64Get(), isConst);
    case UInt64:
        return new UI64Value(value->ui64Get(), isConst);
    case Int:
        return new IValue(value->iGet(), isConst);
    case Float32:
        return new F32Value(value->f32Get(), isConst);
    case Float64:
        return new F64Value(value->f64Get(), isConst);
    case Bool:
        return new BValue(value->bGet(), isConst);
    case String:
        return new StrValue(value->strGet(), isConst);
    case Var:
        return new VarValue(value->varGet(), isConst);
    case Array:
        return new ArrValue(value->arrGet(), isConst);
    default:
        throw std::runtime_error("Unknown type");
    }
}

#endif