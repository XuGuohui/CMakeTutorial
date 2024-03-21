Navigate to the `build` directory:

# Configure the project
- `cmake <path/to/top/CMakeLists.txt>`: Configures the build system, which includes generating makefiles and other intermediate files for building the project.

- `cmake <path/to/top/CMakeLists.txt> -D<option=ON/OFF>`: Configures the build system with given options to override the option() variables in CMakeLists.txt files.

# Build the project
`cmake --build <path/to/build/system>`: Build the project, which involes compiler and linker.