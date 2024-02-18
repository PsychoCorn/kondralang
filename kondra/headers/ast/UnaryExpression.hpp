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
    TokenType operation;

    Value *minus();
    Value *bitwiseNot();
    Value *logicalNot();
public:
    UnaryExpression(TokenType, Expression*);
    ~UnaryExpression();
    Value *eval() override;
};

UnaryExpression::UnaryExpression(TokenType operation, Expression* expr)
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
    switch (operation)
    {
    case TokenType::Plus: return expr->eval();
    case TokenType::Minus: return minus();
    case TokenType::Tilde: return bitwiseNot();
    case TokenType::Exclamation: return logicalNot();
    default:
        throw std::runtime_error(ERR_MSG_WRNG_UN_OP);
    }
}

Value *UnaryExpression::minus()
{
    Value *operand = expr->eval();
    switch (operand->getType())
    {
    case Int8: return new I8Value(-operand->i8Get(), true);
    case Int16: return new I16Value(-operand->i16Get(), true);
    case Int32: return new I32Value(-operand->i32Get(), true);
    case Int64: return new I64Value(-operand->i64Get(), true);
    case UInt8: return new I8Value(-operand->ui8Get(), true);
    case UInt16: return new I16Value(-operand->ui16Get(), true);
    case UInt32: return new I32Value(-operand->ui32Get(), true);
    case UInt64: return new I64Value(-operand->ui64Get(), true);
    case Int: return new IValue(-operand->iGet(), true);
    case Float32: return new F32Value(-operand->f32Get(), true);
    case Float64: return new F64Value(-operand->f64Get(), true);
    case Bool: return new I8Value(-operand->bGet(), true);
    case Var: return new VarValue(-operand->varGet(), true);
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
}

Value *UnaryExpression::bitwiseNot()
{
    Value *operand = expr->eval();
    switch (operand->getType())
    {
    case Int8: return new I8Value(~operand->i8Get(), true);
    case Int16: return new I16Value(~operand->i16Get(), true);
    case Int32: return new I32Value(~operand->i32Get(), true);
    case Int64: return new I64Value(~operand->i64Get(), true);
    case UInt8: return new I8Value(~operand->ui8Get(), true);
    case UInt16: return new I16Value(~operand->ui16Get(), true);
    case UInt32: return new I32Value(~operand->ui32Get(), true);
    case UInt64: return new I64Value(~operand->ui64Get(), true);
    case Int: return new IValue(~operand->iGet(), true);
    case Bool: return new I8Value(~operand->bGet(), true);
    case Var: return new VarValue(~operand->varGet(), true);
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
}

Value *UnaryExpression::logicalNot()
{
    Value *operand = expr->eval();
    switch (operand->getType())
    {
    case Int8: return new BValue(!operand->i8Get(), true);
    case Int16: return new BValue(!operand->i16Get(), true);
    case Int32: return new BValue(!operand->i32Get(), true);
    case Int64: return new BValue(!operand->i64Get(), true);
    case UInt8: return new BValue(!operand->ui8Get(), true);
    case UInt16: return new BValue(!operand->ui16Get(), true);
    case UInt32: return new BValue(!operand->ui32Get(), true);
    case UInt64: return new BValue(!operand->ui64Get(), true);
    case Int: return new BValue(!operand->iGet(), true);
    case Bool: return new BValue(!operand->bGet(), true);
    case Var: return new BValue(!operand->varGet(), true);
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
}

#endif