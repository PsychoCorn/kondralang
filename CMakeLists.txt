cmake_minimum_required(VERSION 3.10)

project(kondraLang)

set(CMAKE_CXX_STANDARD 23)
add_subdirectory(compiler/src/types)
add_subdirectory(compiler/src/parser)
add_subdirectory(compiler/src/ast)
add_executable(kondra main.cpp)

target_link_libraries(kondra types parser ast)
 