# CMake file composition


cmake_minimum_required(VERSION 3.25)

# Project summary
project(
    calibration
    DESCRIPTION "C++ Heston LSVM Calibration"
    VERSION 0.0.1
    LANGUAGES CXX
)

# Project settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags (all warnings, O3 optimisation, native arch)
add_compile_options(-Wall -O3 -march=native)

# Manage output directory 
set(CMAKE_RUNIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Manage include file search directories
include_directories(
    /usr/include
    /usr/include/boost
    /usr/include/benchmark
    /usr/include/eigen3
    /usr/inlude/lapacke
    /usr/include/openblas
)

# Manage link file search directories
link_directories(/usr/lib)



# Add subdirectories
#add_subdirectory(src)
#add_subdirectory(testbench)
