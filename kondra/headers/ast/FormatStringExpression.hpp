#ifndef FormatStringExpression_HPP
#define FormatStringExpression_HPP


#include "Expression.hpp"
#include "../types/kondratypes.hpp"
#include "../lib/Variables.hpp"
#include "../io/kondraio.hpp"
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

class FormatStringExpression : public Expression
{
private:
    size_t pos = 0;
    std::string fmt;

    std::pair<std::string, std::string> getIdAndFormatContext(std::string::iterator, 
        std::string::iterator);
    std::string formatVariable(const std::pair<std::string, std::string> &);
    std::string formatVarVariable(const kondra::var &, const std::string &);
public:
    FormatStringExpression(std::string);
    Value *eval() override;
};

FormatStringExpression::FormatStringExpression(std::string fmt)
{
    this->fmt = fmt;
}

Value *FormatStringExpression::eval()
{
    std::string fstr = fmt; 
    std::stringstream result;
    std::string::iterator lbrace, rbrace;
    for (;;)
    {
        lbrace = std::find(fstr.begin(), fstr.end(), '{');
        rbrace = std::find(fstr.begin(), fstr.end(), '}');
        result << std::string(fstr.begin(), lbrace); 
        if (lbrace != fstr.end())
            result << formatVariable(getIdAndFormatContext(lbrace, rbrace));
        if (rbrace == fstr.end())
            break;
        fstr = std::string(rbrace + 1, fstr.end());
    }
    return new StrValue(kondra::string(result.str()));
}

std::pair<std::string, std::string> FormatStringExpression::getIdAndFormatContext(
    std::string::iterator lb, std::string::iterator rb
)
{
    auto posOfColon = std::find(lb + 1, rb, ':');
    std::string identifier = std::string(lb + 1, posOfColon);
    std::string formatContext = std::string(posOfColon, rb);
    return std::pair<std::string, std::string>(identifier, formatContext);
}

std::string FormatStringExpression::formatVariable(
    const std::pair<std::string, std::string> &idAndFormatContext
)
{
    switch (Variables::get(idAndFormatContext.first)->getType())
    {
    case Int8:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->i8Get()
        ));
    case Int16:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->i16Get()
        ));

    case Int32:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->i32Get()
        ));
    
    case Int64:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->i64Get()
        ));

    case UInt8:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->ui8Get()
        ));
    case UInt16:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->ui16Get()
        ));

    case UInt32:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->ui32Get()
        ));
    
    case UInt64:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->ui64Get()
        ));

    case Int:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->iGet()
        ));

    case Float32:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->f32Get()
        ));

    case Float64:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->f64Get()
        ));

    case Float80:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->f80Get()
        ));

    case Bool:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->bGet()
        ));

    case String:
        return std::vformat("{" + idAndFormatContext.second + "}", 
            std::make_format_args(Variables::get(idAndFormatContext.first)->strGet()
        ));

    case Var:
        return formatVarVariable(Variables::get(idAndFormatContext.first)->varGet(), 
            "{" + idAndFormatContext.second + "}");
    
    default:
        throw std::runtime_error("Wrong type for f-string");
    }
}

std::string FormatStringExpression::formatVarVariable(
    const kondra::var &value, const std::string &formatContext
)
{
    switch (value.getType())
    {
    case kondra::VarType::Int:
        return std::vformat(formatContext , std::make_format_args(*(value.getData().intData)));
    case kondra::VarType::Float:
        return std::vformat(formatContext , std::make_format_args(*(value.getData().floatData)));
    case kondra::VarType::String:
        return std::vformat(formatContext , std::make_format_args(*(value.getData().stringData)));
    case kondra::VarType::Bool:
        return std::vformat(formatContext , std::make_format_args(*(value.getData().boolData)));
    default:
        return std::vformat(formatContext , std::make_format_args("None"));
    }
}

#endif