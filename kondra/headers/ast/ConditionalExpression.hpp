#ifndef ConditionalExpression_HPP
#define ConditionalExpression_HPP

#include "Expression.hpp"
#include <string>
#include <stdexcept>

#define ERR_MSG_WRNG_COND_OP "Wrong conditional operator"
#define ERR_MSG_WRNG_OPNDS "Wrong operands"

class ConditionalExpression : public Expression
{
private:
    Expression* expr1;
    Expression* expr2;
    std::string operation;

    Value *eq();
    Value *lt();
    Value *gt();
    Value *leq();
    Value *geq();
    Value *neq();
    Value *logicalAnd();
    Value *logicalOr();
public:
    ConditionalExpression(std::string, Expression*, Expression*);
    ~ConditionalExpression();
    Value *eval() override;
};

ConditionalExpression::ConditionalExpression(std::string operation, Expression* expr1, Expression* expr2)
{
    this->operation = operation;
    this->expr1 = expr1;
    this->expr2 = expr2;
}

ConditionalExpression::~ConditionalExpression()
{
    delete expr1, expr2;
}

Value *ConditionalExpression::eval()
{
    if (operation == "==")
        return eq();
    else if (operation == "<")
        return lt();
    else if (operation == ">")
        return gt();
    else if (operation == "<=")
        return leq();
    else if (operation == ">=")
        return geq();
    else if (operation == "!=")
        return neq();
    else if (operation == "&&")
        return logicalAnd();
    else if (operation == "||")
        return logicalOr();
    throw std::runtime_error(ERR_MSG_WRNG_COND_OP);
}

Value *ConditionalExpression::logicalAnd()
{
    return new BValue(expr1->eval()->bGet() && expr2->eval()->bGet());
}

Value *ConditionalExpression::logicalOr()
{
    return new BValue(expr1->eval()->bGet() || expr2->eval()->bGet());
}

Value *ConditionalExpression::eq()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i8Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->i8Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->i8Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->i8Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->i8Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->i8Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->i8Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->i8Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->i8Get() == operand2->iGet());
        case Float32: return new BValue(operand1->i8Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->i8Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->i8Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->i8Get() == operand2->bGet());
        case Var: return new BValue(operand1->i8Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i16Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->i16Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->i16Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->i16Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->i16Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->i16Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->i16Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->i16Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->i16Get() == operand2->iGet());
        case Float32: return new BValue(operand1->i16Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->i16Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->i16Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->i16Get() == operand2->bGet());
        case Var: return new BValue(operand1->i16Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i32Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->i32Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->i32Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->i32Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->i32Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->i32Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->i32Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->i32Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->i32Get() == operand2->iGet());
        case Float32: return new BValue(operand1->i32Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->i32Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->i32Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->i32Get() == operand2->bGet());
        case Var: return new BValue(operand1->i32Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i64Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->i64Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->i64Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->i64Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->i64Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->i64Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->i64Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->i64Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->i64Get() == operand2->iGet());
        case Float32: return new BValue(operand1->i64Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->i64Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->i64Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->i64Get() == operand2->bGet());
        case Var: return new BValue(operand1->i64Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui8Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->ui8Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->ui8Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->ui8Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->ui8Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui8Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui8Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui8Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->ui8Get() == operand2->iGet());
        case Float32: return new BValue(operand1->ui8Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->ui8Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->ui8Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->ui8Get() == operand2->bGet());
        case Var: return new BValue(operand1->ui8Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui16Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->ui16Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->ui16Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->ui16Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->ui16Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui16Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui16Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui16Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->ui16Get() == operand2->iGet());
        case Float32: return new BValue(operand1->ui16Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->ui16Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->ui16Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->ui16Get() == operand2->bGet());
        case Var: return new BValue(operand1->ui16Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui32Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->ui32Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->ui32Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->ui32Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->ui32Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui32Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui32Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui32Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->ui32Get() == operand2->iGet());
        case Float32: return new BValue(operand1->ui32Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->ui32Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->ui32Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->ui32Get() == operand2->bGet());
        case Var: return new BValue(operand1->ui32Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui64Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->ui64Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->ui64Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->ui64Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->ui64Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui64Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui64Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui64Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->ui64Get() == operand2->iGet());
        case Float32: return new BValue(operand1->ui64Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->ui64Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->ui64Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->ui64Get() == operand2->bGet());
        case Var: return new BValue(operand1->ui64Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->iGet() == operand2->i8Get());
        case Int16: return new BValue(operand1->iGet() == operand2->i16Get());
        case Int32: return new BValue(operand1->iGet() == operand2->i32Get());
        case Int64: return new BValue(operand1->iGet() == operand2->i64Get());
        case UInt8: return new BValue(operand1->iGet() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->iGet() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->iGet() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->iGet() == operand2->ui64Get());
        case Int: return new BValue(operand1->iGet() == operand2->iGet());
        case Float32: return new BValue(operand1->iGet() == operand2->f32Get());
        case Float64: return new BValue(operand1->iGet() == operand2->f64Get());
        case Float80: return new BValue(operand1->iGet() == operand2->f80Get());
        case Bool: return new BValue(operand1->iGet() == operand2->bGet());
        case Var: return new BValue(operand1->iGet() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f32Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->f32Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->f32Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->f32Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->f32Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->f32Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->f32Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->f32Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->f32Get() == operand2->f32Get());
        case Float32: return new BValue(operand1->f32Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->f32Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->f32Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->f32Get() == operand2->bGet());
        case Var: return new BValue(operand1->f32Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f64Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->f64Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->f64Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->f64Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->f64Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->f64Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->f64Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->f64Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->f64Get() == operand2->f64Get());
        case Float32: return new BValue(operand1->f64Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->f64Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->f64Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->f64Get() == operand2->bGet());
        case Var: return new BValue(operand1->f64Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f80Get() == operand2->i8Get());
        case Int16: return new BValue(operand1->f80Get() == operand2->i16Get());
        case Int32: return new BValue(operand1->f80Get() == operand2->i32Get());
        case Int64: return new BValue(operand1->f80Get() == operand2->i64Get());
        case UInt8: return new BValue(operand1->f80Get() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->f80Get() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->f80Get() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->f80Get() == operand2->ui64Get());
        case Int: return new BValue(operand1->f80Get() == operand2->f64Get());
        case Float32: return new BValue(operand1->f80Get() == operand2->f32Get());
        case Float64: return new BValue(operand1->f80Get() == operand2->f64Get());
        case Float80: return new BValue(operand1->f80Get() == operand2->f80Get());
        case Bool: return new BValue(operand1->f80Get() == operand2->bGet());
        case Var: return new BValue(operand1->f80Get() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->bGet() == operand2->i8Get());
        case Int16: return new BValue(operand1->bGet() == operand2->i16Get());
        case Int32: return new BValue(operand1->bGet() == operand2->i32Get());
        case Int64: return new BValue(operand1->bGet() == operand2->i64Get());
        case UInt8: return new BValue(operand1->bGet() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->bGet() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->bGet() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->bGet() == operand2->ui64Get());
        case Int: return new BValue(operand1->bGet() == operand2->f64Get());
        case Float32: return new BValue(operand1->bGet() == operand2->f32Get());
        case Float64: return new BValue(operand1->bGet() == operand2->f64Get());
        case Float80: return new BValue(operand1->bGet() == operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() == operand2->bGet());
        case Var: return new BValue(operand1->bGet() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new BValue(operand1->strGet() == operand2->strGet());
        case Var: return new BValue(operand1->strGet() == operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->varGet() == operand2->i8Get());
        case Int16: return new BValue(operand1->varGet() == operand2->i16Get());
        case Int32: return new BValue(operand1->varGet() == operand2->i32Get());
        case Int64: return new BValue(operand1->varGet() == operand2->i64Get());
        case UInt8: return new BValue(operand1->varGet() == operand2->ui8Get());
        case UInt16: return new BValue(operand1->varGet() == operand2->ui16Get());
        case UInt32: return new BValue(operand1->varGet() == operand2->ui32Get());
        case UInt64: return new BValue(operand1->varGet() == operand2->ui64Get());
        case Int: return new BValue(operand1->varGet() == operand2->iGet());
        case Float32: return new BValue(operand1->varGet() == operand2->f32Get());
        case Float64: return new BValue(operand1->varGet() == operand2->f64Get());
        case Float80: return new BValue(operand1->varGet() == operand2->f80Get());
        case Bool: return new BValue(operand1->varGet() == operand2->bGet());
        case Var: return new BValue(operand1->varGet() == operand2->varGet());
        case String: return new BValue(operand1->varGet() == operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new BValue(operand1->arrGet() == operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *ConditionalExpression::lt()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i8Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->i8Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->i8Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->i8Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->i8Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->i8Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->i8Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->i8Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->i8Get() < operand2->iGet());
        case Float32: return new BValue(operand1->i8Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->i8Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->i8Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->i8Get() < operand2->bGet());
        case Var: return new BValue(operand1->i8Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i16Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->i16Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->i16Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->i16Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->i16Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->i16Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->i16Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->i16Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->i16Get() < operand2->iGet());
        case Float32: return new BValue(operand1->i16Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->i16Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->i16Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->i16Get() < operand2->bGet());
        case Var: return new BValue(operand1->i16Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i32Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->i32Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->i32Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->i32Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->i32Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->i32Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->i32Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->i32Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->i32Get() < operand2->iGet());
        case Float32: return new BValue(operand1->i32Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->i32Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->i32Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->i32Get() < operand2->bGet());
        case Var: return new BValue(operand1->i32Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i64Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->i64Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->i64Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->i64Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->i64Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->i64Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->i64Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->i64Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->i64Get() < operand2->iGet());
        case Float32: return new BValue(operand1->i64Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->i64Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->i64Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->i64Get() < operand2->bGet());
        case Var: return new BValue(operand1->i64Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui8Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->ui8Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->ui8Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->ui8Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->ui8Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui8Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui8Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui8Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->ui8Get() < operand2->iGet());
        case Float32: return new BValue(operand1->ui8Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->ui8Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->ui8Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->ui8Get() < operand2->bGet());
        case Var: return new BValue(operand1->ui8Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui16Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->ui16Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->ui16Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->ui16Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->ui16Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui16Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui16Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui16Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->ui16Get() < operand2->iGet());
        case Float32: return new BValue(operand1->ui16Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->ui16Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->ui16Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->ui16Get() < operand2->bGet());
        case Var: return new BValue(operand1->ui16Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui32Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->ui32Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->ui32Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->ui32Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->ui32Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui32Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui32Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui32Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->ui32Get() < operand2->iGet());
        case Float32: return new BValue(operand1->ui32Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->ui32Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->ui32Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->ui32Get() < operand2->bGet());
        case Var: return new BValue(operand1->ui32Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui64Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->ui64Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->ui64Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->ui64Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->ui64Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui64Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui64Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui64Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->ui64Get() < operand2->iGet());
        case Float32: return new BValue(operand1->ui64Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->ui64Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->ui64Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->ui64Get() < operand2->bGet());
        case Var: return new BValue(operand1->ui64Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->iGet() < operand2->i8Get());
        case Int16: return new BValue(operand1->iGet() < operand2->i16Get());
        case Int32: return new BValue(operand1->iGet() < operand2->i32Get());
        case Int64: return new BValue(operand1->iGet() < operand2->i64Get());
        case UInt8: return new BValue(operand1->iGet() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->iGet() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->iGet() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->iGet() < operand2->ui64Get());
        case Int: return new BValue(operand1->iGet() < operand2->iGet());
        case Float32: return new BValue(operand1->iGet() < operand2->f32Get());
        case Float64: return new BValue(operand1->iGet() < operand2->f64Get());
        case Float80: return new BValue(operand1->iGet() < operand2->f80Get());
        case Bool: return new BValue(operand1->iGet() < operand2->bGet());
        case Var: return new BValue(operand1->iGet() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f32Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->f32Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->f32Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->f32Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->f32Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->f32Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->f32Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->f32Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->f32Get() < operand2->f32Get());
        case Float32: return new BValue(operand1->f32Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->f32Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->f32Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->f32Get() < operand2->bGet());
        case Var: return new BValue(operand1->f32Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f64Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->f64Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->f64Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->f64Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->f64Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->f64Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->f64Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->f64Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->f64Get() < operand2->f64Get());
        case Float32: return new BValue(operand1->f64Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->f64Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->f64Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->f64Get() < operand2->bGet());
        case Var: return new BValue(operand1->f64Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f80Get() < operand2->i8Get());
        case Int16: return new BValue(operand1->f80Get() < operand2->i16Get());
        case Int32: return new BValue(operand1->f80Get() < operand2->i32Get());
        case Int64: return new BValue(operand1->f80Get() < operand2->i64Get());
        case UInt8: return new BValue(operand1->f80Get() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->f80Get() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->f80Get() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->f80Get() < operand2->ui64Get());
        case Int: return new BValue(operand1->f80Get() < operand2->f64Get());
        case Float32: return new BValue(operand1->f80Get() < operand2->f32Get());
        case Float64: return new BValue(operand1->f80Get() < operand2->f64Get());
        case Float80: return new BValue(operand1->f80Get() < operand2->f80Get());
        case Bool: return new BValue(operand1->f80Get() < operand2->bGet());
        case Var: return new BValue(operand1->f80Get() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->bGet() < operand2->i8Get());
        case Int16: return new BValue(operand1->bGet() < operand2->i16Get());
        case Int32: return new BValue(operand1->bGet() < operand2->i32Get());
        case Int64: return new BValue(operand1->bGet() < operand2->i64Get());
        case UInt8: return new BValue(operand1->bGet() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->bGet() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->bGet() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->bGet() < operand2->ui64Get());
        case Int: return new BValue(operand1->bGet() < operand2->f64Get());
        case Float32: return new BValue(operand1->bGet() < operand2->f32Get());
        case Float64: return new BValue(operand1->bGet() < operand2->f64Get());
        case Float80: return new BValue(operand1->bGet() < operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() < operand2->bGet());
        case Var: return new BValue(operand1->bGet() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new BValue(operand1->strGet() < operand2->strGet());
        case Var: return new BValue(operand1->strGet() < operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->varGet() < operand2->i8Get());
        case Int16: return new BValue(operand1->varGet() < operand2->i16Get());
        case Int32: return new BValue(operand1->varGet() < operand2->i32Get());
        case Int64: return new BValue(operand1->varGet() < operand2->i64Get());
        case UInt8: return new BValue(operand1->varGet() < operand2->ui8Get());
        case UInt16: return new BValue(operand1->varGet() < operand2->ui16Get());
        case UInt32: return new BValue(operand1->varGet() < operand2->ui32Get());
        case UInt64: return new BValue(operand1->varGet() < operand2->ui64Get());
        case Int: return new BValue(operand1->varGet() < operand2->iGet());
        case Float32: return new BValue(operand1->varGet() < operand2->f32Get());
        case Float64: return new BValue(operand1->varGet() < operand2->f64Get());
        case Float80: return new BValue(operand1->varGet() < operand2->f80Get());
        case Bool: return new BValue(operand1->varGet() < operand2->bGet());
        case Var: return new BValue(operand1->varGet() < operand2->varGet());
        case String: return new BValue(operand1->varGet() < operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new BValue(operand1->arrGet() < operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *ConditionalExpression::gt()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i8Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->i8Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->i8Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->i8Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->i8Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->i8Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->i8Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->i8Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->i8Get() > operand2->iGet());
        case Float32: return new BValue(operand1->i8Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->i8Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->i8Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->i8Get() > operand2->bGet());
        case Var: return new BValue(operand1->i8Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i16Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->i16Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->i16Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->i16Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->i16Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->i16Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->i16Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->i16Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->i16Get() > operand2->iGet());
        case Float32: return new BValue(operand1->i16Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->i16Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->i16Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->i16Get() > operand2->bGet());
        case Var: return new BValue(operand1->i16Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i32Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->i32Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->i32Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->i32Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->i32Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->i32Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->i32Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->i32Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->i32Get() > operand2->iGet());
        case Float32: return new BValue(operand1->i32Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->i32Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->i32Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->i32Get() > operand2->bGet());
        case Var: return new BValue(operand1->i32Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i64Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->i64Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->i64Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->i64Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->i64Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->i64Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->i64Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->i64Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->i64Get() > operand2->iGet());
        case Float32: return new BValue(operand1->i64Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->i64Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->i64Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->i64Get() > operand2->bGet());
        case Var: return new BValue(operand1->i64Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui8Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->ui8Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->ui8Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->ui8Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->ui8Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui8Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui8Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui8Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->ui8Get() > operand2->iGet());
        case Float32: return new BValue(operand1->ui8Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->ui8Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->ui8Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->ui8Get() > operand2->bGet());
        case Var: return new BValue(operand1->ui8Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui16Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->ui16Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->ui16Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->ui16Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->ui16Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui16Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui16Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui16Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->ui16Get() > operand2->iGet());
        case Float32: return new BValue(operand1->ui16Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->ui16Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->ui16Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->ui16Get() > operand2->bGet());
        case Var: return new BValue(operand1->ui16Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui32Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->ui32Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->ui32Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->ui32Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->ui32Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui32Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui32Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui32Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->ui32Get() > operand2->iGet());
        case Float32: return new BValue(operand1->ui32Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->ui32Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->ui32Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->ui32Get() > operand2->bGet());
        case Var: return new BValue(operand1->ui32Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui64Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->ui64Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->ui64Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->ui64Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->ui64Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui64Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui64Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui64Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->ui64Get() > operand2->iGet());
        case Float32: return new BValue(operand1->ui64Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->ui64Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->ui64Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->ui64Get() > operand2->bGet());
        case Var: return new BValue(operand1->ui64Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->iGet() > operand2->i8Get());
        case Int16: return new BValue(operand1->iGet() > operand2->i16Get());
        case Int32: return new BValue(operand1->iGet() > operand2->i32Get());
        case Int64: return new BValue(operand1->iGet() > operand2->i64Get());
        case UInt8: return new BValue(operand1->iGet() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->iGet() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->iGet() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->iGet() > operand2->ui64Get());
        case Int: return new BValue(operand1->iGet() > operand2->iGet());
        case Float32: return new BValue(operand1->iGet() > operand2->f32Get());
        case Float64: return new BValue(operand1->iGet() > operand2->f64Get());
        case Float80: return new BValue(operand1->iGet() > operand2->f80Get());
        case Bool: return new BValue(operand1->iGet() > operand2->bGet());
        case Var: return new BValue(operand1->iGet() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f32Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->f32Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->f32Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->f32Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->f32Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->f32Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->f32Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->f32Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->f32Get() > operand2->f32Get());
        case Float32: return new BValue(operand1->f32Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->f32Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->f32Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->f32Get() > operand2->bGet());
        case Var: return new BValue(operand1->f32Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f64Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->f64Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->f64Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->f64Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->f64Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->f64Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->f64Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->f64Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->f64Get() > operand2->f64Get());
        case Float32: return new BValue(operand1->f64Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->f64Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->f64Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->f64Get() > operand2->bGet());
        case Var: return new BValue(operand1->f64Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f80Get() > operand2->i8Get());
        case Int16: return new BValue(operand1->f80Get() > operand2->i16Get());
        case Int32: return new BValue(operand1->f80Get() > operand2->i32Get());
        case Int64: return new BValue(operand1->f80Get() > operand2->i64Get());
        case UInt8: return new BValue(operand1->f80Get() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->f80Get() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->f80Get() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->f80Get() > operand2->ui64Get());
        case Int: return new BValue(operand1->f80Get() > operand2->f64Get());
        case Float32: return new BValue(operand1->f80Get() > operand2->f32Get());
        case Float64: return new BValue(operand1->f80Get() > operand2->f64Get());
        case Float80: return new BValue(operand1->f80Get() > operand2->f80Get());
        case Bool: return new BValue(operand1->f80Get() > operand2->bGet());
        case Var: return new BValue(operand1->f80Get() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->bGet() > operand2->i8Get());
        case Int16: return new BValue(operand1->bGet() > operand2->i16Get());
        case Int32: return new BValue(operand1->bGet() > operand2->i32Get());
        case Int64: return new BValue(operand1->bGet() > operand2->i64Get());
        case UInt8: return new BValue(operand1->bGet() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->bGet() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->bGet() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->bGet() > operand2->ui64Get());
        case Int: return new BValue(operand1->bGet() > operand2->f64Get());
        case Float32: return new BValue(operand1->bGet() > operand2->f32Get());
        case Float64: return new BValue(operand1->bGet() > operand2->f64Get());
        case Float80: return new BValue(operand1->bGet() > operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() > operand2->bGet());
        case Var: return new BValue(operand1->bGet() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new BValue(operand1->strGet() > operand2->strGet());
        case Var: return new BValue(operand1->strGet() > operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->varGet() > operand2->i8Get());
        case Int16: return new BValue(operand1->varGet() > operand2->i16Get());
        case Int32: return new BValue(operand1->varGet() > operand2->i32Get());
        case Int64: return new BValue(operand1->varGet() > operand2->i64Get());
        case UInt8: return new BValue(operand1->varGet() > operand2->ui8Get());
        case UInt16: return new BValue(operand1->varGet() > operand2->ui16Get());
        case UInt32: return new BValue(operand1->varGet() > operand2->ui32Get());
        case UInt64: return new BValue(operand1->varGet() > operand2->ui64Get());
        case Int: return new BValue(operand1->varGet() > operand2->iGet());
        case Float32: return new BValue(operand1->varGet() > operand2->f32Get());
        case Float64: return new BValue(operand1->varGet() > operand2->f64Get());
        case Float80: return new BValue(operand1->varGet() > operand2->f80Get());
        case Bool: return new BValue(operand1->varGet() > operand2->bGet());
        case Var: return new BValue(operand1->varGet() > operand2->varGet());
        case String: return new BValue(operand1->varGet() > operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new BValue(operand1->arrGet() > operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *ConditionalExpression::leq()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i8Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->i8Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->i8Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->i8Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->i8Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i8Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i8Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i8Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->i8Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->i8Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->i8Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->i8Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->i8Get() <= operand2->bGet());
        case Var: return new BValue(operand1->i8Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i16Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->i16Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->i16Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->i16Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->i16Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i16Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i16Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i16Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->i16Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->i16Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->i16Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->i16Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->i16Get() <= operand2->bGet());
        case Var: return new BValue(operand1->i16Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i32Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->i32Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->i32Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->i32Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->i32Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i32Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i32Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i32Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->i32Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->i32Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->i32Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->i32Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->i32Get() <= operand2->bGet());
        case Var: return new BValue(operand1->i32Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i64Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->i64Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->i64Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->i64Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->i64Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i64Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i64Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i64Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->i64Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->i64Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->i64Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->i64Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->i64Get() <= operand2->bGet());
        case Var: return new BValue(operand1->i64Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui8Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->ui8Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->ui8Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->ui8Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui8Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui8Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui8Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui8Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->ui8Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->ui8Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->ui8Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->ui8Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->ui8Get() <= operand2->bGet());
        case Var: return new BValue(operand1->ui8Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui16Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->ui16Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->ui16Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->ui16Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui16Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui16Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui16Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui16Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->ui16Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->ui16Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->ui16Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->ui16Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->ui16Get() <= operand2->bGet());
        case Var: return new BValue(operand1->ui16Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui32Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->ui32Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->ui32Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->ui32Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui32Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui32Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui32Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui32Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->ui32Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->ui32Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->ui32Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->ui32Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->ui32Get() <= operand2->bGet());
        case Var: return new BValue(operand1->ui32Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui64Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->ui64Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->ui64Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->ui64Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui64Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui64Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui64Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui64Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->ui64Get() <= operand2->iGet());
        case Float32: return new BValue(operand1->ui64Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->ui64Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->ui64Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->ui64Get() <= operand2->bGet());
        case Var: return new BValue(operand1->ui64Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->iGet() <= operand2->i8Get());
        case Int16: return new BValue(operand1->iGet() <= operand2->i16Get());
        case Int32: return new BValue(operand1->iGet() <= operand2->i32Get());
        case Int64: return new BValue(operand1->iGet() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->iGet() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->iGet() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->iGet() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->iGet() <= operand2->ui64Get());
        case Int: return new BValue(operand1->iGet() <= operand2->iGet());
        case Float32: return new BValue(operand1->iGet() <= operand2->f32Get());
        case Float64: return new BValue(operand1->iGet() <= operand2->f64Get());
        case Float80: return new BValue(operand1->iGet() <= operand2->f80Get());
        case Bool: return new BValue(operand1->iGet() <= operand2->bGet());
        case Var: return new BValue(operand1->iGet() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f32Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->f32Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->f32Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->f32Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->f32Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->f32Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->f32Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->f32Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->f32Get() <= operand2->f32Get());
        case Float32: return new BValue(operand1->f32Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->f32Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->f32Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->f32Get() <= operand2->bGet());
        case Var: return new BValue(operand1->f32Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f64Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->f64Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->f64Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->f64Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->f64Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->f64Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->f64Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->f64Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->f64Get() <= operand2->f64Get());
        case Float32: return new BValue(operand1->f64Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->f64Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->f64Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->f64Get() <= operand2->bGet());
        case Var: return new BValue(operand1->f64Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f80Get() <= operand2->i8Get());
        case Int16: return new BValue(operand1->f80Get() <= operand2->i16Get());
        case Int32: return new BValue(operand1->f80Get() <= operand2->i32Get());
        case Int64: return new BValue(operand1->f80Get() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->f80Get() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->f80Get() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->f80Get() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->f80Get() <= operand2->ui64Get());
        case Int: return new BValue(operand1->f80Get() <= operand2->f64Get());
        case Float32: return new BValue(operand1->f80Get() <= operand2->f32Get());
        case Float64: return new BValue(operand1->f80Get() <= operand2->f64Get());
        case Float80: return new BValue(operand1->f80Get() <= operand2->f80Get());
        case Bool: return new BValue(operand1->f80Get() <= operand2->bGet());
        case Var: return new BValue(operand1->f80Get() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->bGet() <= operand2->i8Get());
        case Int16: return new BValue(operand1->bGet() <= operand2->i16Get());
        case Int32: return new BValue(operand1->bGet() <= operand2->i32Get());
        case Int64: return new BValue(operand1->bGet() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->bGet() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->bGet() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->bGet() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->bGet() <= operand2->ui64Get());
        case Int: return new BValue(operand1->bGet() <= operand2->f64Get());
        case Float32: return new BValue(operand1->bGet() <= operand2->f32Get());
        case Float64: return new BValue(operand1->bGet() <= operand2->f64Get());
        case Float80: return new BValue(operand1->bGet() <= operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() <= operand2->bGet());
        case Var: return new BValue(operand1->bGet() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new BValue(operand1->strGet() <= operand2->strGet());
        case Var: return new BValue(operand1->strGet() <= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->varGet() <= operand2->i8Get());
        case Int16: return new BValue(operand1->varGet() <= operand2->i16Get());
        case Int32: return new BValue(operand1->varGet() <= operand2->i32Get());
        case Int64: return new BValue(operand1->varGet() <= operand2->i64Get());
        case UInt8: return new BValue(operand1->varGet() <= operand2->ui8Get());
        case UInt16: return new BValue(operand1->varGet() <= operand2->ui16Get());
        case UInt32: return new BValue(operand1->varGet() <= operand2->ui32Get());
        case UInt64: return new BValue(operand1->varGet() <= operand2->ui64Get());
        case Int: return new BValue(operand1->varGet() <= operand2->iGet());
        case Float32: return new BValue(operand1->varGet() <= operand2->f32Get());
        case Float64: return new BValue(operand1->varGet() <= operand2->f64Get());
        case Float80: return new BValue(operand1->varGet() <= operand2->f80Get());
        case Bool: return new BValue(operand1->varGet() <= operand2->bGet());
        case Var: return new BValue(operand1->varGet() <= operand2->varGet());
        case String: return new BValue(operand1->varGet() <= operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new BValue(operand1->arrGet() <= operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *ConditionalExpression::geq()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i8Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->i8Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->i8Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->i8Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->i8Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i8Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i8Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i8Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->i8Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->i8Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->i8Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->i8Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->i8Get() >= operand2->bGet());
        case Var: return new BValue(operand1->i8Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i16Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->i16Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->i16Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->i16Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->i16Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i16Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i16Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i16Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->i16Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->i16Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->i16Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->i16Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->i16Get() >= operand2->bGet());
        case Var: return new BValue(operand1->i16Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i32Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->i32Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->i32Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->i32Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->i32Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i32Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i32Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i32Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->i32Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->i32Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->i32Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->i32Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->i32Get() >= operand2->bGet());
        case Var: return new BValue(operand1->i32Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i64Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->i64Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->i64Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->i64Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->i64Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->i64Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->i64Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->i64Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->i64Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->i64Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->i64Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->i64Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->i64Get() >= operand2->bGet());
        case Var: return new BValue(operand1->i64Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui8Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->ui8Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->ui8Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->ui8Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui8Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui8Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui8Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui8Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->ui8Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->ui8Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->ui8Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->ui8Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->ui8Get() >= operand2->bGet());
        case Var: return new BValue(operand1->ui8Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui16Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->ui16Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->ui16Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->ui16Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui16Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui16Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui16Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui16Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->ui16Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->ui16Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->ui16Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->ui16Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->ui16Get() >= operand2->bGet());
        case Var: return new BValue(operand1->ui16Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui32Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->ui32Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->ui32Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->ui32Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui32Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui32Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui32Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui32Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->ui32Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->ui32Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->ui32Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->ui32Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->ui32Get() >= operand2->bGet());
        case Var: return new BValue(operand1->ui32Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui64Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->ui64Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->ui64Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->ui64Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->ui64Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui64Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui64Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui64Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->ui64Get() >= operand2->iGet());
        case Float32: return new BValue(operand1->ui64Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->ui64Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->ui64Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->ui64Get() >= operand2->bGet());
        case Var: return new BValue(operand1->ui64Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->iGet() >= operand2->i8Get());
        case Int16: return new BValue(operand1->iGet() >= operand2->i16Get());
        case Int32: return new BValue(operand1->iGet() >= operand2->i32Get());
        case Int64: return new BValue(operand1->iGet() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->iGet() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->iGet() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->iGet() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->iGet() >= operand2->ui64Get());
        case Int: return new BValue(operand1->iGet() >= operand2->iGet());
        case Float32: return new BValue(operand1->iGet() >= operand2->f32Get());
        case Float64: return new BValue(operand1->iGet() >= operand2->f64Get());
        case Float80: return new BValue(operand1->iGet() >= operand2->f80Get());
        case Bool: return new BValue(operand1->iGet() >= operand2->bGet());
        case Var: return new BValue(operand1->iGet() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f32Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->f32Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->f32Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->f32Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->f32Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->f32Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->f32Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->f32Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->f32Get() >= operand2->f32Get());
        case Float32: return new BValue(operand1->f32Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->f32Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->f32Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->f32Get() >= operand2->bGet());
        case Var: return new BValue(operand1->f32Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f64Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->f64Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->f64Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->f64Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->f64Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->f64Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->f64Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->f64Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->f64Get() >= operand2->f64Get());
        case Float32: return new BValue(operand1->f64Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->f64Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->f64Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->f64Get() >= operand2->bGet());
        case Var: return new BValue(operand1->f64Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f80Get() >= operand2->i8Get());
        case Int16: return new BValue(operand1->f80Get() >= operand2->i16Get());
        case Int32: return new BValue(operand1->f80Get() >= operand2->i32Get());
        case Int64: return new BValue(operand1->f80Get() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->f80Get() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->f80Get() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->f80Get() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->f80Get() >= operand2->ui64Get());
        case Int: return new BValue(operand1->f80Get() >= operand2->f64Get());
        case Float32: return new BValue(operand1->f80Get() >= operand2->f32Get());
        case Float64: return new BValue(operand1->f80Get() >= operand2->f64Get());
        case Float80: return new BValue(operand1->f80Get() >= operand2->f80Get());
        case Bool: return new BValue(operand1->f80Get() >= operand2->bGet());
        case Var: return new BValue(operand1->f80Get() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->bGet() >= operand2->i8Get());
        case Int16: return new BValue(operand1->bGet() >= operand2->i16Get());
        case Int32: return new BValue(operand1->bGet() >= operand2->i32Get());
        case Int64: return new BValue(operand1->bGet() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->bGet() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->bGet() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->bGet() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->bGet() >= operand2->ui64Get());
        case Int: return new BValue(operand1->bGet() >= operand2->f64Get());
        case Float32: return new BValue(operand1->bGet() >= operand2->f32Get());
        case Float64: return new BValue(operand1->bGet() >= operand2->f64Get());
        case Float80: return new BValue(operand1->bGet() >= operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() >= operand2->bGet());
        case Var: return new BValue(operand1->bGet() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new BValue(operand1->strGet() >= operand2->strGet());
        case Var: return new BValue(operand1->strGet() >= operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->varGet() >= operand2->i8Get());
        case Int16: return new BValue(operand1->varGet() >= operand2->i16Get());
        case Int32: return new BValue(operand1->varGet() >= operand2->i32Get());
        case Int64: return new BValue(operand1->varGet() >= operand2->i64Get());
        case UInt8: return new BValue(operand1->varGet() >= operand2->ui8Get());
        case UInt16: return new BValue(operand1->varGet() >= operand2->ui16Get());
        case UInt32: return new BValue(operand1->varGet() >= operand2->ui32Get());
        case UInt64: return new BValue(operand1->varGet() >= operand2->ui64Get());
        case Int: return new BValue(operand1->varGet() >= operand2->iGet());
        case Float32: return new BValue(operand1->varGet() >= operand2->f32Get());
        case Float64: return new BValue(operand1->varGet() >= operand2->f64Get());
        case Float80: return new BValue(operand1->varGet() >= operand2->f80Get());
        case Bool: return new BValue(operand1->varGet() >= operand2->bGet());
        case Var: return new BValue(operand1->varGet() >= operand2->varGet());
        case String: return new BValue(operand1->varGet() >= operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new BValue(operand1->arrGet() >= operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

Value *ConditionalExpression::neq()
{
    Value *operand1 = expr1->eval(), *operand2 = expr2->eval();
    switch (operand1->getType())
    {
    case Int8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i8Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->i8Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->i8Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->i8Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->i8Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->i8Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->i8Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->i8Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->i8Get() != operand2->iGet());
        case Float32: return new BValue(operand1->i8Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->i8Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->i8Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->i8Get() != operand2->bGet());
        case Var: return new BValue(operand1->i8Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i16Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->i16Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->i16Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->i16Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->i16Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->i16Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->i16Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->i16Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->i16Get() != operand2->iGet());
        case Float32: return new BValue(operand1->i16Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->i16Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->i16Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->i16Get() != operand2->bGet());
        case Var: return new BValue(operand1->i16Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i32Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->i32Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->i32Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->i32Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->i32Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->i32Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->i32Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->i32Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->i32Get() != operand2->iGet());
        case Float32: return new BValue(operand1->i32Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->i32Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->i32Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->i32Get() != operand2->bGet());
        case Var: return new BValue(operand1->i32Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->i64Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->i64Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->i64Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->i64Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->i64Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->i64Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->i64Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->i64Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->i64Get() != operand2->iGet());
        case Float32: return new BValue(operand1->i64Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->i64Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->i64Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->i64Get() != operand2->bGet());
        case Var: return new BValue(operand1->i64Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt8:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui8Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->ui8Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->ui8Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->ui8Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->ui8Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui8Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui8Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui8Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->ui8Get() != operand2->iGet());
        case Float32: return new BValue(operand1->ui8Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->ui8Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->ui8Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->ui8Get() != operand2->bGet());
        case Var: return new BValue(operand1->ui8Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt16:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui16Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->ui16Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->ui16Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->ui16Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->ui16Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui16Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui16Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui16Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->ui16Get() != operand2->iGet());
        case Float32: return new BValue(operand1->ui16Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->ui16Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->ui16Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->ui16Get() != operand2->bGet());
        case Var: return new BValue(operand1->ui16Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui32Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->ui32Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->ui32Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->ui32Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->ui32Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui32Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui32Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui32Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->ui32Get() != operand2->iGet());
        case Float32: return new BValue(operand1->ui32Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->ui32Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->ui32Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->ui32Get() != operand2->bGet());
        case Var: return new BValue(operand1->ui32Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case UInt64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->ui64Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->ui64Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->ui64Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->ui64Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->ui64Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->ui64Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->ui64Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->ui64Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->ui64Get() != operand2->iGet());
        case Float32: return new BValue(operand1->ui64Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->ui64Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->ui64Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->ui64Get() != operand2->bGet());
        case Var: return new BValue(operand1->ui64Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Int:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->iGet() != operand2->i8Get());
        case Int16: return new BValue(operand1->iGet() != operand2->i16Get());
        case Int32: return new BValue(operand1->iGet() != operand2->i32Get());
        case Int64: return new BValue(operand1->iGet() != operand2->i64Get());
        case UInt8: return new BValue(operand1->iGet() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->iGet() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->iGet() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->iGet() != operand2->ui64Get());
        case Int: return new BValue(operand1->iGet() != operand2->iGet());
        case Float32: return new BValue(operand1->iGet() != operand2->f32Get());
        case Float64: return new BValue(operand1->iGet() != operand2->f64Get());
        case Float80: return new BValue(operand1->iGet() != operand2->f80Get());
        case Bool: return new BValue(operand1->iGet() != operand2->bGet());
        case Var: return new BValue(operand1->iGet() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float32:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f32Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->f32Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->f32Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->f32Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->f32Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->f32Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->f32Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->f32Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->f32Get() != operand2->f32Get());
        case Float32: return new BValue(operand1->f32Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->f32Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->f32Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->f32Get() != operand2->bGet());
        case Var: return new BValue(operand1->f32Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float64:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f64Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->f64Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->f64Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->f64Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->f64Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->f64Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->f64Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->f64Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->f64Get() != operand2->f64Get());
        case Float32: return new BValue(operand1->f64Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->f64Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->f64Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->f64Get() != operand2->bGet());
        case Var: return new BValue(operand1->f64Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Float80:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->f80Get() != operand2->i8Get());
        case Int16: return new BValue(operand1->f80Get() != operand2->i16Get());
        case Int32: return new BValue(operand1->f80Get() != operand2->i32Get());
        case Int64: return new BValue(operand1->f80Get() != operand2->i64Get());
        case UInt8: return new BValue(operand1->f80Get() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->f80Get() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->f80Get() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->f80Get() != operand2->ui64Get());
        case Int: return new BValue(operand1->f80Get() != operand2->f64Get());
        case Float32: return new BValue(operand1->f80Get() != operand2->f32Get());
        case Float64: return new BValue(operand1->f80Get() != operand2->f64Get());
        case Float80: return new BValue(operand1->f80Get() != operand2->f80Get());
        case Bool: return new BValue(operand1->f80Get() != operand2->bGet());
        case Var: return new BValue(operand1->f80Get() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Bool:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->bGet() != operand2->i8Get());
        case Int16: return new BValue(operand1->bGet() != operand2->i16Get());
        case Int32: return new BValue(operand1->bGet() != operand2->i32Get());
        case Int64: return new BValue(operand1->bGet() != operand2->i64Get());
        case UInt8: return new BValue(operand1->bGet() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->bGet() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->bGet() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->bGet() != operand2->ui64Get());
        case Int: return new BValue(operand1->bGet() != operand2->f64Get());
        case Float32: return new BValue(operand1->bGet() != operand2->f32Get());
        case Float64: return new BValue(operand1->bGet() != operand2->f64Get());
        case Float80: return new BValue(operand1->bGet() != operand2->f80Get());
        case Bool: return new BValue(operand1->bGet() != operand2->bGet());
        case Var: return new BValue(operand1->bGet() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case String:
        switch (operand2->getType())
        {
        case String: return new BValue(operand1->strGet() != operand2->strGet());
        case Var: return new BValue(operand1->strGet() != operand2->varGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Var:
        switch (operand2->getType())
        {
        case Int8: return new BValue(operand1->varGet() != operand2->i8Get());
        case Int16: return new BValue(operand1->varGet() != operand2->i16Get());
        case Int32: return new BValue(operand1->varGet() != operand2->i32Get());
        case Int64: return new BValue(operand1->varGet() != operand2->i64Get());
        case UInt8: return new BValue(operand1->varGet() != operand2->ui8Get());
        case UInt16: return new BValue(operand1->varGet() != operand2->ui16Get());
        case UInt32: return new BValue(operand1->varGet() != operand2->ui32Get());
        case UInt64: return new BValue(operand1->varGet() != operand2->ui64Get());
        case Int: return new BValue(operand1->varGet() != operand2->iGet());
        case Float32: return new BValue(operand1->varGet() != operand2->f32Get());
        case Float64: return new BValue(operand1->varGet() != operand2->f64Get());
        case Float80: return new BValue(operand1->varGet() != operand2->f80Get());
        case Bool: return new BValue(operand1->varGet() != operand2->bGet());
        case Var: return new BValue(operand1->varGet() != operand2->varGet());
        case String: return new BValue(operand1->varGet() != operand2->strGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    case Array:
        switch (operand2->getType())
        {
        case Array: return new BValue(operand1->arrGet() != operand2->arrGet());
        default: throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
        }

    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPNDS);
    }
}

#endif