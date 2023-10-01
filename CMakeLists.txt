cmake_minimum_required(VERSION 3.10)
project( 
        tinypdf
        LANGUAGES CXX 
       )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER /bin/clang)

# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE SOURCES src/*.c**)
file(GLOB_RECURSE HEADERS include/*.h**)

message("> Searching for QT...")
find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets Pdf)
find_package    (Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Pdf)

if(QT_FOUND)
    add_compile_definitions(USE_GUI)
    if(QT_VERSION_MAJOR GREATER_EQUAL 6)
        qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${SOURCES} ${HEADERS})
        qt_finalize_executable(${PROJECT_NAME})
    else()
        add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
    endif()
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Pdf)
else()
    message(FATAL_ERROR "> QT not found")
endif()