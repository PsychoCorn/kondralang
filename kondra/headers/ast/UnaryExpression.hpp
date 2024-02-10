#ifndef UnaryExpression_HPP
#define UnaryExpression_HPP

#include "Expression.hpp"
#include <stdexcept>
#include <string>

#define ERR_MSG_WRNG_UN_OP "Wrong unary operator"
#define ERR_MSG_WRNG_OPND "Wrong operand"

class UnaryExpression : public Expression
{
private:
    Expression* expr;
    std::string operation;

    Value *minus();
    Value *bitwiseNot();
    Value *logicalNot();
public:
    UnaryExpression(std::string, Expression*);
    ~UnaryExpression();
    Value *eval() override;
};

UnaryExpression::UnaryExpression(std::string operation, Expression* expr)
{
    this->operation = operation;
    this->expr = expr;
}

UnaryExpression::~UnaryExpression()
{
    delete expr;
}

Value *UnaryExpression::eval()
{
    if (operation == "+")
        return expr->eval();
    else if(operation == "-")
        return minus();
    else if(operation == "~")
        return bitwiseNot();
    else if(operation == "!")
        return logicalNot();
    throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
}

Value *UnaryExpression::minus()
{
    Value *operand = expr->eval();
    switch (operand->getType())
    {
    case Int8: return new I8Value(-operand->i8Get());
    case Int16: return new I16Value(-operand->i16Get());
    case Int32: return new I32Value(-operand->i32Get());
    case Int64: return new I64Value(-operand->i64Get());
    case UInt8: return new I8Value(-operand->ui8Get());
    case UInt16: return new I16Value(-operand->ui16Get());
    case UInt32: return new I32Value(-operand->ui32Get());
    case UInt64: return new I64Value(-operand->ui64Get());
    case Int: return new IValue(-operand->iGet());
    case Float32: return new F32Value(-operand->f32Get());
    case Float64: return new F64Value(-operand->f64Get());
    case Float80: return new F80Value(-operand->f80Get());
    case Bool: return new I8Value(-operand->bGet());
    case Var: return new VarValue(-operand->varGet());
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
}

Value *UnaryExpression::bitwiseNot()
{
    Value *operand = expr->eval();
    switch (operand->getType())
    {
    case Int8: return new I8Value(~operand->i8Get());
    case Int16: return new I16Value(~operand->i16Get());
    case Int32: return new I32Value(~operand->i32Get());
    case Int64: return new I64Value(~operand->i64Get());
    case UInt8: return new I8Value(~operand->ui8Get());
    case UInt16: return new I16Value(~operand->ui16Get());
    case UInt32: return new I32Value(~operand->ui32Get());
    case UInt64: return new I64Value(~operand->ui64Get());
    case Int: return new IValue(~operand->iGet());
    case Bool: return new I8Value(~operand->bGet());
    case Var: return new VarValue(~operand->varGet());
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
}

Value *UnaryExpression::logicalNot()
{
    Value *operand = expr->eval();
    switch (operand->getType())
    {
    case Int8: return new I8Value(!operand->i8Get());
    case Int16: return new I16Value(!operand->i16Get());
    case Int32: return new I32Value(!operand->i32Get());
    case Int64: return new I64Value(!operand->i64Get());
    case UInt8: return new I8Value(!operand->ui8Get());
    case UInt16: return new I16Value(!operand->ui16Get());
    case UInt32: return new I32Value(!operand->ui32Get());
    case UInt64: return new I64Value(!operand->ui64Get());
    case Int: return new IValue(!operand->iGet());
    case Bool: return new I8Value(!operand->bGet());
    case Var: return new VarValue(!operand->varGet());
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
}

#endif