#ifndef Format_HPP
#define Format_HPP

#include "Function.hpp"
#include <sstream>
#include <algorithm>
#include "../../io/kondraio.hpp"
#include "../types/VarValue.hpp"

class Format : public Function
{
private:
    std::string formatValue(const std::string &, Value *);
    std::string formatVarValue(const std::string &,  const kondra::var &);
public:
    Format();
    Value *execute(std::vector<Value *>::iterator, std::vector<Value *>::iterator) override;
};

Format::Format() {}

Value *Format::execute(std::vector<Value *>::iterator begin, std::vector<Value *>::iterator end)
{
    if (end - begin == 0)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    std::string fmt = (*begin)->strGet();
    size_t numOfValues = end - begin - 1;
    if (numOfValues == 0)
        return new StrValue(fmt);
    if (std::count(fmt.begin(), fmt.end(), '{') != numOfValues || 
        std::count(fmt.begin(), fmt.end(), '}') != numOfValues)
        throw std::runtime_error(ERR_MSG_WRNG_ARGS);
    std::stringstream result;
    std::string::iterator lbrace, rbrace;
    for (auto value = begin + 1; value != end; value++)
    {
        lbrace = std::find(fmt.begin(), fmt.end(), '{');
        rbrace = std::find(fmt.begin(), fmt.end(), '}');
        result << std::string(fmt.begin(), lbrace); 
        result << formatValue(std::string(lbrace, rbrace + 1), *value);
        fmt = std::string(rbrace + 1, fmt.end());
    } 
    result << fmt;
    return new StrValue(kondra::string(result.str()));
}

std::string Format::formatValue(const std::string &formatContext, Value *value)
{
    switch (value->getType())
    {
    case Int8: return std::vformat(formatContext, std::make_format_args(value->i8Get()));
    case Int16: return std::vformat(formatContext, std::make_format_args(value->i16Get()));
    case Int32: return std::vformat(formatContext, std::make_format_args(value->i32Get()));
    case Int64: return std::vformat(formatContext, std::make_format_args(value->i64Get()));
    case UInt8: return std::vformat(formatContext, std::make_format_args(value->ui8Get()));
    case UInt16: return std::vformat(formatContext, std::make_format_args(value->ui16Get()));
    case UInt32: return std::vformat(formatContext, std::make_format_args(value->ui32Get()));
    case UInt64: return std::vformat(formatContext, std::make_format_args(value->ui64Get()));
    case Int: return std::vformat(formatContext, std::make_format_args(value->iGet()));
    case Float32: return std::vformat(formatContext, std::make_format_args(value->f32Get()));
    case Float64: return std::vformat(formatContext, std::make_format_args(value->f64Get()));
    case Float80: return std::vformat(formatContext, std::make_format_args(value->f80Get()));
    case Bool: return std::vformat(formatContext, std::make_format_args(value->bGet()));
    case String: return std::vformat(formatContext, std::make_format_args(value->strGet()));
    case Var: return formatVarValue(formatContext, value->varGet());
    default: throw std::runtime_error("Wrong type for f-string");
    }
}

std::string Format::formatVarValue(const std::string &formatContext, const kondra::var &value)
{
    switch (value.getType())
    {
    case kondra::VarType::Int:
        return std::vformat(formatContext, std::make_format_args(*(value.getData().intData)));
    case kondra::VarType::Float:
        return std::vformat(formatContext, std::make_format_args(*(value.getData().floatData)));
    case kondra::VarType::String:
        return std::vformat(formatContext, std::make_format_args(*(value.getData().stringData)));
    case kondra::VarType::Bool:
        return std::vformat(formatContext, std::make_format_args(*(value.getData().boolData)));
    default:
        return std::vformat(formatContext, std::make_format_args("None"));
    }
}

#endif