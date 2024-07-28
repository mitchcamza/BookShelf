cmake_minimum_required(VERSION 3.5)
project(COS3711-03-01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Add subdirectories
add_subdirectory(src/)
add_subdirectory(tests/)

# Enable testing
enable_testing()
