# Create a library called "lib2" which includes the source file "lib2.cpp" (For "ar <obj_file>" in makefile)
add_library(lib3 STATIC func.cpp)

# Target name followed by path to header files (For "cc -I<path_to_header_file_dir>" in makefile)
# The paths are PUBLIC, so we don't need to specify the paths in top CMakeLists.txt
target_include_directories(lib3 PUBLIC
    "."
    "./inc"
)

# Need to use --fresh to re-configure the build system to take effect,
# otherwise, we have to explicitly specify the option value (-DUSE_FUNC1=ON/OFF) when configuring the build system.
option(USE_FUNC1 "Use myFunc1()" OFF)

if (USE_FUNC1)
    # Add a compile definition (For "cc -D<macro_name>" in makefile)
    target_compile_definitions(lib3 PUBLIC "USE_FUNC1")

    #1 One way to conditionally compile the dependdent source files
    # Just add the source files to lib3
    target_sources(lib3 PUBLIC
        src/func1.cpp
    )
else()
    #2 Another way to conditionally compile the dependdent source files
    # Create a new library and link it onto lib3
    add_library(libfunc2 STATIC src/func2.cpp)
    target_link_libraries(lib3 PUBLIC libfunc2)
    target_include_directories(libfunc2 PUBLIC
        "./inc"
    )
endif()
