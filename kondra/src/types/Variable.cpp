#include "../../headers/types/Variable.hpp"

#define ERR_MSG_INVALID_OPERANDS "Invalid operands!"
#define ERR_MSG_INVALID_OPERAND "Invalid operand!"
#define ERR_MSG_DIVISION_BY_ZERO "Division by zero!"

namespace kondra
{

    Variable::Variable()
    {
        type = VarType::None;
    }

    Variable::Variable(const dynamic_int &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const signed char &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }
    
    Variable::Variable(const unsigned char &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const short &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }
    
    Variable::Variable(const unsigned short &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const int &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const unsigned int &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const long long &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const unsigned long long &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const float &floatValue)
    {
        data.floatData = new double(floatValue);
        type = VarType::Float;
    }

    Variable::Variable(const double &floatValue)
    {
        data.floatData = new double(floatValue);
        type = VarType::Float;
    }

    Variable::Variable(const long double &floatValue)
    {
        data.floatData = new double(floatValue);
        type = VarType::Float;
    }

    Variable::Variable(const char *strValue)
    {
        data.stringData = new string(strValue);
        type = VarType::String;
    }

    Variable::Variable(const std::string &strValue)
    {
        data.stringData = new string(strValue);
        type = VarType::String;
    }

    Variable::Variable(const string &strValue)
    {
        data.stringData = new string(strValue);
        type = VarType::String;
    }

    Variable::Variable(const bool &boolValue)
    {
        data.boolData = new bool(boolValue);
        type = VarType::Bool;
    }

    Variable::Variable(const Variable &varValue)
    {
        copyDataFromOther(varValue);
    }

    void Variable::copyDataFromOther(const Variable &other)
    {
        type = other.getType();
        switch (type)
        {
        case VarType::Int:
            data.intData = new dynamic_int(*(other.getData().intData));
            break;

        case VarType::Float:
            data.floatData = new double(*(other.getData().floatData));
            break;

        case VarType::String:
            data.stringData = new string(*(other.getData().stringData));
            break;

        case VarType::Bool:
            data.boolData = new bool(*(other.getData().boolData));
            break;

        default:
            break;
        }
    }

    Variable::~Variable()
    {
        clearData();
    }

    VarType Variable::getType() const
    {
        return type;
    }

    VarData Variable::getData() const
    {
        return data;
    }

    void Variable::clearData()
    {
        switch (type)
        {
        case VarType::Int:
            delete data.intData;
            break;

        case VarType::Float:
            delete data.floatData;
            break;

        case VarType::String:
            delete data.stringData;
            break;

        case VarType::Bool:
            delete data.boolData;
            break;

        default:
            break;
        }
        type = VarType::None;
    }

    Variable &Variable::operator=(const Variable &other)
    {
        if (type == other.getType())
        {
            switch (type)
            {
            case VarType::Int:
                *(data.intData) = *(other.getData().intData);
                break;

            case VarType::Float:
                *(data.floatData) = *(other.getData().floatData);
                break;

            case VarType::String:
                *(data.stringData) = *(other.getData().stringData);
                break;

            case VarType::Bool:
                *(data.boolData) = *(other.getData().boolData);
                break;

            default:
                break;
            }
        }
        else
        {
            clearData();
            copyDataFromOther(other);
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Variable &obj)
    {
        switch (obj.type)
        {
        case VarType::Int:
            os << *(obj.data.intData);
            break;

        case VarType::Float:
            os << *(obj.data.floatData);
            break;

        case VarType::String:
            os << *(obj.data.stringData);
            break;

        case VarType::Bool:
            os << std::boolalpha << *(obj.data.boolData);
            break;

        case VarType::None:
            os << "None";
            break;

        default:
            break;
        }
        return os;
    }

    std::istream &operator>>(std::istream &is, Variable &obj)
    {
        string val;
        is >> val;
        obj = Variable(val.c_str());
        return is;
    }

    Variable Variable::toInt(const Variable &obj)
    {
        switch (obj.getType())
        {
        case VarType::Float:
            return Variable(dynamic_int(*(obj.getData().floatData)));
            break;

        case VarType::String:
            return Variable(dynamic_int(obj.getData().stringData->c_str()));
            break;

        case VarType::Bool:
            return Variable(int(*(obj.getData().boolData)));
            break;

        case VarType::None:
            return Variable(0);
            break;

        default:
            return obj;
            break;
        }
    }

    Variable Variable::toFloat(const Variable &obj)
    {
        switch (obj.getType())
        {
        case VarType::Int:
            return Variable(obj.getData().intData->doubleGetNumber());
            break;

        case VarType::String:
            return Variable(std::stod(obj.getData().stringData->c_str()));
            break;

        case VarType::Bool:
            return Variable(float(*(obj.getData().boolData)));
            break;

        case VarType::None:
            return Variable(.0f);
            break;

        default:
            return obj;
            break;
        }
    }

    Variable Variable::toString(const Variable &obj)
    {
        switch (obj.getType())
        {
        case VarType::Int:
            return Variable(obj.getData().intData->strGetNumber());
            break;

        case VarType::Float:
            return Variable(std::to_string(*(obj.getData().floatData)).c_str());
            break;

        case VarType::Bool:
            return Variable(*(obj.getData().boolData) ? "true" : "false");
            break;

        case VarType::None:
            return Variable("");
            break;

        default:
            return obj;
            break;
        }
    }

    Variable Variable::toBool(const Variable &obj)
    {
        switch (obj.getType())
        {
        case VarType::Int:
            return Variable(bool(obj.getData().intData->longLongGetNumber()));
            break;

        case VarType::Float:
            return Variable(bool(*(obj.getData().floatData)));
            break;

        case VarType::String:
            return Variable((*(obj.getData().stringData)) == "" ? false : true);
            break;

        case VarType::None:
            return Variable(false);
            break;

        default:
            return obj;
            break;
        }
    }

    Variable operator+(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.intData) + *(var2.data.intData));
                break;

            case VarType::Float:
                return Variable(var1.data.intData->doubleGetNumber() + *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.intData) + dynamic_int(*(var2.data.boolData)));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.floatData) + var2.data.intData->doubleGetNumber());
                break;

            case VarType::Float:
                return Variable(*(var1.data.floatData) + *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.floatData) + *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return Variable((*(var1.data.stringData) + *(var2.data.stringData)).c_str());
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.boolData) + *(var2.data.intData));
                break;

            case VarType::Float:
                return Variable(*(var1.data.boolData) + *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.boolData) + *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    Variable &Variable::operator+=(const Variable &other)
    {
        *this = *this + other;
        return *this;
    }

    Variable operator-(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.intData) - *(var2.data.intData));
                break;

            case VarType::Float:
                return Variable(var1.data.intData->doubleGetNumber() - *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.intData) - dynamic_int(*(var2.data.boolData)));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.floatData) - var2.data.intData->doubleGetNumber());
                break;

            case VarType::Float:
                return Variable(*(var1.data.floatData) - *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.floatData) - *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.boolData) - *(var2.data.intData));
                break;

            case VarType::Float:
                return Variable(*(var1.data.boolData) - *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.boolData) - *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    Variable &Variable::operator-=(const Variable &other)
    {
        *this = *this - other;
        return *this;
    }

    Variable Variable::operator-() const
    {
        switch (type)
        {
        case VarType::Int:
            return Variable(-(*(data.intData)));
            break;

        case VarType::Float:
            return Variable(-(*(data.floatData)));
            break;

        case VarType::Bool:
            return Variable(-(*(data.boolData)));
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERAND);
            break;
        }
    }

    bool operator==(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.intData) == *(var2.data.intData);
                break;

            case VarType::Float:
                return var1.data.intData->doubleGetNumber() == *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.intData) == *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.floatData) == var2.data.intData->doubleGetNumber();
                break;

            case VarType::Float:
                return *(var1.data.floatData) == *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.floatData) == *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.boolData) == *(var2.data.intData);
                break;

            case VarType::Float:
                return *(var1.data.boolData) == *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.boolData) == *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return *(var1.data.stringData) == *(var2.data.stringData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    bool operator<(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.intData) < *(var2.data.intData);
                break;

            case VarType::Float:
                return var1.data.intData->doubleGetNumber() < *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.intData) < *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.floatData) < var2.data.intData->doubleGetNumber();
                break;

            case VarType::Float:
                return *(var1.data.floatData) < *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.floatData) < *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.boolData) < *(var2.data.intData);
                break;

            case VarType::Float:
                return *(var1.data.boolData) < *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.boolData) < *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return *(var1.data.stringData) < *(var2.data.stringData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    bool operator>(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.intData) > *(var2.data.intData);
                break;

            case VarType::Float:
                return var1.data.intData->doubleGetNumber() > *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.intData) > *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.floatData) > var2.data.intData->doubleGetNumber();
                break;

            case VarType::Float:
                return *(var1.data.floatData) > *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.floatData) > *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.boolData) > *(var2.data.intData);
                break;

            case VarType::Float:
                return *(var1.data.boolData) > *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.boolData) > *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return *(var1.data.stringData) > *(var2.data.stringData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    bool operator<=(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.intData) <= *(var2.data.intData);
                break;

            case VarType::Float:
                return var1.data.intData->doubleGetNumber() <= *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.intData) <= *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.floatData) <= var2.data.intData->doubleGetNumber();
                break;

            case VarType::Float:
                return *(var1.data.floatData) <= *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.floatData) <= *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.boolData) <= *(var2.data.intData);
                break;

            case VarType::Float:
                return *(var1.data.boolData) <= *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.boolData) <= *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return *(var1.data.stringData) <= *(var2.data.stringData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    bool operator>=(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.intData) >= *(var2.data.intData);
                break;

            case VarType::Float:
                return var1.data.intData->doubleGetNumber() >= *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.intData) >= *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.floatData) >= var2.data.intData->doubleGetNumber();
                break;

            case VarType::Float:
                return *(var1.data.floatData) >= *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.floatData) >= *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.boolData) >= *(var2.data.intData);
                break;

            case VarType::Float:
                return *(var1.data.boolData) >= *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.boolData) >= *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return *(var1.data.stringData) >= *(var2.data.stringData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    bool operator!=(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.intData) != *(var2.data.intData);
                break;

            case VarType::Float:
                return var1.data.intData->doubleGetNumber() != *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.intData) != *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.floatData) != var2.data.intData->doubleGetNumber();
                break;

            case VarType::Float:
                return *(var1.data.floatData) != *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.floatData) != *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return *(var1.data.boolData) != *(var2.data.intData);
                break;

            case VarType::Float:
                return *(var1.data.boolData) != *(var2.data.floatData);
                break;

            case VarType::Bool:
                return *(var1.data.boolData) != *(var2.data.boolData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::String:
                return *(var1.data.stringData) != *(var2.data.stringData);
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    Variable operator/(const Variable &var1, const Variable &var2)
    {
        if (var2 == Variable(0))
        {
            throw std::runtime_error(ERR_MSG_DIVISION_BY_ZERO);
        }
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(var1.data.intData->doubleGetNumber() / var2.data.intData->doubleGetNumber());
                break;

            case VarType::Float:
                return Variable(var1.data.intData->doubleGetNumber() / *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(var1.data.intData->doubleGetNumber() / *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.floatData) / var2.data.intData->doubleGetNumber());
                break;

            case VarType::Float:
                return Variable(*(var1.data.floatData) / *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.floatData) / *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.boolData) / var2.data.intData->doubleGetNumber());
                break;

            case VarType::Float:
                return Variable(*(var1.data.boolData) / *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.boolData) / *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    Variable &Variable::operator/=(const Variable &other)
    {
        *this = *this / other;
        return *this;
    }

    Variable operator*(const Variable &var1, const Variable &var2)
    {
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.intData) * *(var2.data.intData));
                break;

            case VarType::Float:
                return Variable(var1.data.intData->doubleGetNumber() * *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.intData) * dynamic_int(*(var2.data.boolData)));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Float:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.floatData) * var2.data.intData->doubleGetNumber());
                break;

            case VarType::Float:
                return Variable(*(var1.data.floatData) * *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.floatData) * *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::String:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.stringData) * var2.data.intData->uLongLongGetNumber());
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.boolData) * *(var2.data.intData));
                break;

            case VarType::Float:
                return Variable(*(var1.data.boolData) * *(var2.data.floatData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.boolData) * *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    Variable &Variable::operator*=(const Variable &other)
    {
        *this = *this * other;
        return *this;
    }

    bool Variable::operator!() const
    {
        return !(*(Variable::toBool(*this).data.boolData));
    }

    Variable operator%(const Variable &var1, const Variable &var2)
    {
        if (var2 == Variable(0))
        {
            throw std::runtime_error(ERR_MSG_DIVISION_BY_ZERO);
        }
        switch (var1.type)
        {
        case VarType::Int:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.intData) % *(var2.data.intData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.intData) % *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        case VarType::Bool:
            switch (var2.type)
            {
            case VarType::Int:
                return Variable(*(var1.data.boolData) % *(var2.data.intData));
                break;

            case VarType::Bool:
                return Variable(*(var1.data.boolData) % *(var2.data.boolData));
                break;

            default:
                throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
                break;
            }
            break;

        default:
            throw std::runtime_error(ERR_MSG_INVALID_OPERANDS);
            break;
        }
    }

    Variable &Variable::operator%=(const Variable &other)
    {
        *this = *this % other;
        return *this;
    }

    Variable &Variable::operator++()
    {
        *this = *this + Variable(1);
        return *this;
    }

    Variable Variable::operator++(int)
    {
        Variable temp = *this;
        *this = *this + Variable(1);
        return temp;
    }

    Variable &Variable::operator--()
    {
        *this = *this - Variable(1);
        return *this;
    }

    Variable Variable::operator--(int)
    {
        Variable temp = *this;
        *this = *this - Variable(1);
        return temp;
    }

    bool operator&&(const Variable &var1, const Variable &var2)
    {
        return *(Variable::toBool(var1).data.boolData) && *(Variable::toBool(var2).data.boolData);
    }

    bool operator||(const Variable &var1, const Variable &var2)
    {
        return *(Variable::toBool(var1).data.boolData) || *(Variable::toBool(var2).data.boolData);
    }

}