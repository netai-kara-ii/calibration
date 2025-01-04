# [ cmake build system --config ]

MESSAGE(STATUS "cmake --version: ${CMAKE_VERSION}")
MESSAGE(STATUS "")

cmake_minimum_required(VERSION 3.25)

project(lsvm-calibration
    VERSION 1.0.0
    DESCRIPTION "lsvm-calibration"
    LANGUAGES CXX
)

message(STATUS "${PROJECT_NAME} --version: ${PROJECT_VERSION}")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_compile_options(-Wall -O3 -march=native)

# output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


# Add subdirectories
add_subdirectory(source)
#add_subdirectory(kernels)
#add_subdirectory(testbench)

