set(GMP_DIR C:/msys64/mingw64/include)

find_path(GMP_INCLUDE_DIR gmp.h)
find_library(GMP_LIBRARY gmp)

add_library(types Variable.cpp DynamicInteger.cpp String.cpp)
target_link_libraries(types gmp gmpxx)