#include "../../headers/types/String.hpp"

namespace kondra
{

String::String(const char* s) : std::string(s) {}

String::String(const std::string& s) : std::string(s) {}

String::String(const String& s) : std::string(s) {}

}