cmake_minimum_required(VERSION 3.15)

project(HelloWorld VERSION 1.2.3)

# The file "inc/config.h.in" is relative to the root directory of source code, i.e. the directory containing CMakeLists.txt
# The file "config.h" is relative to the build directory where cmake is run
configure_file(inc/config.h.in config.h)

# set(CMAKE_C_COMPILER /Applications/ARM/bin/arm-none-eabi-gcc)
# set(CMAKE_CXX_COMPILER /Applications/ARM/bin/arm-none-eabi-g++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Process the CMakeLists.txt in the subdirectory in relative to the root directory of source code
# (For "make -c <sub_module>" in makefile)
add_subdirectory(libs/lib1)
add_subdirectory(libs/lib2)
add_subdirectory(libs/lib3)


############ Compiling-Time Options ############
# Target name followed by source files (For "cc <src_file>" in makefile)
# The file "src/main.cpp" is relative to the root directory of source code, i.e. the directory containing CMakeLists.txt
add_executable(HelloWorld src/main.cpp)

# Target name followed by path to header files (For "cc -I<path_to_header_file_dir>" in makefile)
target_include_directories(HelloWorld PUBLIC
    "${PROJECT_BINARY_DIR}" # The build directory where cmake is run
    "${PROJECT_SOURCE_DIR}/inc" # The root directory of source code, i.e. the directory containing CMakeLists.txt
    "${PROJECT_SOURCE_DIR}/libs/lib1"
    # We have specified the paths in sub CMakeLists.txt for lib2 and lib3, so we don't need to specify them here
)


############ Linking-Time Options ############
# Target name followed by libs (For "ld -l<lib>" in makefile)
target_link_libraries(HelloWorld PUBLIC
    lib1 # Defined in CMakeLists.txt in subdirectory
    lib2
    lib3
)
