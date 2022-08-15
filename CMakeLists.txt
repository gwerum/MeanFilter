
project(MeanFilter) # Mandatory. 
cmake_minimum_required(VERSION 3.1) # Mandatory. 
set(CMAKE_CXX_STANDARD 14) # Use c++14.

# Set build type if not set. 
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Set additional flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra") # -Wall -Wextra: show all warnings
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0") # -g: keep debug information in binary, --coverage: Emits code coverage data for gcovr
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # -O<num>: optimization level in {0, 1, 2, 3}: 0: no optimization 3: full optimization

# tell cmake to output binaries here: 
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) # tell cmake where to look for *.h files 
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
