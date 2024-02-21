#ifndef Functions_HPP
#define Functions_HPP

#include "functions/functions.hpp"
#include <unordered_map>

#define ERR_MSG_UNKN_ID "Unknown identifier"
#define functionHashMap std::unordered_map<std::string, std::unordered_map<size_t, Function *>> 

class Functions
{
private:
    static functionHashMap functions;
    static const size_t dynamicNumOfArgs = -1;
    
public:

    static Function * get(const std::string &, const size_t &);
    static void set(const std::string &, const size_t &, Function *);
    static bool isFunctionExist(const std::string &, const size_t &);
};

const size_t Functions::dynamicNumOfArgs;

functionHashMap Functions::functions = {
    {"toInt", {
            {0, new ToInt0()}, 
            {1, new ToInt1()}, 
            {2, new ToInt2()}
        }
    },
    {"toFloat", {
            {0, new ToFloat0()}, 
            {1, new ToFloat1()}
        }
    },
    {"toString", {
            {0, new ToString0()}, 
            {1, new ToString1()}
        }
    },
    {"toBoolean", {
            {0, new ToBoolean0()}, 
            {1, new ToBoolean1()}
        }
    },
    {"print", {
            {dynamicNumOfArgs, new Print()}
        }
    },
    {"println", {
            {0, new Println0()}, 
            {dynamicNumOfArgs, new Println()},
        }
    },
    {"input", {
            {0, new Input0()}, 
            {1, new Input1()}
        }
    },
    {"format", {
            {dynamicNumOfArgs, new Format()}
        }
    },
    {"toBase", {
            {2, new ToBase2()}
        }
    },
    {"newMut", {
            {1, new New1()}
        }
    },
    {"isNullRef", {
            {1, new IsNullRef1()}
        }
    },
    {"free", {
            {dynamicNumOfArgs, new Free()}
        }
    },
    {"delete", {
            {dynamicNumOfArgs, new Delete()}
        }
    },
    {"size", {
            {1, new Size1()}
        }
    },
    {"iterSet", {
            {2, new IterSet2()}
        }
    },
    {"iterGet", {
            {1, new IterGet1()}
        }
    },
    {"begin", {
            {1, new Begin1()}
        }
    },
    {"rbegin", {
            {1, new RBegin1()}
        }
    },
    {"end", {
            {1, new End1()}
        }
    },
    {"rend", {
            {1, new REnd1()}
        }
    },
};

Function *Functions::get(const std::string &key, const size_t &numOfArgs)
{
    if (isFunctionExist(key, numOfArgs))
        return functions[key][numOfArgs];
    else if (isFunctionExist(key, dynamicNumOfArgs))
        return functions[key][dynamicNumOfArgs];
    throw std::runtime_error(ERR_MSG_UNKN_ID);
}

bool Functions::isFunctionExist(const std::string& key, const size_t &numOfArgs)
{
    if (functions.find(key) == functions.end())
        return false;
    return functions[key].find(numOfArgs) != functions[key].end();
}

void Functions::set(const std::string &key, const size_t &numOfArgs, Function *func)
{
    functions[key][numOfArgs] = func;
}

#endif