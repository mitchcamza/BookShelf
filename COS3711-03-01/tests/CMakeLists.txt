cmake_minimum_required(VERSION 3.5)

project(UnitTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(UNIT_TEST_SOURCES
    tst_author.h tst_author.cpp
    testbook.h testbook.cpp
    testbooktablemodel.h testbooktablemodel.cpp
)

add_executable(UnitTests ${UNIT_TEST_SOURCES}
    main.cpp
)

# Link the library from the main project and set include directories
target_link_libraries(UnitTests PRIVATE MyProjectLib Qt${QT_VERSION_MAJOR}::Test)

# Include directories for the tests
target_include_directories(UnitTests PRIVATE ${CMAKE_SOURCE_DIR}/../src)

# Add tests
add_test(NAME UnitTests COMMAND UnitTests)
