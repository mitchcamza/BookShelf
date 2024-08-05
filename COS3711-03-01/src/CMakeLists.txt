cmake_minimum_required(VERSION 3.5)

project(COS3711-03-01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    resources.qrc
    mainwindow.h mainwindow.cpp
    author.h author.cpp
    book.h book.cpp
    bookinput.h bookinput.cpp
)

# Create library
add_library(MyProjectLib ${PROJECT_SOURCES}
    booktablemodel.h booktablemodel.cpp)

# Include directories for the library
target_include_directories(MyProjectLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the library to the executable
target_link_libraries(MyProjectLib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Create the main executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(COS3711-03-01
        MANUAL_FINALIZATION
        main.cpp
    )
else()
    if(ANDROID)
        add_library(COS3711-03-01 SHARED
            main.cpp
        )
    else()
        add_executable(COS3711-03-01
            main.cpp
        )
    endif()
endif()

target_link_libraries(COS3711-03-01 PRIVATE MyProjectLib Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(COS3711-03-01 PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS COS3711-03-01
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(COS3711-03-01)
endif()
