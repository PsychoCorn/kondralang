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

    std::pair<std::string, std::string> getIdAndFormatSetting(std::string::iterator, 
        std::string::iterator);
    std::string formatVariable(std::pair<std::string, std::string>);
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
            result << formatVariable(getIdAndFormatSetting(lbrace, rbrace));
        if (rbrace == fstr.end())
            break;
        fstr = std::string(rbrace + 1, fstr.end());
    }
    return new StrValue(kondra::string(result.str()));
}

std::pair<std::string, std::string> FormatStringExpression::getIdAndFormatSetting(
    std::string::iterator lb, std::string::iterator rb
)
{
    std::string identifier = std::string(lb + 1, std::find(lb + 1, rb, ':'));
    std::string formatSetting = std::string(std::find(lb + 1, rb, ':'), rb);
    return std::pair<std::string, std::string>(identifier, formatSetting);
}

std::string FormatStringExpression::formatVariable(
    std::pair<std::string, std::string> idAndFormatSetting
)
{
    switch (Variables::get(idAndFormatSetting.first)->getType())
    {
    case Int8:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->i8Get()
        ));
    case Int16:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->i16Get()
        ));

    case Int32:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->i32Get()
        ));
    
    case Int64:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->i64Get()
        ));

    case UInt8:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->ui8Get()
        ));
    case UInt16:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->ui16Get()
        ));

    case UInt32:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->ui32Get()
        ));
    
    case UInt64:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->ui64Get()
        ));

    case Int:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->iGet()
        ));

    case Float32:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->f32Get()
        ));

    case Float64:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->f64Get()
        ));

    case Float80:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->f80Get()
        ));

    case Bool:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->bGet()
        ));

    case String:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->strGet()
        ));

    case Var:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables::get(idAndFormatSetting.first)->varGet()
        ));
    
    default:
        throw std::runtime_error("Wrong type for f-string");
    }
}

#endif