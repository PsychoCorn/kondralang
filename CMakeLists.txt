cmake_minimum_required(VERSION 3.10)

project(kondraLang)

set(CMAKE_CXX_STANDARD 23)

set(GMP_DIR C:/msys64/mingw64/include)

find_path(GMP_INCLUDE_DIR gmp.h)
find_library(GMP_LIBRARY gmp)

add_library(dynamic_integer compiler/src/types/DynamicInteger.cpp)
add_library(variable compiler/src/types/Variable.cpp)
add_library(str compiler/src/types/String.cpp)
add_executable(kondra main.cpp)

target_link_libraries(kondra variable dynamic_integer str gmp gmpxx)
 