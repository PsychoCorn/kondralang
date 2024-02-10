#ifndef BinaryExpression_HPP
#define BinaryExpression_HPP

#include "Expression.hpp"
#include <string>
#include <stdexcept>

#define ERR_MSG_WRNG_BIN_OP "Wrong binary operator"
#define ERR_MSG_WRNG_OPNDS "Wrong operands"

class BinaryExpression : public Expression
{
private:
    Expression* expr1;
    Expression* expr2;
    std::string operation;
    
    Value *add();
    Value *sub();
    Value *mul();
    Value *div();
    Value *mod();
    Value *bitwiseAnd();
    Value *bitwiseXor();
    Value *bitwiseOr();
    Value *shl();
    Value *shr();

public:
    BinaryExpression(std::string, Expression*, Expression*);
    ~BinaryExpression();
    Value *eval() override;
};

BinaryExpression::BinaryExpression(std::string operation, Expression* expr1, Expression* expr2)
{
    this->operation = operation;
    this->expr1 = expr1;
    this->expr2 = expr2;
}

BinaryExpression::~BinaryExpression()
{
    delete expr1, expr2;
}

Value *BinaryExpression::eval()
{
    if (operation == "+")
        return add();
    else if (operation == "-")
        return sub();
    else if (operation == "*")
        return mul();
    else if (operation == "/")
        return div();
    else if (operation == "%")
        return mod();
    else if (operation == "&")
        return bitwiseAnd();
    else if (operation == "|")
        return bitwiseOr();
    else if (operation == "^")
        return bitwiseXor();
    else if (operation == ">>")
        return shl();
    else if (operation == "<<")
        return shr();
    throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
}

Value *BinaryExpression::add()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() + operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() + operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() + operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() + operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() + operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->i8Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->i8Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->i8Get() + operand2->f80Get());
        case Bool: return new I8Value(operand1->i8Get() + operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() + operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() + operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() + operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() + operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() + operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->i16Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->i16Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->i16Get() + operand2->f80Get());
        case Bool: return new I16Value(operand1->i16Get() + operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() + operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() + operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() + operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() + operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() + operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->i32Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->i32Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->i32Get() + operand2->f80Get());
        case Bool: return new I32Value(operand1->i32Get() + operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() + operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() + operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() + operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() + operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() + operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() + operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->i64Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->i64Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->i64Get() + operand2->f80Get());
        case Bool: return new I64Value(operand1->i64Get() + operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() + operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() + operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() + operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() + operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() + operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->ui8Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->ui8Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->ui8Get() + operand2->f80Get());
        case Bool: return new UI8Value(operand1->ui8Get() + operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() + operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() + operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() + operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() + operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() + operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->ui16Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->ui16Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->ui16Get() + operand2->f80Get());
        case Bool: return new UI16Value(operand1->ui16Get() + operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() + operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() + operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() + operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() + operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() + operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->ui32Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->ui32Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->ui32Get() + operand2->f80Get());
        case Bool: return new UI32Value(operand1->ui32Get() + operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() + operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() + operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() + operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() + operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() + operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() + operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() + operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() + operand2->iGet());
        case Float32: return new F32Value(operand1->ui64Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->ui64Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->ui64Get() + operand2->f80Get());
        case Bool: return new UI64Value(operand1->ui64Get() + operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() + operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() + operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() + operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() + operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() + operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() + operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() + operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() + operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() + operand2->iGet());
        case Float32: return new F32Value(static_cast<float>(operand1->iGet() + operand2->f32Get()));
        case Float64: return new F64Value(static_cast<double>(operand1->iGet() + operand2->f64Get()));
        case Float80: return new F80Value(static_cast<long double>(operand1->iGet() + operand2->f80Get()));
        case Bool: return new IValue(operand1->iGet() + operand2->bGet());
        case Var: return new VarValue(operand1->iGet() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() + operand2->i8Get());
        case Int16: return new F32Value(operand1->f32Get() + operand2->i16Get());
        case Int32: return new F32Value(operand1->f32Get() + operand2->i32Get());
        case Int64: return new F32Value(operand1->f32Get() + operand2->i64Get());
        case UInt8: return new F32Value(operand1->f32Get() + operand2->ui8Get());
        case UInt16: return new F32Value(operand1->f32Get() + operand2->ui16Get());
        case UInt32: return new F32Value(operand1->f32Get() + operand2->ui32Get());
        case UInt64: return new F32Value(operand1->f32Get() + operand2->ui64Get());
        case Int: return new F32Value(operand1->f32Get() + operand2->f32Get());
        case Float32: return new F32Value(operand1->f32Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->f32Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->f32Get() + operand2->f80Get());
        case Bool: return new F32Value(operand1->f32Get() + operand2->bGet());
        case Var: return new VarValue(operand1->f32Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() + operand2->i8Get());
        case Int16: return new F64Value(operand1->f64Get() + operand2->i16Get());
        case Int32: return new F64Value(operand1->f64Get() + operand2->i32Get());
        case Int64: return new F64Value(operand1->f64Get() + operand2->i64Get());
        case UInt8: return new F64Value(operand1->f64Get() + operand2->ui8Get());
        case UInt16: return new F64Value(operand1->f64Get() + operand2->ui16Get());
        case UInt32: return new F64Value(operand1->f64Get() + operand2->ui32Get());
        case UInt64: return new F64Value(operand1->f64Get() + operand2->ui64Get());
        case Int: return new F64Value(operand1->f64Get() + operand2->f64Get());
        case Float32: return new F64Value(operand1->f64Get() + operand2->f32Get());
        case Float64: return new F64Value(operand1->f64Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->f64Get() + operand2->f80Get());
        case Bool: return new F64Value(operand1->f64Get() + operand2->bGet());
        case Var: return new VarValue(operand1->f64Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new F80Value(operand1->f80Get() + operand2->i8Get());
        case Int16: return new F80Value(operand1->f80Get() + operand2->i16Get());
        case Int32: return new F80Value(operand1->f80Get() + operand2->i32Get());
        case Int64: return new F80Value(operand1->f80Get() + operand2->i64Get());
        case UInt8: return new F80Value(operand1->f80Get() + operand2->ui8Get());
        case UInt16: return new F80Value(operand1->f80Get() + operand2->ui16Get());
        case UInt32: return new F80Value(operand1->f80Get() + operand2->ui32Get());
        case UInt64: return new F80Value(operand1->f80Get() + operand2->ui64Get());
        case Int: return new F80Value(operand1->f80Get() + operand2->f64Get());
        case Float32: return new F80Value(operand1->f80Get() + operand2->f32Get());
        case Float64: return new F80Value(operand1->f80Get() + operand2->f64Get());
        case Float80: return new F80Value(operand1->f80Get() + operand2->f80Get());
        case Bool: return new F80Value(operand1->f80Get() + operand2->bGet());
        case Var: return new VarValue(operand1->f80Get() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() + operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() + operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() + operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() + operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() + operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() + operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() + operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() + operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() + operand2->f64Get());
        case Float32: return new F32Value(operand1->bGet() + operand2->f32Get());
        case Float64: return new F64Value(operand1->bGet() + operand2->f64Get());
        case Float80: return new F80Value(operand1->bGet() + operand2->f80Get());
        case Bool: return new I8Value(operand1->bGet() + operand2->bGet());
        case Var: return new VarValue(operand1->bGet() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new StrValue(operand1->strGet() + operand2->strGet());
        case Var: return new VarValue(operand1->strGet() + operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() + operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() + operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() + operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() + operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() + operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() + operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() + operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() + operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() + operand2->iGet());
        case Float32: return new VarValue(operand1->varGet() + operand2->f32Get());
        case Float64: return new VarValue(operand1->varGet() + operand2->f64Get());
        case Float80: return new VarValue(operand1->varGet() + operand2->f80Get());
        case Bool: return new VarValue(operand1->varGet() + operand2->bGet());
        case Var: return new VarValue(operand1->varGet() + operand2->varGet());
        case String: return new VarValue(operand1->varGet() + operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new ArrValue(operand1->arrGet() + operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::sub()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() - operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() - operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() - operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() - operand2->i64Get());
        case UInt8: return new I8Value(operand1->i8Get() - operand2->ui8Get());
        case UInt16: return new I16Value(operand1->i8Get() - operand2->ui16Get());
        case UInt32: return new I32Value(operand1->i8Get() - operand2->ui32Get());
        case UInt64: return new I64Value(operand1->i8Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->i8Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->i8Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->i8Get() - operand2->f80Get());
        case Bool: return new I8Value(operand1->i8Get() - operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() - operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() - operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() - operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() - operand2->i64Get());
        case UInt8: return new I16Value(operand1->i16Get() - operand2->ui8Get());
        case UInt16: return new I16Value(operand1->i16Get() - operand2->ui16Get());
        case UInt32: return new I32Value(operand1->i16Get() - operand2->ui32Get());
        case UInt64: return new I64Value(operand1->i16Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->i16Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->i16Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->i16Get() - operand2->f80Get());
        case Bool: return new I16Value(operand1->i16Get() - operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() - operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() - operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() - operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() - operand2->i64Get());
        case UInt8: return new I32Value(operand1->i32Get() - operand2->ui8Get());
        case UInt16: return new I32Value(operand1->i32Get() - operand2->ui16Get());
        case UInt32: return new I32Value(operand1->i32Get() - operand2->ui32Get());
        case UInt64: return new I64Value(operand1->i32Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->i32Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->i32Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->i32Get() - operand2->f80Get());
        case Bool: return new I32Value(operand1->i32Get() - operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() - operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() - operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() - operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() - operand2->i64Get());
        case UInt8: return new I64Value(operand1->i64Get() - operand2->ui8Get());
        case UInt16: return new I64Value(operand1->i64Get() - operand2->ui16Get());
        case UInt32: return new I64Value(operand1->i64Get() - operand2->ui32Get());
        case UInt64: return new I64Value(operand1->i64Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->i64Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->i64Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->i64Get() - operand2->f80Get());
        case Bool: return new I64Value(operand1->i64Get() - operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() - operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() - operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() - operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() - operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() - operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() - operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() - operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->ui8Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->ui8Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->ui8Get() - operand2->f80Get());
        case Bool: return new UI8Value(operand1->ui8Get() - operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() - operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() - operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() - operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() - operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() - operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() - operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() - operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->ui16Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->ui16Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->ui16Get() - operand2->f80Get());
        case Bool: return new UI16Value(operand1->ui16Get() - operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() - operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() - operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() - operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() - operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() - operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() - operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() - operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->ui32Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->ui32Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->ui32Get() - operand2->f80Get());
        case Bool: return new UI32Value(operand1->ui32Get() - operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() - operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() - operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() - operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() - operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() - operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() - operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() - operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() - operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() - operand2->iGet());
        case Float32: return new F32Value(operand1->ui64Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->ui64Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->ui64Get() - operand2->f80Get());
        case Bool: return new UI64Value(operand1->ui64Get() - operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() - operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() - operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() - operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() - operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() - operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() - operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() - operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() - operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() - operand2->iGet());
        case Float32: return new F32Value(static_cast<float>(operand1->iGet() - operand2->f32Get()));
        case Float64: return new F64Value(static_cast<double>(operand1->iGet() - operand2->f64Get()));
        case Float80: return new F80Value(static_cast<long double>(operand1->iGet() - operand2->f80Get()));
        case Bool: return new IValue(operand1->iGet() - operand2->bGet());
        case Var: return new VarValue(operand1->iGet() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() - operand2->i8Get());
        case Int16: return new F32Value(operand1->f32Get() - operand2->i16Get());
        case Int32: return new F32Value(operand1->f32Get() - operand2->i32Get());
        case Int64: return new F32Value(operand1->f32Get() - operand2->i64Get());
        case UInt8: return new F32Value(operand1->f32Get() - operand2->ui8Get());
        case UInt16: return new F32Value(operand1->f32Get() - operand2->ui16Get());
        case UInt32: return new F32Value(operand1->f32Get() - operand2->ui32Get());
        case UInt64: return new F32Value(operand1->f32Get() - operand2->ui64Get());
        case Int: return new F32Value(operand1->f32Get() - operand2->f32Get());
        case Float32: return new F32Value(operand1->f32Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->f32Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->f32Get() - operand2->f80Get());
        case Bool: return new F32Value(operand1->f32Get() - operand2->bGet());
        case Var: return new VarValue(operand1->f32Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() - operand2->i8Get());
        case Int16: return new F64Value(operand1->f64Get() - operand2->i16Get());
        case Int32: return new F64Value(operand1->f64Get() - operand2->i32Get());
        case Int64: return new F64Value(operand1->f64Get() - operand2->i64Get());
        case UInt8: return new F64Value(operand1->f64Get() - operand2->ui8Get());
        case UInt16: return new F64Value(operand1->f64Get() - operand2->ui16Get());
        case UInt32: return new F64Value(operand1->f64Get() - operand2->ui32Get());
        case UInt64: return new F64Value(operand1->f64Get() - operand2->ui64Get());
        case Int: return new F64Value(operand1->f64Get() - operand2->f64Get());
        case Float32: return new F64Value(operand1->f64Get() - operand2->f32Get());
        case Float64: return new F64Value(operand1->f64Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->f64Get() - operand2->f80Get());
        case Bool: return new F64Value(operand1->f64Get() - operand2->bGet());
        case Var: return new VarValue(operand1->f64Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new F80Value(operand1->f80Get() - operand2->i8Get());
        case Int16: return new F80Value(operand1->f80Get() - operand2->i16Get());
        case Int32: return new F80Value(operand1->f80Get() - operand2->i32Get());
        case Int64: return new F80Value(operand1->f80Get() - operand2->i64Get());
        case UInt8: return new F80Value(operand1->f80Get() - operand2->ui8Get());
        case UInt16: return new F80Value(operand1->f80Get() - operand2->ui16Get());
        case UInt32: return new F80Value(operand1->f80Get() - operand2->ui32Get());
        case UInt64: return new F80Value(operand1->f80Get() - operand2->ui64Get());
        case Int: return new F80Value(operand1->f80Get() - operand2->f64Get());
        case Float32: return new F80Value(operand1->f80Get() - operand2->f32Get());
        case Float64: return new F80Value(operand1->f80Get() - operand2->f64Get());
        case Float80: return new F80Value(operand1->f80Get() - operand2->f80Get());
        case Bool: return new F80Value(operand1->f80Get() - operand2->bGet());
        case Var: return new VarValue(operand1->f80Get() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() - operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() - operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() - operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() - operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() - operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() - operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() - operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() - operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() - operand2->f64Get());
        case Float32: return new F32Value(operand1->bGet() - operand2->f32Get());
        case Float64: return new F64Value(operand1->bGet() - operand2->f64Get());
        case Float80: return new F80Value(operand1->bGet() - operand2->f80Get());
        case Bool: return new I8Value(operand1->bGet() - operand2->bGet());
        case Var: return new VarValue(operand1->bGet() - operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() - operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() - operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() - operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() - operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() - operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() - operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() - operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() - operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() - operand2->iGet());
        case Float32: return new VarValue(operand1->varGet() - operand2->f32Get());
        case Float64: return new VarValue(operand1->varGet() - operand2->f64Get());
        case Float80: return new VarValue(operand1->varGet() - operand2->f80Get());
        case Bool: return new VarValue(operand1->varGet() - operand2->bGet());
        case Var: return new VarValue(operand1->varGet() - operand2->varGet());
        case String: return new VarValue(operand1->varGet() - operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::mul()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() * operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() * operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() * operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() * operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() * operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->i8Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->i8Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->i8Get() * operand2->f80Get());
        case Bool: return new I8Value(operand1->i8Get() * operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() * operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() * operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() * operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() * operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() * operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->i16Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->i16Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->i16Get() * operand2->f80Get());
        case Bool: return new I16Value(operand1->i16Get() * operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() * operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() * operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() * operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() * operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() * operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->i32Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->i32Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->i32Get() * operand2->f80Get());
        case Bool: return new I32Value(operand1->i32Get() * operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() * operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() * operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() * operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() * operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() * operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() * operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->i64Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->i64Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->i64Get() * operand2->f80Get());
        case Bool: return new I64Value(operand1->i64Get() * operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() * operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() * operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() * operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() * operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() * operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->ui8Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->ui8Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->ui8Get() * operand2->f80Get());
        case Bool: return new UI8Value(operand1->ui8Get() * operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() * operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() * operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() * operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() * operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() * operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->ui16Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->ui16Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->ui16Get() * operand2->f80Get());
        case Bool: return new UI16Value(operand1->ui16Get() * operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() * operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() * operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() * operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() * operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() * operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->ui32Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->ui32Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->ui32Get() * operand2->f80Get());
        case Bool: return new UI32Value(operand1->ui32Get() * operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() * operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() * operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() * operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() * operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() * operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() * operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() * operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() * operand2->iGet());
        case Float32: return new F32Value(operand1->ui64Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->ui64Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->ui64Get() * operand2->f80Get());
        case Bool: return new UI64Value(operand1->ui64Get() * operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() * operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() * operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() * operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() * operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() * operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() * operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() * operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() * operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() * operand2->iGet());
        case Float32: return new F32Value(static_cast<float>(operand1->iGet() * operand2->f32Get()));
        case Float64: return new F64Value(static_cast<double>(operand1->iGet() * operand2->f64Get()));
        case Float80: return new F80Value(static_cast<long double>(operand1->iGet() * operand2->f80Get()));
        case Bool: return new IValue(operand1->iGet() * operand2->bGet());
        case Var: return new VarValue(operand1->iGet() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() * operand2->i8Get());
        case Int16: return new F32Value(operand1->f32Get() * operand2->i16Get());
        case Int32: return new F32Value(operand1->f32Get() * operand2->i32Get());
        case Int64: return new F32Value(operand1->f32Get() * operand2->i64Get());
        case UInt8: return new F32Value(operand1->f32Get() * operand2->ui8Get());
        case UInt16: return new F32Value(operand1->f32Get() * operand2->ui16Get());
        case UInt32: return new F32Value(operand1->f32Get() * operand2->ui32Get());
        case UInt64: return new F32Value(operand1->f32Get() * operand2->ui64Get());
        case Int: return new F32Value(operand1->f32Get() * operand2->f32Get());
        case Float32: return new F32Value(operand1->f32Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->f32Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->f32Get() * operand2->f80Get());
        case Bool: return new F32Value(operand1->f32Get() * operand2->bGet());
        case Var: return new VarValue(operand1->f32Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() * operand2->i8Get());
        case Int16: return new F64Value(operand1->f64Get() * operand2->i16Get());
        case Int32: return new F64Value(operand1->f64Get() * operand2->i32Get());
        case Int64: return new F64Value(operand1->f64Get() * operand2->i64Get());
        case UInt8: return new F64Value(operand1->f64Get() * operand2->ui8Get());
        case UInt16: return new F64Value(operand1->f64Get() * operand2->ui16Get());
        case UInt32: return new F64Value(operand1->f64Get() * operand2->ui32Get());
        case UInt64: return new F64Value(operand1->f64Get() * operand2->ui64Get());
        case Int: return new F64Value(operand1->f64Get() * operand2->f64Get());
        case Float32: return new F64Value(operand1->f64Get() * operand2->f32Get());
        case Float64: return new F64Value(operand1->f64Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->f64Get() * operand2->f80Get());
        case Bool: return new F64Value(operand1->f64Get() * operand2->bGet());
        case Var: return new VarValue(operand1->f64Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new F80Value(operand1->f80Get() * operand2->i8Get());
        case Int16: return new F80Value(operand1->f80Get() * operand2->i16Get());
        case Int32: return new F80Value(operand1->f80Get() * operand2->i32Get());
        case Int64: return new F80Value(operand1->f80Get() * operand2->i64Get());
        case UInt8: return new F80Value(operand1->f80Get() * operand2->ui8Get());
        case UInt16: return new F80Value(operand1->f80Get() * operand2->ui16Get());
        case UInt32: return new F80Value(operand1->f80Get() * operand2->ui32Get());
        case UInt64: return new F80Value(operand1->f80Get() * operand2->ui64Get());
        case Int: return new F80Value(operand1->f80Get() * operand2->f64Get());
        case Float32: return new F80Value(operand1->f80Get() * operand2->f32Get());
        case Float64: return new F80Value(operand1->f80Get() * operand2->f64Get());
        case Float80: return new F80Value(operand1->f80Get() * operand2->f80Get());
        case Bool: return new F80Value(operand1->f80Get() * operand2->bGet());
        case Var: return new VarValue(operand1->f80Get() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() * operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() * operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() * operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() * operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() * operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() * operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() * operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() * operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() * operand2->f64Get());
        case Float32: return new F32Value(operand1->bGet() * operand2->f32Get());
        case Float64: return new F64Value(operand1->bGet() * operand2->f64Get());
        case Float80: return new F80Value(operand1->bGet() * operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() * operand2->bGet());
        case Var: return new VarValue(operand1->bGet() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case Int8: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case Int16: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case Int32: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case Int64: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case UInt8: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case UInt16: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case UInt32: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case UInt64: return new StrValue(operand1->strGet() * operand2->ui64Get());
        case Var: return new VarValue(operand1->strGet() * operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() * operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() * operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() * operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() * operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() * operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() * operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() * operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() * operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() * operand2->iGet());
        case Float32: return new VarValue(operand1->varGet() * operand2->f32Get());
        case Float64: return new VarValue(operand1->varGet() * operand2->f64Get());
        case Float80: return new VarValue(operand1->varGet() * operand2->f80Get());
        case Bool: return new VarValue(operand1->varGet() * operand2->bGet());
        case Var: return new VarValue(operand1->varGet() * operand2->varGet());
        case String: return new VarValue(operand1->varGet() * operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Int8: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case Int16: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case Int32: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case Int64: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case UInt8: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case UInt16: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case UInt32: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        case UInt64: return new ArrValue(operand1->arrGet() * operand2->ui64Get());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::div()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->i8Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->i8Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->i8Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->i8Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->i8Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->i8Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->i8Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->i8Get() / operand2->ui64Get());
        case Int: return new F32Value(static_cast<float>(operand1->i8Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->i8Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->i8Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->i8Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->i8Get() / operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->i16Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->i16Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->i16Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->i16Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->i16Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->i16Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->i16Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->i16Get() / operand2->ui64Get());
        case Int: return new F32Value(static_cast<float>(operand1->i16Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->i16Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->i16Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->i16Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->i16Get() / operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->i32Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->i32Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->i32Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->i32Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->i32Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->i32Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->i32Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->i32Get() / operand2->ui64Get());
        case Int: return new F32Value(static_cast<float>(operand1->i32Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->i32Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->i32Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->i32Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->i32Get() / operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->i64Get() / operand2->i8Get());
        case Int16: return new F64Value(operand1->i64Get() / operand2->i16Get());
        case Int32: return new F64Value(operand1->i64Get() / operand2->i32Get());
        case Int64: return new F64Value(operand1->i64Get() / operand2->i64Get());
        case UInt8: return new F64Value(operand1->i64Get() / operand2->ui8Get());
        case UInt16: return new F64Value(operand1->i64Get() / operand2->ui16Get());
        case UInt32: return new F64Value(operand1->i64Get() / operand2->ui32Get());
        case UInt64: return new F64Value(operand1->i64Get() / operand2->ui64Get());
        case Int: return new F64Value(static_cast<double>(operand1->i64Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->i64Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->i64Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->i64Get() / operand2->f80Get());
        case Bool: return new F64Value(operand1->i64Get() / operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->ui8Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->ui8Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->ui8Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->ui8Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->ui8Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->ui8Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->ui8Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->ui8Get() / operand2->ui64Get());
        case Int: return new F32Value(static_cast<float>(operand1->ui8Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->ui8Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->ui8Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->ui8Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->ui8Get() / operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->ui16Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->ui16Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->ui16Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->ui16Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->ui16Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->ui16Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->ui16Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->ui16Get() / operand2->ui64Get());
        case Int: return new F32Value(static_cast<float>(operand1->ui16Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->ui16Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->ui16Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->ui16Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->ui16Get() / operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->ui32Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->ui32Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->ui32Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->ui32Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->ui32Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->ui32Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->ui32Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->ui32Get() / operand2->ui64Get());
        case Int: return new F32Value(static_cast<float>(operand1->ui32Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->ui32Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->ui32Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->ui32Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->ui32Get() / operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->ui64Get() / operand2->i8Get());
        case Int16: return new F64Value(operand1->ui64Get() / operand2->i16Get());
        case Int32: return new F64Value(operand1->ui64Get() / operand2->i32Get());
        case Int64: return new F64Value(operand1->ui64Get() / operand2->i64Get());
        case UInt8: return new F64Value(operand1->ui64Get() / operand2->ui8Get());
        case UInt16: return new F64Value(operand1->ui64Get() / operand2->ui16Get());
        case UInt32: return new F64Value(operand1->ui64Get() / operand2->ui32Get());
        case UInt64: return new F64Value(operand1->ui64Get() / operand2->ui64Get());
        case Int: return new F64Value(static_cast<double>(operand1->ui64Get() / operand2->iGet()));
        case Float32: return new F32Value(operand1->ui64Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->ui64Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->ui64Get() / operand2->f80Get());
        case Bool: return new F64Value(operand1->ui64Get() / operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(static_cast<double>(operand1->iGet() / operand2->i8Get()));
        case Int16: return new F64Value(static_cast<double>(operand1->iGet() / operand2->i16Get()));
        case Int32: return new F64Value(static_cast<double>(operand1->iGet() / operand2->i32Get()));
        case Int64: return new F64Value(static_cast<double>(operand1->iGet() / operand2->i64Get()));
        case UInt8: return new F64Value(static_cast<double>(operand1->iGet() / operand2->ui8Get()));
        case UInt16: return new F64Value(static_cast<double>(operand1->iGet() / operand2->ui16Get()));
        case UInt32: return new F64Value(static_cast<double>(operand1->iGet() / operand2->ui32Get()));
        case UInt64: return new F64Value(static_cast<double>(operand1->iGet() / operand2->ui64Get()));
        case Int: return new F64Value(static_cast<double>(operand1->iGet() / operand2->iGet()));
        case Float32: return new F32Value(static_cast<float>(operand1->iGet() / operand2->f32Get()));
        case Float64: return new F64Value(static_cast<double>(operand1->iGet() / operand2->f64Get()));
        case Float80: return new F80Value(static_cast<long double>(operand1->iGet() / operand2->f80Get()));
        case Bool: return new F64Value(static_cast<double>(operand1->iGet() / operand2->bGet()));
        case Var: return new VarValue(operand1->iGet() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() / operand2->i8Get());
        case Int16: return new F32Value(operand1->f32Get() / operand2->i16Get());
        case Int32: return new F32Value(operand1->f32Get() / operand2->i32Get());
        case Int64: return new F32Value(operand1->f32Get() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->f32Get() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->f32Get() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->f32Get() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->f32Get() / operand2->ui64Get());
        case Int: return new F32Value(operand1->f32Get() / operand2->f32Get());
        case Float32: return new F32Value(operand1->f32Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->f32Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->f32Get() / operand2->f80Get());
        case Bool: return new F32Value(operand1->f32Get() / operand2->bGet());
        case Var: return new VarValue(operand1->f32Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() / operand2->i8Get());
        case Int16: return new F64Value(operand1->f64Get() / operand2->i16Get());
        case Int32: return new F64Value(operand1->f64Get() / operand2->i32Get());
        case Int64: return new F64Value(operand1->f64Get() / operand2->i64Get());
        case UInt8: return new F64Value(operand1->f64Get() / operand2->ui8Get());
        case UInt16: return new F64Value(operand1->f64Get() / operand2->ui16Get());
        case UInt32: return new F64Value(operand1->f64Get() / operand2->ui32Get());
        case UInt64: return new F64Value(operand1->f64Get() / operand2->ui64Get());
        case Int: return new F64Value(operand1->f64Get() / operand2->f64Get());
        case Float32: return new F64Value(operand1->f64Get() / operand2->f32Get());
        case Float64: return new F64Value(operand1->f64Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->f64Get() / operand2->f80Get());
        case Bool: return new F64Value(operand1->f64Get() / operand2->bGet());
        case Var: return new VarValue(operand1->f64Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new F80Value(operand1->f80Get() / operand2->i8Get());
        case Int16: return new F80Value(operand1->f80Get() / operand2->i16Get());
        case Int32: return new F80Value(operand1->f80Get() / operand2->i32Get());
        case Int64: return new F80Value(operand1->f80Get() / operand2->i64Get());
        case UInt8: return new F80Value(operand1->f80Get() / operand2->ui8Get());
        case UInt16: return new F80Value(operand1->f80Get() / operand2->ui16Get());
        case UInt32: return new F80Value(operand1->f80Get() / operand2->ui32Get());
        case UInt64: return new F80Value(operand1->f80Get() / operand2->ui64Get());
        case Int: return new F80Value(operand1->f80Get() / operand2->f64Get());
        case Float32: return new F80Value(operand1->f80Get() / operand2->f32Get());
        case Float64: return new F80Value(operand1->f80Get() / operand2->f64Get());
        case Float80: return new F80Value(operand1->f80Get() / operand2->f80Get());
        case Bool: return new F80Value(operand1->f80Get() / operand2->bGet());
        case Var: return new VarValue(operand1->f80Get() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->bGet() / operand2->i8Get());
        case Int16: return new F32Value(operand1->bGet() / operand2->i16Get());
        case Int32: return new F32Value(operand1->bGet() / operand2->i32Get());
        case Int64: return new F32Value(operand1->bGet() / operand2->i64Get());
        case UInt8: return new F32Value(operand1->bGet() / operand2->ui8Get());
        case UInt16: return new F32Value(operand1->bGet() / operand2->ui16Get());
        case UInt32: return new F32Value(operand1->bGet() / operand2->ui32Get());
        case UInt64: return new F32Value(operand1->bGet() / operand2->ui64Get());
        case Int: return new F32Value(operand1->bGet() / operand2->f64Get());
        case Float32: return new F32Value(operand1->bGet() / operand2->f32Get());
        case Float64: return new F64Value(operand1->bGet() / operand2->f64Get());
        case Float80: return new F80Value(operand1->bGet() / operand2->f80Get());
        case Bool: return new F32Value(operand1->bGet() / operand2->bGet());
        case Var: return new VarValue(operand1->bGet() / operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() / operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() / operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() / operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() / operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() / operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() / operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() / operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() / operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() / operand2->iGet());
        case Float32: return new VarValue(operand1->varGet() / operand2->f32Get());
        case Float64: return new VarValue(operand1->varGet() / operand2->f64Get());
        case Float80: return new VarValue(operand1->varGet() / operand2->f80Get());
        case Bool: return new VarValue(operand1->varGet() / operand2->bGet());
        case Var: return new VarValue(operand1->varGet() / operand2->varGet());
        case String: return new VarValue(operand1->varGet() / operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::mod()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() % operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() % operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() % operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() % operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() % operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() % operand2->iGet());
        case Bool: return new I8Value(operand1->i8Get() % operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() % operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() % operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() % operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() % operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() % operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() % operand2->iGet());
        case Bool: return new I16Value(operand1->i16Get() % operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() % operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() % operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() % operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() % operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() % operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() % operand2->iGet());
        case Bool: return new I32Value(operand1->i32Get() % operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() % operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() % operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() % operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() % operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() % operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() % operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() % operand2->iGet());
        case Bool: return new I64Value(operand1->i64Get() % operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() % operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() % operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() % operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() % operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() % operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() % operand2->iGet());
        case Bool: return new UI8Value(operand1->ui8Get() % operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() % operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() % operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() % operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() % operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() % operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() % operand2->iGet());
        case Bool: return new UI16Value(operand1->ui16Get() % operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() % operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() % operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() % operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() % operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() % operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() % operand2->iGet());
        case Bool: return new UI32Value(operand1->ui32Get() % operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() % operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() % operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() % operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() % operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() % operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() % operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() % operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() % operand2->iGet());
        case Bool: return new UI64Value(operand1->ui64Get() % operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() % operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() % operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() % operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() % operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() % operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() % operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() % operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() % operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() % operand2->iGet());
        case Bool: return new IValue(operand1->iGet() % operand2->bGet());
        case Var: return new VarValue(operand1->iGet() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() % operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() % operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() % operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() % operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() % operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() % operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() % operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() % operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() % operand2->iGet());
        case Bool: return new I8Value(operand1->bGet() % operand2->bGet());
        case Var: return new VarValue(operand1->bGet() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() % operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() % operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() % operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() % operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() % operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() % operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() % operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() % operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() % operand2->iGet());
        case Bool: return new VarValue(operand1->varGet() % operand2->bGet());
        case Var: return new VarValue(operand1->varGet() % operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::bitwiseAnd()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() & operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() & operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() & operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() & operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() & operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() & operand2->iGet());
        case Bool: return new I8Value(operand1->i8Get() & operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() & operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() & operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() & operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() & operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() & operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() & operand2->iGet());
        case Bool: return new I16Value(operand1->i16Get() & operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() & operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() & operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() & operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() & operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() & operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() & operand2->iGet());
        case Bool: return new I32Value(operand1->i32Get() & operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() & operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() & operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() & operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() & operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() & operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() & operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() & operand2->iGet());
        case Bool: return new I64Value(operand1->i64Get() & operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() & operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() & operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() & operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() & operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() & operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() & operand2->iGet());
        case Bool: return new UI8Value(operand1->ui8Get() & operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() & operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() & operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() & operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() & operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() & operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() & operand2->iGet());
        case Bool: return new UI16Value(operand1->ui16Get() & operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() & operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() & operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() & operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() & operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() & operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() & operand2->iGet());
        case Bool: return new UI32Value(operand1->ui32Get() & operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() & operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() & operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() & operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() & operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() & operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() & operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() & operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() & operand2->iGet());
        case Bool: return new UI64Value(operand1->ui64Get() & operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() & operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() & operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() & operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() & operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() & operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() & operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() & operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() & operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() & operand2->iGet());
        case Bool: return new IValue(operand1->iGet() & operand2->bGet());
        case Var: return new VarValue(operand1->iGet() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() & operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() & operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() & operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() & operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() & operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() & operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() & operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() & operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() & operand2->iGet());
        case Bool: return new I8Value(operand1->bGet() & operand2->bGet());
        case Var: return new VarValue(operand1->bGet() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() & operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() & operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() & operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() & operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() & operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() & operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() & operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() & operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() & operand2->iGet());
        case Bool: return new VarValue(operand1->varGet() & operand2->bGet());
        case Var: return new VarValue(operand1->varGet() & operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::bitwiseOr()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() | operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() | operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() | operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() | operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() | operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() | operand2->iGet());
        case Bool: return new I8Value(operand1->i8Get() | operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() | operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() | operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() | operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() | operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() | operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() | operand2->iGet());
        case Bool: return new I16Value(operand1->i16Get() | operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() | operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() | operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() | operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() | operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() | operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() | operand2->iGet());
        case Bool: return new I32Value(operand1->i32Get() | operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() | operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() | operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() | operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() | operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() | operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() | operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() | operand2->iGet());
        case Bool: return new I64Value(operand1->i64Get() | operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() | operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() | operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() | operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() | operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() | operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() | operand2->iGet());
        case Bool: return new UI8Value(operand1->ui8Get() | operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() | operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() | operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() | operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() | operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() | operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() | operand2->iGet());
        case Bool: return new UI16Value(operand1->ui16Get() | operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() | operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() | operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() | operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() | operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() | operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() | operand2->iGet());
        case Bool: return new UI32Value(operand1->ui32Get() | operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() | operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() | operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() | operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() | operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() | operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() | operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() | operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() | operand2->iGet());
        case Bool: return new UI64Value(operand1->ui64Get() | operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() | operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() | operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() | operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() | operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() | operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() | operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() | operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() | operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() | operand2->iGet());
        case Bool: return new IValue(operand1->iGet() | operand2->bGet());
        case Var: return new VarValue(operand1->iGet() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() | operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() | operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() | operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() | operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() | operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() | operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() | operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() | operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() | operand2->iGet());
        case Bool: return new I8Value(operand1->bGet() | operand2->bGet());
        case Var: return new VarValue(operand1->bGet() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() | operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() | operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() | operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() | operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() | operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() | operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() | operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() | operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() | operand2->iGet());
        case Bool: return new VarValue(operand1->varGet() | operand2->bGet());
        case Var: return new VarValue(operand1->varGet() | operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::bitwiseXor()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() ^ operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() ^ operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() ^ operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() ^ operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() ^ operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() ^ operand2->iGet());
        case Bool: return new I8Value(operand1->i8Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() ^ operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() ^ operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() ^ operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() ^ operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() ^ operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() ^ operand2->iGet());
        case Bool: return new I16Value(operand1->i16Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() ^ operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() ^ operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() ^ operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() ^ operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() ^ operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() ^ operand2->iGet());
        case Bool: return new I32Value(operand1->i32Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() ^ operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() ^ operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() ^ operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() ^ operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() ^ operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() ^ operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() ^ operand2->iGet());
        case Bool: return new I64Value(operand1->i64Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() ^ operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() ^ operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() ^ operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() ^ operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() ^ operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() ^ operand2->iGet());
        case Bool: return new UI8Value(operand1->ui8Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() ^ operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() ^ operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() ^ operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() ^ operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() ^ operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() ^ operand2->iGet());
        case Bool: return new UI16Value(operand1->ui16Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() ^ operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() ^ operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() ^ operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() ^ operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() ^ operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() ^ operand2->iGet());
        case Bool: return new UI32Value(operand1->ui32Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() ^ operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() ^ operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() ^ operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() ^ operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() ^ operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() ^ operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() ^ operand2->iGet());
        case Bool: return new UI64Value(operand1->ui64Get() ^ operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() ^ operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() ^ operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() ^ operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() ^ operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() ^ operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() ^ operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() ^ operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() ^ operand2->iGet());
        case Bool: return new IValue(operand1->iGet() ^ operand2->bGet());
        case Var: return new VarValue(operand1->iGet() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() ^ operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() ^ operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() ^ operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() ^ operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() ^ operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() ^ operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() ^ operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() ^ operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() ^ operand2->iGet());
        case Bool: return new I8Value(operand1->bGet() ^ operand2->bGet());
        case Var: return new VarValue(operand1->bGet() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() ^ operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() ^ operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() ^ operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() ^ operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() ^ operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() ^ operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() ^ operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() ^ operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() ^ operand2->iGet());
        case Bool: return new VarValue(operand1->varGet() ^ operand2->bGet());
        case Var: return new VarValue(operand1->varGet() ^ operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::shl()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() << operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() << operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() << operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() << operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() << operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() << operand2->iGet());
        case Bool: return new I8Value(operand1->i8Get() << operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() << operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() << operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() << operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() << operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() << operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() << operand2->iGet());
        case Bool: return new I16Value(operand1->i16Get() << operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() << operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() << operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() << operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() << operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() << operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() << operand2->iGet());
        case Bool: return new I32Value(operand1->i32Get() << operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() << operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() << operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() << operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() << operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() << operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() << operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() << operand2->iGet());
        case Bool: return new I64Value(operand1->i64Get() << operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() << operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() << operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() << operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() << operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() << operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() << operand2->iGet());
        case Bool: return new UI8Value(operand1->ui8Get() << operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() << operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() << operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() << operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() << operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() << operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() << operand2->iGet());
        case Bool: return new UI16Value(operand1->ui16Get() << operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() << operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() << operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() << operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() << operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() << operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() << operand2->iGet());
        case Bool: return new UI32Value(operand1->ui32Get() << operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() << operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() << operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() << operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() << operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() << operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() << operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() << operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() << operand2->iGet());
        case Bool: return new UI64Value(operand1->ui64Get() << operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() << operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() << operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() << operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() << operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() << operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() << operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() << operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() << operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() << operand2->iGet());
        case Bool: return new IValue(operand1->iGet() << operand2->bGet());
        case Var: return new VarValue(operand1->iGet() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() << operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() << operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() << operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() << operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() << operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() << operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() << operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() << operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() << operand2->iGet());
        case Bool: return new I8Value(operand1->bGet() << operand2->bGet());
        case Var: return new VarValue(operand1->bGet() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() << operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() << operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() << operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() << operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() << operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() << operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() << operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() << operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() << operand2->iGet());
        case Bool: return new VarValue(operand1->varGet() << operand2->bGet());
        case Var: return new VarValue(operand1->varGet() << operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *BinaryExpression::shr()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() >> operand2->i8Get());
        case Int16: return new I16Value(operand1->i8Get() >> operand2->i16Get());
        case Int32: return new I32Value(operand1->i8Get() >> operand2->i32Get());
        case Int64: return new I64Value(operand1->i8Get() >> operand2->i64Get());
        case UInt8: return new UI8Value(operand1->i8Get() >> operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i8Get() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i8Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i8Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->i8Get() >> operand2->iGet());
        case Bool: return new I8Value(operand1->i8Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->i8Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() >> operand2->i8Get());
        case Int16: return new I16Value(operand1->i16Get() >> operand2->i16Get());
        case Int32: return new I32Value(operand1->i16Get() >> operand2->i32Get());
        case Int64: return new I64Value(operand1->i16Get() >> operand2->i64Get());
        case UInt8: return new UI16Value(operand1->i16Get() >> operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->i16Get() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i16Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i16Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->i16Get() >> operand2->iGet());
        case Bool: return new I16Value(operand1->i16Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->i16Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() >> operand2->i8Get());
        case Int16: return new I32Value(operand1->i32Get() >> operand2->i16Get());
        case Int32: return new I32Value(operand1->i32Get() >> operand2->i32Get());
        case Int64: return new I64Value(operand1->i32Get() >> operand2->i64Get());
        case UInt8: return new UI32Value(operand1->i32Get() >> operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->i32Get() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->i32Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i32Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->i32Get() >> operand2->iGet());
        case Bool: return new I32Value(operand1->i32Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->i32Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() >> operand2->i8Get());
        case Int16: return new I64Value(operand1->i64Get() >> operand2->i16Get());
        case Int32: return new I64Value(operand1->i64Get() >> operand2->i32Get());
        case Int64: return new I64Value(operand1->i64Get() >> operand2->i64Get());
        case UInt8: return new UI64Value(operand1->i64Get() >> operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->i64Get() >> operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->i64Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->i64Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->i64Get() >> operand2->iGet());
        case Bool: return new I64Value(operand1->i64Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->i64Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() >> operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui8Get() >> operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui8Get() >> operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui8Get() >> operand2->i64Get());
        case UInt8: return new UI8Value(operand1->ui8Get() >> operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui8Get() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui8Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui8Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->ui8Get() >> operand2->iGet());
        case Bool: return new UI8Value(operand1->ui8Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->ui8Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() >> operand2->i8Get());
        case Int16: return new UI16Value(operand1->ui16Get() >> operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui16Get() >> operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui16Get() >> operand2->i64Get());
        case UInt8: return new UI16Value(operand1->ui16Get() >> operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->ui16Get() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui16Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui16Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->ui16Get() >> operand2->iGet());
        case Bool: return new UI16Value(operand1->ui16Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->ui16Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() >> operand2->i8Get());
        case Int16: return new UI32Value(operand1->ui32Get() >> operand2->i16Get());
        case Int32: return new UI32Value(operand1->ui32Get() >> operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui32Get() >> operand2->i64Get());
        case UInt8: return new UI32Value(operand1->ui32Get() >> operand2->ui8Get());
        case UInt16: return new UI32Value(operand1->ui32Get() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->ui32Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui32Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->ui32Get() >> operand2->iGet());
        case Bool: return new UI32Value(operand1->ui32Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->ui32Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() >> operand2->i8Get());
        case Int16: return new UI64Value(operand1->ui64Get() >> operand2->i16Get());
        case Int32: return new UI64Value(operand1->ui64Get() >> operand2->i32Get());
        case Int64: return new UI64Value(operand1->ui64Get() >> operand2->i64Get());
        case UInt8: return new UI64Value(operand1->ui64Get() >> operand2->ui8Get());
        case UInt16: return new UI64Value(operand1->ui64Get() >> operand2->ui16Get());
        case UInt32: return new UI64Value(operand1->ui64Get() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->ui64Get() >> operand2->ui64Get());
        case Int: return new IValue(operand1->ui64Get() >> operand2->iGet());
        case Bool: return new UI64Value(operand1->ui64Get() >> operand2->bGet());
        case Var: return new VarValue(operand1->ui64Get() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() >> operand2->i8Get());
        case Int16: return new IValue(operand1->iGet() >> operand2->i16Get());
        case Int32: return new IValue(operand1->iGet() >> operand2->i32Get());
        case Int64: return new IValue(operand1->iGet() >> operand2->i64Get());
        case UInt8: return new IValue(operand1->iGet() >> operand2->ui8Get());
        case UInt16: return new IValue(operand1->iGet() >> operand2->ui16Get());
        case UInt32: return new IValue(operand1->iGet() >> operand2->ui32Get());
        case UInt64: return new IValue(operand1->iGet() >> operand2->ui64Get());
        case Int: return new IValue(operand1->iGet() >> operand2->iGet());
        case Bool: return new IValue(operand1->iGet() >> operand2->bGet());
        case Var: return new VarValue(operand1->iGet() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() >> operand2->i8Get());
        case Int16: return new I16Value(operand1->bGet() >> operand2->i16Get());
        case Int32: return new I32Value(operand1->bGet() >> operand2->i32Get());
        case Int64: return new I64Value(operand1->bGet() >> operand2->i64Get());
        case UInt8: return new UI8Value(operand1->bGet() >> operand2->ui8Get());
        case UInt16: return new UI16Value(operand1->bGet() >> operand2->ui16Get());
        case UInt32: return new UI32Value(operand1->bGet() >> operand2->ui32Get());
        case UInt64: return new UI64Value(operand1->bGet() >> operand2->ui64Get());
        case Int: return new IValue(operand1->bGet() >> operand2->iGet());
        case Bool: return new I8Value(operand1->bGet() >> operand2->bGet());
        case Var: return new VarValue(operand1->bGet() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() >> operand2->i8Get());
        case Int16: return new VarValue(operand1->varGet() >> operand2->i16Get());
        case Int32: return new VarValue(operand1->varGet() >> operand2->i32Get());
        case Int64: return new VarValue(operand1->varGet() >> operand2->i64Get());
        case UInt8: return new VarValue(operand1->varGet() >> operand2->ui8Get());
        case UInt16: return new VarValue(operand1->varGet() >> operand2->ui16Get());
        case UInt32: return new VarValue(operand1->varGet() >> operand2->ui32Get());
        case UInt64: return new VarValue(operand1->varGet() >> operand2->ui64Get());
        case Int: return new VarValue(operand1->varGet() >> operand2->iGet());
        case Bool: return new VarValue(operand1->varGet() >> operand2->bGet());
        case Var: return new VarValue(operand1->varGet() >> operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

#endif