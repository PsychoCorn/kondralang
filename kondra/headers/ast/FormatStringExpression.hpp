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

template <class T>
class FormatStringExpression : public Expression<T>
{
private:
    size_t pos = 0;
    std::string fmt;

    std::pair<std::string, std::string> getIdAndFormatSetting(std::string::iterator, 
        std::string::iterator);
    std::string formatVariable(std::pair<std::string, std::string>);
public:
    FormatStringExpression(std::string);
    T eval() override;
};

template <class T>
FormatStringExpression<T>::FormatStringExpression(std::string fmt)
{
    this->fmt = fmt;
}

template <class T>
T FormatStringExpression<T>::eval()
{
    std::stringstream result;
    std::string::iterator lbrace, rbrace;
    std::string test;
    for (;;)
    {
        lbrace = std::find(fmt.begin(), fmt.end(), '{');
        rbrace = std::find(fmt.begin(), fmt.end(), '}');
        result << std::string(fmt.begin(), lbrace); 
        test = result.str();
        if (lbrace != fmt.end())
            result << formatVariable(getIdAndFormatSetting(lbrace, rbrace));
        test = result.str();
        if (rbrace == fmt.end())
            break;
        fmt = std::string(rbrace + 1, fmt.end());
    }
    return kondra::string(result.str());
}

template <class T>
std::pair<std::string, std::string> FormatStringExpression<T>::getIdAndFormatSetting(
    std::string::iterator lb, std::string::iterator rb
)
{
    std::string identifier = std::string(lb + 1, std::find(lb + 1, rb, ':'));
    std::string formatSetting = std::string(std::find(lb + 1, rb, ':'), rb);
    return std::pair<std::string, std::string>(identifier, formatSetting);
}

template <class T>
std::string FormatStringExpression<T>::formatVariable(
    std::pair<std::string, std::string> idAndFormatSetting
)
{
    switch (ListOfVariables::getType(idAndFormatSetting.first))
    {
    case Int8:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<signed char>::get(idAndFormatSetting.first)
        ));
    case Int16:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<short>::get(idAndFormatSetting.first)
        ));

    case Int32:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<int>::get(idAndFormatSetting.first)
        ));
    
    case Int64:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<long long>::get(idAndFormatSetting.first)
        ));

    case UInt8:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<unsigned char>::get(idAndFormatSetting.first)
        ));
    case UInt16:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<unsigned short>::get(idAndFormatSetting.first)
        ));

    case UInt32:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<unsigned int>::get(idAndFormatSetting.first)
        ));
    
    case UInt64:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<unsigned long long>::get(idAndFormatSetting.first)
        ));

    case Int:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<kondra::dynamic_int>::get(idAndFormatSetting.first)
        ));

    case Float32:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<float>::get(idAndFormatSetting.first)
        ));

    case Float64:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<double>::get(idAndFormatSetting.first)
        ));

    case Float80:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<long double>::get(idAndFormatSetting.first)
        ));

    case Bool:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<bool>::get(idAndFormatSetting.first)
        ));

    case String:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<kondra::string>::get(idAndFormatSetting.first)
        ));

    case Var:
        return std::vformat("{" + idAndFormatSetting.second + "}", 
            std::make_format_args(Variables<kondra::var>::get(idAndFormatSetting.first)
        ));
    
    default:
        throw std::runtime_error(ERR_MSG_UNKN_ID);
    }
}

#endif