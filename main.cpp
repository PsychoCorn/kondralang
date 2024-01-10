#include "compiler/headers/io/kondraio.hpp"
#include <iostream>


using namespace kondra;

int main()
{
    dynamic_int n = 25;
    char nn = 25;
    //println(std::stoll("54xrthtrhrt}"));
    print(std::format("Num is {:?^5}", n));
    return 0;
}