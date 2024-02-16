#ifndef Scopes_HPP
#define Scopes_HPP

#include "Variables.hpp"
#include <list>

class Scopes
{
private:
    static std::list<Variables *> variables;
public:
    static void initGlobalScope();
    static Value * get(const std::string &);
    static void set(const std::string &, Value *);
    static void create(const std::string &, const std::string &, const bool &, const bool &, Value *);
    static void addScope();
    static void deleteScope();
};

std::list<Variables *> Scopes::variables;

void Scopes::initGlobalScope()
{
    variables.push_front(
        new Variables({
            {"_I8_MAX_", new I8Value(std::numeric_limits<signed char>::max(), true)},
            {"_I8_MIN_", new I8Value(std::numeric_limits<signed char>::min(), true)},
            {"_I16_MAX_", new I16Value(std::numeric_limits<short>::max(), true)},
            {"_I16_MIN_", new I16Value(std::numeric_limits<short>::min(), true)},
            {"_I32_MAX_", new I32Value(std::numeric_limits<int>::max(), true)},
            {"_I32_MIN_", new I32Value(std::numeric_limits<int>::min(), true)},
            {"_I64_MAX_", new I64Value(std::numeric_limits<long long>::max(), true)},
            {"_I64_MIN_", new I64Value(std::numeric_limits<long long>::min(), true)},
            {"_UI8_MAX_", new UI8Value(std::numeric_limits<unsigned char>::max(), true)},
            {"_UI16_MAX_", new UI16Value(std::numeric_limits<unsigned short>::max(), true)},
            {"_UI32_MAX_", new UI32Value(std::numeric_limits<unsigned int>::max(), true)},
            {"_UI64_MAX_", new UI64Value(std::numeric_limits<unsigned long long>::max(), true)},
            {"_INF_", new F64Value(std::numeric_limits<double>::infinity(), true)},
            {"_NAN_", new F64Value(std::numeric_limits<double>::quiet_NaN(), true)},
            {"_NULL_", new I64Value(0ull, true)},
            {"_ENDL_", new StrValue("\n", true)},
            {"_NONE_", new VarValue(kondra::var(), true)},
        })
    );
}

Value *Scopes::get(const std::string &key)
{
    for (auto variable : variables)
    {
        if (variable->isVariableExist(key))
        {
            return variable->get(key);
        }
    }
    throw std::runtime_error(ERR_MSG_UNKN_ID);
}

void Scopes::set(const std::string &key, Value *value)
{
    for (auto variable : variables)
    {
        if (variable->isVariableExist(key))
        {
            variable->set(key, value);
            return;
        }
    }
    throw std::runtime_error(ERR_MSG_UNKN_ID);
}

void Scopes::create(const std::string &type, const std::string &key, const bool &isGlobal, 
    const bool &isConst, Value *value)
{
    auto scope = isGlobal ? std::prev(variables.end()) : variables.begin();
    if ((*scope)->isVariableExist(key))
        throw std::runtime_error("Variable with same identifier already exist in this scope");
    (*scope)->create(type, key, isConst, value);
}

void Scopes::addScope()
{
    variables.push_front(new Variables());
}

void Scopes::deleteScope()
{
    delete *variables.begin();
    variables.pop_front();
}

#endif