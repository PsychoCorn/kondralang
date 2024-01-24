#include "kondra/headers/interpreter/Interpreter.hpp"

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        std::string pathToSourceFile = argv[1];
        Interpreter interpreter(pathToSourceFile);
        interpreter.interpretation();
    }
    else
        std::cout << "kondra has been built" << std::endl;
    return 0;
}