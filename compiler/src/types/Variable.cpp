#include "../../headers/types/Variable.hpp"

#define ERR_MSG_INVALID_OPERANDS "Invalid operands!"
#define ERR_MSG_INVALID_OPERAND "Invalid operand!"
#define ERR_MSG_DIVISION_BY_ZERO "Division by zero!"
#define ERR_MSG_NOT_STRING "Variable is not string!"
#define ERR_MSG_INDEX_NOT_INT "Index must be integer!"
#define ERR_MSG_NEGATIVE_INDEX "Index can't be negative"

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

    Variable::Variable(const int &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const long long &intValue)
    {
        data.intData = new dynamic_int(intValue);
        type = VarType::Int;
    }

    Variable::Variable(const double &floatValue)
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
            os << *(obj.data.boolData);
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

    Variable &Variable::toInt()
    {
        switch (type)
        {
        case VarType::Float:
            *this = Variable(dynamic_int(*(data.floatData)));
            break;

        case VarType::String:
            *this = Variable(dynamic_int(data.stringData->c_str()));
            break;

        case VarType::Bool:
            *this = Variable(int(*(data.boolData)));
            break;

        case VarType::None:
            *this = Variable(0);
            break;

        default:
            break;
        }
        return *this;
    }

    Variable toInt(const Variable &obj)
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
            break;
        }
        return obj;
    }

    Variable &Variable::toFloat()
    {
        switch (type)
        {
        case VarType::Int:
            *this = Variable(data.intData->doubleGetNumber());
            break;

        case VarType::String:
            *this = Variable(std::stod(data.stringData->c_str()));
            break;

        case VarType::Bool:
            *this = Variable(float(*(data.boolData)));
            break;

        case VarType::None:
            *this = Variable(0.0f);
            break;

        default:
            break;
        }
        return *this;
    }

    Variable toFloat(const Variable &obj)
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
            break;
        }
        return obj;
    }

    Variable &Variable::toString()
    {
        switch (type)
        {
        case VarType::Int:
            *this = Variable(data.intData->strGetNumber());
            break;

        case VarType::Float:
            *this = Variable(std::to_string(*(data.floatData)).c_str());
            break;

        case VarType::Bool:
            *this = Variable(std::to_string(*(data.boolData)).c_str());
            break;

        case VarType::None:
            *this = Variable("");
            break;

        default:
            break;
        }
        return *this;
    }

    Variable toString(const Variable &obj)
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
            return Variable(std::to_string(*(obj.getData().boolData)).c_str());
            break;

        case VarType::None:
            return Variable("");
            break;

        default:
            break;
        }
        return obj;
    }

    Variable &Variable::toBool()
    {
        switch (type)
        {
        case VarType::Int:
            *this = Variable(bool(data.intData->longLongGetNumber()));
            break;

        case VarType::Float:
            *this = Variable(bool(*(data.floatData)));
            break;

        case VarType::String:
            *this = Variable((*(data.stringData)) == "" ? false : true);
            break;

        case VarType::None:
            *this = Variable(false);
            break;

        default:
            break;
        }
        return *this;
    }

    Variable toBool(const Variable &obj)
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
            break;
        }
        return obj;
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
        return !(*(kondra::toBool(*this).data.boolData));
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

    char &Variable::at(const Variable &index)
    {
        if (type != VarType::String)
        {
            throw std::invalid_argument(ERR_MSG_NOT_STRING);
        }
        else if (index.getType() != VarType::Int)
        {
            throw std::invalid_argument(ERR_MSG_INDEX_NOT_INT);
        }
        else if (index < Variable(0))
        {
            throw std::invalid_argument(ERR_MSG_NEGATIVE_INDEX);
        }
        return data.stringData->at(index.getData().intData->uLongLongGetNumber());
    }

    char &Variable::operator[](const Variable &index)
    {
        return at(index);
    }

    Variable::operator long long() const
    {
        return kondra::toInt(*this).data.intData->longLongGetNumber();
    }

    Variable::operator unsigned long long() const
    {
        return kondra::toInt(*this).data.intData->uLongLongGetNumber();
    }

    Variable::operator bool() const
    {
        return *(kondra::toBool(*this).data.boolData);
    }

    Variable::operator string() const
    {
        return *(kondra::toString(*this).data.stringData);
    }

    Variable::operator double() const
    {
        return *(kondra::toFloat(*this).data.floatData);
    }

    Variable::operator dynamic_int() const
    {
        return *(kondra::toInt(*this).data.intData);
    }

    bool operator&&(const Variable &var1, const Variable &var2)
    {
        return *(toBool(var1).data.boolData) && *(toBool(var2).data.boolData);
    }

    bool operator||(const Variable &var1, const Variable &var2)
    {
        return *(toBool(var1).data.boolData) || *(toBool(var2).data.boolData);
    }

}