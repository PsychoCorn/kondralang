cmake_minimum_required(VERSION 3.10)

project(kondraLang)

set(CMAKE_CXX_STANDARD 23)
add_subdirectory(kondra/src)
add_executable(kondra main.cpp)

target_link_libraries(kondra kondra_lib)
 