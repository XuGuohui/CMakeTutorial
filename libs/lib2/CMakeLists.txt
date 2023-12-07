# Create a library called "lib2" which includes the source file "lib2.cpp" (For "ar <obj_file>" in makefile)
add_library(lib2 STATIC src/lib2.cpp)

# Target name followed by path to header files (For "cc -I<path_to_header_file_dir>" in makefile)
# The paths are PUBLIC, so we don't need to specify the paths in top CMakeLists.txt
target_include_directories(lib2 PUBLIC
    "./inc"
)

# Need to use --fresh to re-configure the build system to take effect,
# otherwise, we have to explicitly specify the option value (-DUSE_ACCUMULATE=ON/OFF) when configuring the build system.
option(USE_ACCUMULATE "Use std::accumulate() function" OFF)

if (USE_ACCUMULATE)
    # Add a compile definition (For "cc -D<macro_name>" in makefile)
    target_compile_definitions(lib2 PUBLIC "USE_STD_ACCUMULATE")
endif()
