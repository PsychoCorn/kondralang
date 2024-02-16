#ifndef BinaryExpression_HPP
#define BinaryExpression_HPP

#include "Expression.hpp"
#include "../interpreter/Token.hpp"
#include <string>
#include <stdexcept>

#define ERR_MSG_WRNG_BIN_OP "Wrong binary operator"
#define ERR_MSG_WRNG_OPNDS "Wrong operands"

class BinaryExpression : public Expression
{
private:
    Expression* expr1;
    Expression* expr2;
    TokenType operation;
    
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
    BinaryExpression(TokenType, Expression*, Expression*);
    ~BinaryExpression();
    Value *eval() override;
};

BinaryExpression::BinaryExpression(TokenType operation, Expression* expr1, Expression* expr2)
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
    switch (operation)
    {
    case TokenType::Plus: return add();
    case TokenType::Minus: return sub();
    case TokenType::Star: return mul();
    case TokenType::Slash: return div();
    case TokenType::Percentage: return mod();
    case TokenType::Ampersand: return bitwiseAnd();
    case TokenType::Pipe: return bitwiseOr();
    case TokenType::Caret: return bitwiseXor();
    case TokenType::Lshift: return shl();
    case TokenType::Rshift: return shr();
    default:
        throw std::runtime_error(ERR_MSG_WRNG_BIN_OP);
    }
}

Value *BinaryExpression::add()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->i8Get() + operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() + operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() + operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() + operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() + operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i8Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i8Get() + operand2->f64Get(), true);
        case Bool: return new I8Value(operand1->i8Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() + operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() + operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() + operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() + operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() + operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i16Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i16Get() + operand2->f64Get(), true);
        case Bool: return new I16Value(operand1->i16Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() + operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() + operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() + operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() + operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() + operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i32Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i32Get() + operand2->f64Get(), true);
        case Bool: return new I32Value(operand1->i32Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() + operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() + operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() + operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() + operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() + operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() + operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i64Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i64Get() + operand2->f64Get(), true);
        case Bool: return new I64Value(operand1->i64Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() + operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() + operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() + operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() + operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() + operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui8Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui8Get() + operand2->f64Get(), true);
        case Bool: return new UI8Value(operand1->ui8Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() + operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() + operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() + operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() + operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() + operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui16Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui16Get() + operand2->f64Get(), true);
        case Bool: return new UI16Value(operand1->ui16Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() + operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() + operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() + operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() + operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() + operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui32Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui32Get() + operand2->f64Get(), true);
        case Bool: return new UI32Value(operand1->ui32Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() + operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() + operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() + operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() + operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() + operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() + operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui64Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui64Get() + operand2->f64Get(), true);
        case Bool: return new UI64Value(operand1->ui64Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() + operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() + operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() + operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() + operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() + operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() + operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() + operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() + operand2->iGet(), true);
        case Float32: return new F32Value(operand1->f64Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() + operand2->f64Get(), true);
        case Bool: return new IValue(operand1->iGet() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() + operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->f32Get() + operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->f32Get() + operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->f32Get() + operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->f32Get() + operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->f32Get() + operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->f32Get() + operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->f32Get() + operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->f32Get() + operand2->f32Get(), true);
        case Float32: return new F32Value(operand1->f32Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f32Get() + operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->f32Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->f32Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() + operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->f64Get() + operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->f64Get() + operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->f64Get() + operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->f64Get() + operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->f64Get() + operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->f64Get() + operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->f64Get() + operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->f64Get() + operand2->f64Get(), true);
        case Float32: return new F64Value(operand1->f64Get() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() + operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->f64Get() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->f64Get() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() + operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() + operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() + operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() + operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() + operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() + operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() + operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() + operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() + operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->bGet() + operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->bGet() + operand2->f64Get(), true);
        case Bool: return new I8Value(operand1->bGet() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new StrValue(operand1->strGet() + operand2->strGet(), true);
        case Var: return new VarValue(operand1->strGet() + operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() + operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() + operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() + operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() + operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() + operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() + operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() + operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() + operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() + operand2->iGet(), true);
        case Float32: return new VarValue(operand1->varGet() + operand2->f32Get(), true);
        case Float64: return new VarValue(operand1->varGet() + operand2->f64Get(), true);
        case Bool: return new VarValue(operand1->varGet() + operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() + operand2->varGet(), true);
        case String: return new VarValue(operand1->varGet() + operand2->strGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new ArrValue(operand1->arrGet() + operand2->arrGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() - operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() - operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() - operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() - operand2->i64Get(), true);
        case UInt8: return new I8Value(operand1->i8Get() - operand2->ui8Get(), true);
        case UInt16: return new I16Value(operand1->i8Get() - operand2->ui16Get(), true);
        case UInt32: return new I32Value(operand1->i8Get() - operand2->ui32Get(), true);
        case UInt64: return new I64Value(operand1->i8Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i8Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i8Get() - operand2->f64Get(), true);
        case Bool: return new I8Value(operand1->i8Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() - operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() - operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() - operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() - operand2->i64Get(), true);
        case UInt8: return new I16Value(operand1->i16Get() - operand2->ui8Get(), true);
        case UInt16: return new I16Value(operand1->i16Get() - operand2->ui16Get(), true);
        case UInt32: return new I32Value(operand1->i16Get() - operand2->ui32Get(), true);
        case UInt64: return new I64Value(operand1->i16Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i16Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i16Get() - operand2->f64Get(), true);
        case Bool: return new I16Value(operand1->i16Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() - operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() - operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() - operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() - operand2->i64Get(), true);
        case UInt8: return new I32Value(operand1->i32Get() - operand2->ui8Get(), true);
        case UInt16: return new I32Value(operand1->i32Get() - operand2->ui16Get(), true);
        case UInt32: return new I32Value(operand1->i32Get() - operand2->ui32Get(), true);
        case UInt64: return new I64Value(operand1->i32Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i32Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i32Get() - operand2->f64Get(), true);
        case Bool: return new I32Value(operand1->i32Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() - operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() - operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() - operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() - operand2->i64Get(), true);
        case UInt8: return new I64Value(operand1->i64Get() - operand2->ui8Get(), true);
        case UInt16: return new I64Value(operand1->i64Get() - operand2->ui16Get(), true);
        case UInt32: return new I64Value(operand1->i64Get() - operand2->ui32Get(), true);
        case UInt64: return new I64Value(operand1->i64Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i64Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i64Get() - operand2->f64Get(), true);
        case Bool: return new I64Value(operand1->i64Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() - operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() - operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() - operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() - operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() - operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() - operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() - operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui8Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui8Get() - operand2->f64Get(), true);
        case Bool: return new UI8Value(operand1->ui8Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() - operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() - operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() - operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() - operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() - operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() - operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() - operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui16Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui16Get() - operand2->f64Get(), true);
        case Bool: return new UI16Value(operand1->ui16Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() - operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() - operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() - operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() - operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() - operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() - operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() - operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui32Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui32Get() - operand2->f64Get(), true);
        case Bool: return new UI32Value(operand1->ui32Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() - operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() - operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() - operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() - operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() - operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() - operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() - operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui64Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui64Get() - operand2->f64Get(), true);
        case Bool: return new UI64Value(operand1->ui64Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() - operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() - operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() - operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() - operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() - operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() - operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() - operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() - operand2->iGet(), true);
        case Float32: return new F32Value(operand1->f64Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() - operand2->f64Get(), true);
        case Bool: return new IValue(operand1->iGet() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() - operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->f32Get() - operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->f32Get() - operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->f32Get() - operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->f32Get() - operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->f32Get() - operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->f32Get() - operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->f32Get() - operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->f32Get() - operand2->f32Get(), true);
        case Float32: return new F32Value(operand1->f32Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f32Get() - operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->f32Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->f32Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() - operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->f64Get() - operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->f64Get() - operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->f64Get() - operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->f64Get() - operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->f64Get() - operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->f64Get() - operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->f64Get() - operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->f64Get() - operand2->f64Get(), true);
        case Float32: return new F64Value(operand1->f64Get() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() - operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->f64Get() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->f64Get() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() - operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() - operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() - operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() - operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() - operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() - operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() - operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() - operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() - operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->bGet() - operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->bGet() - operand2->f64Get(), true);
        case Bool: return new I8Value(operand1->bGet() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() - operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() - operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() - operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() - operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() - operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() - operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() - operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() - operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() - operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() - operand2->iGet(), true);
        case Float32: return new VarValue(operand1->varGet() - operand2->f32Get(), true);
        case Float64: return new VarValue(operand1->varGet() - operand2->f64Get(), true);
        case Bool: return new VarValue(operand1->varGet() - operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() - operand2->varGet(), true);
        case String: return new VarValue(operand1->varGet() - operand2->strGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() * operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() * operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() * operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() * operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() * operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i8Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i8Get() * operand2->f64Get(), true);
        case Bool: return new I8Value(operand1->i8Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() * operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() * operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() * operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() * operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() * operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i16Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i16Get() * operand2->f64Get(), true);
        case Bool: return new I16Value(operand1->i16Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() * operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() * operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() * operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() * operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() * operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i32Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i32Get() * operand2->f64Get(), true);
        case Bool: return new I32Value(operand1->i32Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() * operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() * operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() * operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() * operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() * operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() * operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->i64Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i64Get() * operand2->f64Get(), true);
        case Bool: return new I64Value(operand1->i64Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() * operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() * operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() * operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() * operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() * operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui8Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui8Get() * operand2->f64Get(), true);
        case Bool: return new UI8Value(operand1->ui8Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() * operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() * operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() * operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() * operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() * operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui16Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui16Get() * operand2->f64Get(), true);
        case Bool: return new UI16Value(operand1->ui16Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() * operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() * operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() * operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() * operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() * operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui32Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui32Get() * operand2->f64Get(), true);
        case Bool: return new UI32Value(operand1->ui32Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() * operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() * operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() * operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() * operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() * operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() * operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->ui64Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui64Get() * operand2->f64Get(), true);
        case Bool: return new UI64Value(operand1->ui64Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() * operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() * operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() * operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() * operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() * operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() * operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() * operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() * operand2->iGet(), true);
        case Float32: return new F32Value(operand1->f64Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() * operand2->f64Get(), true);
        case Bool: return new IValue(operand1->iGet() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() * operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->f32Get() * operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->f32Get() * operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->f32Get() * operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->f32Get() * operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->f32Get() * operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->f32Get() * operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->f32Get() * operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->f32Get() * operand2->f32Get(), true);
        case Float32: return new F32Value(operand1->f32Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f32Get() * operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->f32Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->f32Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() * operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->f64Get() * operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->f64Get() * operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->f64Get() * operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->f64Get() * operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->f64Get() * operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->f64Get() * operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->f64Get() * operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->f64Get() * operand2->f64Get(), true);
        case Float32: return new F64Value(operand1->f64Get() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() * operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->f64Get() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->f64Get() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() * operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() * operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() * operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() * operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() * operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() * operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() * operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() * operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() * operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->bGet() * operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->bGet() * operand2->f64Get(), true);
        case Bool: return new BValue(operand1->bGet() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case Int8: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case Int16: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case Int32: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case Int64: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case UInt8: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case UInt16: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case UInt32: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case UInt64: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case Int: return new StrValue(operand1->strGet() * operand2->ui64Get(), true);
        case Var: return new VarValue(operand1->strGet() * operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() * operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() * operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() * operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() * operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() * operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() * operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() * operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() * operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() * operand2->iGet(), true);
        case Float32: return new VarValue(operand1->varGet() * operand2->f32Get(), true);
        case Float64: return new VarValue(operand1->varGet() * operand2->f64Get(), true);
        case Bool: return new VarValue(operand1->varGet() * operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() * operand2->varGet(), true);
        case String: return new VarValue(operand1->varGet() * operand2->strGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Int8: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case Int16: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case Int32: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case Int64: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case UInt8: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case UInt16: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case UInt32: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
        case UInt64: return new ArrValue(operand1->arrGet() * operand2->ui64Get(), true);
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
        case Int8: return new F32Value(operand1->i8Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->i8Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->i8Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->i8Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->i8Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->i8Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->i8Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->i8Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->i8Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->i8Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i8Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->i8Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->i16Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->i16Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->i16Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->i16Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->i16Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->i16Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->i16Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->i16Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->i16Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->i16Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i16Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->i16Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->i32Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->i32Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->i32Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->i32Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->i32Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->i32Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->i32Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->i32Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->i32Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->i32Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i32Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->i32Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->i64Get() / operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->i64Get() / operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->i64Get() / operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->i64Get() / operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->i64Get() / operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->i64Get() / operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->i64Get() / operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->i64Get() / operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->i64Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->i64Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->i64Get() / operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->i64Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->ui8Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->ui8Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->ui8Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->ui8Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->ui8Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->ui8Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->ui8Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->ui8Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->ui8Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->ui8Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui8Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->ui8Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->ui16Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->ui16Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->ui16Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->ui16Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->ui16Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->ui16Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->ui16Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->ui16Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->ui16Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->ui16Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui16Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->ui16Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->ui32Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->ui32Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->ui32Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->ui32Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->ui32Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->ui32Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->ui32Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->ui32Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->ui32Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->ui32Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui32Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->ui32Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->ui64Get() / operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->ui64Get() / operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->ui64Get() / operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->ui64Get() / operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->ui64Get() / operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->ui64Get() / operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->ui64Get() / operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->ui64Get() / operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->ui64Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->ui64Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->ui64Get() / operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->ui64Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() / operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->f64Get() / operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->f64Get() / operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->f64Get() / operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->f64Get() / operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->f64Get() / operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->f64Get() / operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->f64Get() / operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->f64Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->f64Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() / operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->f64Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->f64Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->f32Get() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->f32Get() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->f32Get() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->f32Get() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->f32Get() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->f32Get() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->f32Get() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->f32Get() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->f32Get() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->f32Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f32Get() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->f32Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->f32Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new F64Value(operand1->f64Get() / operand2->i8Get(), true);
        case Int16: return new F64Value(operand1->f64Get() / operand2->i16Get(), true);
        case Int32: return new F64Value(operand1->f64Get() / operand2->i32Get(), true);
        case Int64: return new F64Value(operand1->f64Get() / operand2->i64Get(), true);
        case UInt8: return new F64Value(operand1->f64Get() / operand2->ui8Get(), true);
        case UInt16: return new F64Value(operand1->f64Get() / operand2->ui16Get(), true);
        case UInt32: return new F64Value(operand1->f64Get() / operand2->ui32Get(), true);
        case UInt64: return new F64Value(operand1->f64Get() / operand2->ui64Get(), true);
        case Int: return new F64Value(operand1->f64Get() / operand2->f64Get(), true);
        case Float32: return new F64Value(operand1->f64Get() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->f64Get() / operand2->f64Get(), true);
        case Bool: return new F64Value(operand1->f64Get() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->f64Get() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new F32Value(operand1->bGet() / operand2->i8Get(), true);
        case Int16: return new F32Value(operand1->bGet() / operand2->i16Get(), true);
        case Int32: return new F32Value(operand1->bGet() / operand2->i32Get(), true);
        case Int64: return new F32Value(operand1->bGet() / operand2->i64Get(), true);
        case UInt8: return new F32Value(operand1->bGet() / operand2->ui8Get(), true);
        case UInt16: return new F32Value(operand1->bGet() / operand2->ui16Get(), true);
        case UInt32: return new F32Value(operand1->bGet() / operand2->ui32Get(), true);
        case UInt64: return new F32Value(operand1->bGet() / operand2->ui64Get(), true);
        case Int: return new F32Value(operand1->bGet() / operand2->f64Get(), true);
        case Float32: return new F32Value(operand1->bGet() / operand2->f32Get(), true);
        case Float64: return new F64Value(operand1->bGet() / operand2->f64Get(), true);
        case Bool: return new F32Value(operand1->bGet() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() / operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() / operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() / operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() / operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() / operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() / operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() / operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() / operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() / operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() / operand2->iGet(), true);
        case Float32: return new VarValue(operand1->varGet() / operand2->f32Get(), true);
        case Float64: return new VarValue(operand1->varGet() / operand2->f64Get(), true);
        case Bool: return new VarValue(operand1->varGet() / operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() / operand2->varGet(), true);
        case String: return new VarValue(operand1->varGet() / operand2->strGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() % operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() % operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() % operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() % operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() % operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() % operand2->iGet(), true);
        case Bool: return new I8Value(operand1->i8Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() % operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() % operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() % operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() % operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() % operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() % operand2->iGet(), true);
        case Bool: return new I16Value(operand1->i16Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() % operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() % operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() % operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() % operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() % operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() % operand2->iGet(), true);
        case Bool: return new I32Value(operand1->i32Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() % operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() % operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() % operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() % operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() % operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() % operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() % operand2->iGet(), true);
        case Bool: return new I64Value(operand1->i64Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() % operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() % operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() % operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() % operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() % operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() % operand2->iGet(), true);
        case Bool: return new UI8Value(operand1->ui8Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() % operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() % operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() % operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() % operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() % operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() % operand2->iGet(), true);
        case Bool: return new UI16Value(operand1->ui16Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() % operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() % operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() % operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() % operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() % operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() % operand2->iGet(), true);
        case Bool: return new UI32Value(operand1->ui32Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() % operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() % operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() % operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() % operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() % operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() % operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() % operand2->iGet(), true);
        case Bool: return new UI64Value(operand1->ui64Get() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() % operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() % operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() % operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() % operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() % operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() % operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() % operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() % operand2->iGet(), true);
        case Bool: return new IValue(operand1->iGet() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() % operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() % operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() % operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() % operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() % operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() % operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() % operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() % operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() % operand2->iGet(), true);
        case Bool: return new I8Value(operand1->bGet() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() % operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() % operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() % operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() % operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() % operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() % operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() % operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() % operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() % operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() % operand2->iGet(), true);
        case Bool: return new VarValue(operand1->varGet() % operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() % operand2->varGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() & operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() & operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() & operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() & operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() & operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() & operand2->iGet(), true);
        case Bool: return new I8Value(operand1->i8Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() & operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() & operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() & operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() & operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() & operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() & operand2->iGet(), true);
        case Bool: return new I16Value(operand1->i16Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() & operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() & operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() & operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() & operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() & operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() & operand2->iGet(), true);
        case Bool: return new I32Value(operand1->i32Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() & operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() & operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() & operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() & operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() & operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() & operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() & operand2->iGet(), true);
        case Bool: return new I64Value(operand1->i64Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() & operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() & operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() & operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() & operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() & operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() & operand2->iGet(), true);
        case Bool: return new UI8Value(operand1->ui8Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() & operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() & operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() & operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() & operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() & operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() & operand2->iGet(), true);
        case Bool: return new UI16Value(operand1->ui16Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() & operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() & operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() & operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() & operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() & operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() & operand2->iGet(), true);
        case Bool: return new UI32Value(operand1->ui32Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() & operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() & operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() & operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() & operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() & operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() & operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() & operand2->iGet(), true);
        case Bool: return new UI64Value(operand1->ui64Get() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() & operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() & operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() & operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() & operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() & operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() & operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() & operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() & operand2->iGet(), true);
        case Bool: return new IValue(operand1->iGet() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() & operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() & operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() & operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() & operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() & operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() & operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() & operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() & operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() & operand2->iGet(), true);
        case Bool: return new I8Value(operand1->bGet() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() & operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() & operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() & operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() & operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() & operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() & operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() & operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() & operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() & operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() & operand2->iGet(), true);
        case Bool: return new VarValue(operand1->varGet() & operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() & operand2->varGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() | operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() | operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() | operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() | operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() | operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() | operand2->iGet(), true);
        case Bool: return new I8Value(operand1->i8Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() | operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() | operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() | operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() | operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() | operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() | operand2->iGet(), true);
        case Bool: return new I16Value(operand1->i16Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() | operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() | operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() | operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() | operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() | operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() | operand2->iGet(), true);
        case Bool: return new I32Value(operand1->i32Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() | operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() | operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() | operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() | operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() | operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() | operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() | operand2->iGet(), true);
        case Bool: return new I64Value(operand1->i64Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() | operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() | operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() | operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() | operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() | operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() | operand2->iGet(), true);
        case Bool: return new UI8Value(operand1->ui8Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() | operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() | operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() | operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() | operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() | operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() | operand2->iGet(), true);
        case Bool: return new UI16Value(operand1->ui16Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() | operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() | operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() | operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() | operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() | operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() | operand2->iGet(), true);
        case Bool: return new UI32Value(operand1->ui32Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() | operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() | operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() | operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() | operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() | operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() | operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() | operand2->iGet(), true);
        case Bool: return new UI64Value(operand1->ui64Get() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() | operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() | operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() | operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() | operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() | operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() | operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() | operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() | operand2->iGet(), true);
        case Bool: return new IValue(operand1->iGet() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() | operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() | operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() | operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() | operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() | operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() | operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() | operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() | operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() | operand2->iGet(), true);
        case Bool: return new I8Value(operand1->bGet() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() | operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() | operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() | operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() | operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() | operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() | operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() | operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() | operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() | operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() | operand2->iGet(), true);
        case Bool: return new VarValue(operand1->varGet() | operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() | operand2->varGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() ^ operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() ^ operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() ^ operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() ^ operand2->iGet(), true);
        case Bool: return new I8Value(operand1->i8Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() ^ operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() ^ operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() ^ operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() ^ operand2->iGet(), true);
        case Bool: return new I16Value(operand1->i16Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() ^ operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() ^ operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() ^ operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() ^ operand2->iGet(), true);
        case Bool: return new I32Value(operand1->i32Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() ^ operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() ^ operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() ^ operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() ^ operand2->iGet(), true);
        case Bool: return new I64Value(operand1->i64Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() ^ operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() ^ operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() ^ operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() ^ operand2->iGet(), true);
        case Bool: return new UI8Value(operand1->ui8Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() ^ operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() ^ operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() ^ operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() ^ operand2->iGet(), true);
        case Bool: return new UI16Value(operand1->ui16Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() ^ operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() ^ operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() ^ operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() ^ operand2->iGet(), true);
        case Bool: return new UI32Value(operand1->ui32Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() ^ operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() ^ operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() ^ operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() ^ operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() ^ operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() ^ operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() ^ operand2->iGet(), true);
        case Bool: return new UI64Value(operand1->ui64Get() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() ^ operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() ^ operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() ^ operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() ^ operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() ^ operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() ^ operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() ^ operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() ^ operand2->iGet(), true);
        case Bool: return new IValue(operand1->iGet() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() ^ operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() ^ operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() ^ operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() ^ operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() ^ operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() ^ operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() ^ operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() ^ operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() ^ operand2->iGet(), true);
        case Bool: return new I8Value(operand1->bGet() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() ^ operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() ^ operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() ^ operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() ^ operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() ^ operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() ^ operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() ^ operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() ^ operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() ^ operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() ^ operand2->iGet(), true);
        case Bool: return new VarValue(operand1->varGet() ^ operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() ^ operand2->varGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() << operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() << operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() << operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() << operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() << operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() << operand2->iGet(), true);
        case Bool: return new I8Value(operand1->i8Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() << operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() << operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() << operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() << operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() << operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() << operand2->iGet(), true);
        case Bool: return new I16Value(operand1->i16Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() << operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() << operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() << operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() << operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() << operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() << operand2->iGet(), true);
        case Bool: return new I32Value(operand1->i32Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() << operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() << operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() << operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() << operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() << operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() << operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() << operand2->iGet(), true);
        case Bool: return new I64Value(operand1->i64Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() << operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() << operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() << operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() << operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() << operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() << operand2->iGet(), true);
        case Bool: return new UI8Value(operand1->ui8Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() << operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() << operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() << operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() << operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() << operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() << operand2->iGet(), true);
        case Bool: return new UI16Value(operand1->ui16Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() << operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() << operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() << operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() << operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() << operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() << operand2->iGet(), true);
        case Bool: return new UI32Value(operand1->ui32Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() << operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() << operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() << operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() << operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() << operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() << operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() << operand2->iGet(), true);
        case Bool: return new UI64Value(operand1->ui64Get() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() << operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() << operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() << operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() << operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() << operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() << operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() << operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() << operand2->iGet(), true);
        case Bool: return new IValue(operand1->iGet() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() << operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() << operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() << operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() << operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() << operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() << operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() << operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() << operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() << operand2->iGet(), true);
        case Bool: return new I8Value(operand1->bGet() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() << operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() << operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() << operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() << operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() << operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() << operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() << operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() << operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() << operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() << operand2->iGet(), true);
        case Bool: return new VarValue(operand1->varGet() << operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() << operand2->varGet(), true);
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
        case Int8: return new I8Value(operand1->i8Get() >> operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i8Get() >> operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i8Get() >> operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i8Get() >> operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->i8Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i8Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i8Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i8Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i8Get() >> operand2->iGet(), true);
        case Bool: return new I8Value(operand1->i8Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->i8Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new I16Value(operand1->i16Get() >> operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->i16Get() >> operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i16Get() >> operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i16Get() >> operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->i16Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->i16Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i16Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i16Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i16Get() >> operand2->iGet(), true);
        case Bool: return new I16Value(operand1->i16Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->i16Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new I32Value(operand1->i32Get() >> operand2->i8Get(), true);
        case Int16: return new I32Value(operand1->i32Get() >> operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->i32Get() >> operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i32Get() >> operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->i32Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->i32Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->i32Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i32Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i32Get() >> operand2->iGet(), true);
        case Bool: return new I32Value(operand1->i32Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->i32Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new I64Value(operand1->i64Get() >> operand2->i8Get(), true);
        case Int16: return new I64Value(operand1->i64Get() >> operand2->i16Get(), true);
        case Int32: return new I64Value(operand1->i64Get() >> operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->i64Get() >> operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->i64Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->i64Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->i64Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->i64Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->i64Get() >> operand2->iGet(), true);
        case Bool: return new I64Value(operand1->i64Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->i64Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new UI8Value(operand1->ui8Get() >> operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui8Get() >> operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui8Get() >> operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui8Get() >> operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->ui8Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui8Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui8Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui8Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui8Get() >> operand2->iGet(), true);
        case Bool: return new UI8Value(operand1->ui8Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui8Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new UI16Value(operand1->ui16Get() >> operand2->i8Get(), true);
        case Int16: return new UI16Value(operand1->ui16Get() >> operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui16Get() >> operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui16Get() >> operand2->i64Get(), true);
        case UInt8: return new UI16Value(operand1->ui16Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->ui16Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui16Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui16Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui16Get() >> operand2->iGet(), true);
        case Bool: return new UI16Value(operand1->ui16Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui16Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new UI32Value(operand1->ui32Get() >> operand2->i8Get(), true);
        case Int16: return new UI32Value(operand1->ui32Get() >> operand2->i16Get(), true);
        case Int32: return new UI32Value(operand1->ui32Get() >> operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui32Get() >> operand2->i64Get(), true);
        case UInt8: return new UI32Value(operand1->ui32Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI32Value(operand1->ui32Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->ui32Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui32Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui32Get() >> operand2->iGet(), true);
        case Bool: return new UI32Value(operand1->ui32Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui32Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new UI64Value(operand1->ui64Get() >> operand2->i8Get(), true);
        case Int16: return new UI64Value(operand1->ui64Get() >> operand2->i16Get(), true);
        case Int32: return new UI64Value(operand1->ui64Get() >> operand2->i32Get(), true);
        case Int64: return new UI64Value(operand1->ui64Get() >> operand2->i64Get(), true);
        case UInt8: return new UI64Value(operand1->ui64Get() >> operand2->ui8Get(), true);
        case UInt16: return new UI64Value(operand1->ui64Get() >> operand2->ui16Get(), true);
        case UInt32: return new UI64Value(operand1->ui64Get() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->ui64Get() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->ui64Get() >> operand2->iGet(), true);
        case Bool: return new UI64Value(operand1->ui64Get() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->ui64Get() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new IValue(operand1->iGet() >> operand2->i8Get(), true);
        case Int16: return new IValue(operand1->iGet() >> operand2->i16Get(), true);
        case Int32: return new IValue(operand1->iGet() >> operand2->i32Get(), true);
        case Int64: return new IValue(operand1->iGet() >> operand2->i64Get(), true);
        case UInt8: return new IValue(operand1->iGet() >> operand2->ui8Get(), true);
        case UInt16: return new IValue(operand1->iGet() >> operand2->ui16Get(), true);
        case UInt32: return new IValue(operand1->iGet() >> operand2->ui32Get(), true);
        case UInt64: return new IValue(operand1->iGet() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->iGet() >> operand2->iGet(), true);
        case Bool: return new IValue(operand1->iGet() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->iGet() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new I8Value(operand1->bGet() >> operand2->i8Get(), true);
        case Int16: return new I16Value(operand1->bGet() >> operand2->i16Get(), true);
        case Int32: return new I32Value(operand1->bGet() >> operand2->i32Get(), true);
        case Int64: return new I64Value(operand1->bGet() >> operand2->i64Get(), true);
        case UInt8: return new UI8Value(operand1->bGet() >> operand2->ui8Get(), true);
        case UInt16: return new UI16Value(operand1->bGet() >> operand2->ui16Get(), true);
        case UInt32: return new UI32Value(operand1->bGet() >> operand2->ui32Get(), true);
        case UInt64: return new UI64Value(operand1->bGet() >> operand2->ui64Get(), true);
        case Int: return new IValue(operand1->bGet() >> operand2->iGet(), true);
        case Bool: return new I8Value(operand1->bGet() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->bGet() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new VarValue(operand1->varGet() >> operand2->i8Get(), true);
        case Int16: return new VarValue(operand1->varGet() >> operand2->i16Get(), true);
        case Int32: return new VarValue(operand1->varGet() >> operand2->i32Get(), true);
        case Int64: return new VarValue(operand1->varGet() >> operand2->i64Get(), true);
        case UInt8: return new VarValue(operand1->varGet() >> operand2->ui8Get(), true);
        case UInt16: return new VarValue(operand1->varGet() >> operand2->ui16Get(), true);
        case UInt32: return new VarValue(operand1->varGet() >> operand2->ui32Get(), true);
        case UInt64: return new VarValue(operand1->varGet() >> operand2->ui64Get(), true);
        case Int: return new VarValue(operand1->varGet() >> operand2->iGet(), true);
        case Bool: return new VarValue(operand1->varGet() >> operand2->bGet(), true);
        case Var: return new VarValue(operand1->varGet() >> operand2->varGet(), true);
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

#endif