#ifndef ListOfVariables_HPP
#define ListOfVariables_HPP

#include <unordered_map>
#include <string>

enum Type
{
    Int8,
    Int16,
    Int32,
    Int64,
    UInt8,
    UInt16,
    UInt32,
    UInt64,
    Int,
    Float32,
    Float64,
    Float80,
    Bool,
    String,
    Var,
    None //doesn't exist
};

class ListOfVariables
{
private:
    static std::unordered_map<std::string, Type> listOfVariables;
public:
    static Type getType(std::string); // returns type of variable if id exist and None if id doesn't exist
    static void setType(std::string, Type);
    static std::unordered_map<std::string, Type> getList();
    
};


#endif