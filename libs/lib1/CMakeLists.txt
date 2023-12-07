# Create a library called "lib1" which includes the source file "lib1.cpp" (For "ar <obj_file>" in makefile)
add_library(lib1 STATIC lib1.cpp)

target_include_directories(lib1 INTERFACE # Only source files for building lib1's consumers(Parent lib or final target) can see the header files
    ${CMAKE_CURRENT_SOURCE_DIR} # The directory where current CMakeLists.txt is located
)
