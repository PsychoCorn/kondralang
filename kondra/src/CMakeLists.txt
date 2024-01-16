add_subdirectory(types)
add_subdirectory(parser)
add_subdirectory(ast)
add_subdirectory(lib)

add_library(kondra_lib STATIC
    $<TARGET_OBJECTS:types> 
    $<TARGET_OBJECTS:parser> 
    $<TARGET_OBJECTS:ast> 
    $<TARGET_OBJECTS:lib>
)
