#include "compiler/headers/io/kondraio.hpp"
#include <iostream>


using namespace kondra;

int main()
{
    dynamic_int n = "435345534";
    string str = to_string(435345534);
    print(std::format("Num is {}", str));
    return 0;
}