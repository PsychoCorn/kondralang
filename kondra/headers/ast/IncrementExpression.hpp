#ifndef IncrementExpression_HPP
#define IncrementExpression_HPP

#include "Expression.hpp"
#include "../lib/types/ValueCreator.hpp"
#include <stdexcept>

class IncrementExpression : public Expression
{
private:
    std::string variable;
    TokenType operation;
    bool isPrefix;

    Value *preInc();
    Value *postInc();
    Value *preDec();
    Value *postDec();

public:
    IncrementExpression(const std::string &, const TokenType &, const bool &);
    Value *eval() override;
};

IncrementExpression::IncrementExpression(const std::string &variable, 
    const TokenType &operation, const bool &isPrefix)
{
    this->variable = variable;
    this->operation = operation;
    this->isPrefix = isPrefix;
}

Value *IncrementExpression::eval()
{
    if (isPrefix)
    {
        switch (operation)
        {
        case TokenType::DoublePlus: return preInc();
        case TokenType::DoubleMinus: return preDec();
        default:
            throw std::runtime_error(ERR_MSG_UNKNWN_OP);
        }
    }
    else
    {
        switch (operation)
        {
        case TokenType::DoublePlus: return postInc();
        case TokenType::DoubleMinus: return postDec();
        default:
            throw std::runtime_error(ERR_MSG_UNKNWN_OP);
        }
    }
}

Value *IncrementExpression::preInc()
{
    Value *newValue, *currentValue = ValueCreator::createValue(Scopes::get(variable), true);
    switch (currentValue->getType())
    {
    case Type::Int8: 
        newValue = new I8Value(currentValue->i8Get() + 1, true);
        break;

    case Type::Int16: 
        newValue = new I16Value(currentValue->i16Get() + 1, true);
        break;

    case Type::Int32: 
        newValue = new I32Value(currentValue->i32Get() + 1, true);
        break;

    case Type::Int64: 
        newValue = new I64Value(currentValue->i64Get() + 1, true);
        break;

    case Type::UInt8: 
        newValue = new UI8Value(currentValue->ui8Get() + 1, true);
        break;

    case Type::UInt16: 
        newValue = new UI16Value(currentValue->ui16Get() + 1, true);
        break;

    case Type::UInt32: 
        newValue = new UI32Value(currentValue->ui32Get() + 1, true);
        break;

    case Type::UInt64: 
        newValue = new UI64Value(currentValue->ui64Get() + 1, true);
        break;

    case Type::Int: 
        newValue = new IValue(currentValue->iGet() + 1, true);
        break;

    case Type::Float32: 
        newValue = new F32Value(currentValue->f32Get() + 1, true);
        break;

    case Type::Float64: 
        newValue = new F64Value(currentValue->f64Get() + 1, true);
        break;

    case Type::Var: 
        newValue = new VarValue(currentValue->varGet() + 1, true);
        break;
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
    Scopes::set(variable, newValue);
    delete currentValue;
    return newValue;
}

Value *IncrementExpression::postInc()
{
    Value *newValue, *currentValue = ValueCreator::createValue(Scopes::get(variable), true);
    switch (currentValue->getType())
    {
    case Type::Int8: 
        newValue = new I8Value(currentValue->i8Get() + 1, true);
        break;

    case Type::Int16: 
        newValue = new I16Value(currentValue->i16Get() + 1, true);
        break;

    case Type::Int32: 
        newValue = new I32Value(currentValue->i32Get() + 1, true);
        break;

    case Type::Int64: 
        newValue = new I64Value(currentValue->i64Get() + 1, true);
        break;

    case Type::UInt8: 
        newValue = new UI8Value(currentValue->ui8Get() + 1, true);
        break;

    case Type::UInt16: 
        newValue = new UI16Value(currentValue->ui16Get() + 1, true);
        break;

    case Type::UInt32: 
        newValue = new UI32Value(currentValue->ui32Get() + 1, true);
        break;

    case Type::UInt64: 
        newValue = new UI64Value(currentValue->ui64Get() + 1, true);
        break;

    case Type::Int: 
        newValue = new IValue(currentValue->iGet() + 1, true);
        break;

    case Type::Float32: 
        newValue = new F32Value(currentValue->f32Get() + 1, true);
        break;

    case Type::Float64: 
        newValue = new F64Value(currentValue->f64Get() + 1, true);
        break;

    case Type::Var: 
        newValue = new VarValue(currentValue->varGet() + 1, true);
        break;
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
    Scopes::set(variable, newValue);
    delete newValue;
    return currentValue;
}

Value *IncrementExpression::preDec()
{
    Value *newValue, *currentValue = ValueCreator::createValue(Scopes::get(variable), true);
    switch (currentValue->getType())
    {
    case Type::Int8: 
        newValue = new I8Value(currentValue->i8Get() - 1, true);
        break;

    case Type::Int16: 
        newValue = new I16Value(currentValue->i16Get() - 1, true);
        break;

    case Type::Int32: 
        newValue = new I32Value(currentValue->i32Get() - 1, true);
        break;

    case Type::Int64: 
        newValue = new I64Value(currentValue->i64Get() - 1, true);
        break;

    case Type::UInt8: 
        newValue = new UI8Value(currentValue->ui8Get() - 1, true);
        break;

    case Type::UInt16: 
        newValue = new UI16Value(currentValue->ui16Get() - 1, true);
        break;

    case Type::UInt32: 
        newValue = new UI32Value(currentValue->ui32Get() - 1, true);
        break;

    case Type::UInt64: 
        newValue = new UI64Value(currentValue->ui64Get() - 1, true);
        break;

    case Type::Int: 
        newValue = new IValue(currentValue->iGet() - 1, true);
        break;

    case Type::Float32: 
        newValue = new F32Value(currentValue->f32Get() - 1, true);
        break;

    case Type::Float64: 
        newValue = new F64Value(currentValue->f64Get() - 1, true);
        break;

    case Type::Var: 
        newValue = new VarValue(currentValue->varGet() - 1, true);
        break;
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
    Scopes::set(variable, newValue);
    delete currentValue;
    return newValue;
}

Value *IncrementExpression::postDec()
{
    Value *newValue, *currentValue = ValueCreator::createValue(Scopes::get(variable), true);
    switch (currentValue->getType())
    {
    case Type::Int8: 
        newValue = new I8Value(currentValue->i8Get() - 1, true);
        break;

    case Type::Int16: 
        newValue = new I16Value(currentValue->i16Get() - 1, true);
        break;

    case Type::Int32: 
        newValue = new I32Value(currentValue->i32Get() - 1, true);
        break;

    case Type::Int64: 
        newValue = new I64Value(currentValue->i64Get() - 1, true);
        break;

    case Type::UInt8: 
        newValue = new UI8Value(currentValue->ui8Get() - 1, true);
        break;

    case Type::UInt16: 
        newValue = new UI16Value(currentValue->ui16Get() - 1, true);
        break;

    case Type::UInt32: 
        newValue = new UI32Value(currentValue->ui32Get() - 1, true);
        break;

    case Type::UInt64: 
        newValue = new UI64Value(currentValue->ui64Get() - 1, true);
        break;

    case Type::Int: 
        newValue = new IValue(currentValue->iGet() - 1, true);
        break;

    case Type::Float32: 
        newValue = new F32Value(currentValue->f32Get() - 1, true);
        break;

    case Type::Float64: 
        newValue = new F64Value(currentValue->f64Get() - 1, true);
        break;

    case Type::Var: 
        newValue = new VarValue(currentValue->varGet() - 1, true);
        break;
    
    default:
        throw std::runtime_error(ERR_MSG_WRNG_OPND);
    }
    Scopes::set(variable, newValue);
    delete newValue;
    return currentValue;
}

#endif