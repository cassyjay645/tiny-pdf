cmake_minimum_required(VERSION 3.10)
project( 
        tinypdf
        LANGUAGES CXX 
       )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER /bin/clang)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE SOURCES src/*.c** src/*.ui)
file(GLOB_RECURSE HEADERS include/*.h**)
message("> Searching for QT...")
message(WARNING "> Qt5 is temporarily disabled")
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Pdf)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Pdf PdfWidgets Gui)

if(QT_FOUND)
    add_compile_definitions(USE_GUI)
    qt_standard_project_setup()
    message("> Using Qt${QT_VERSION}...")
    message("> Sources: ${SOURCES}")
    message("> Headers: ${HEADERS}")

    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${SOURCES} ${HEADERS})

    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY
        QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE
                        Qt${QT_VERSION_MAJOR}::Core 
                        Qt${QT_VERSION_MAJOR}::Widgets 
                        Qt${QT_VERSION_MAJOR}::Pdf 
                        Qt${QT_VERSION_MAJOR}::Gui
                        Qt${QT_VERSION_MAJOR}::PdfWidgets)

    install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    qt_finalize_executable(${PROJECT_NAME})
else()
    message(FATAL_ERROR "> QT not found")
endif()

