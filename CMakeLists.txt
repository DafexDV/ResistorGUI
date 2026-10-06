cmake_minimum_required(VERSION 3.16)

project(ResistorGUI
    LANGUAGES CXX
)

set(PROJECT_VERSION 0.0.1-02102026)
set(PROJECT_AUTHOR "DafexDV")
set(PROJECT_LICENSE "GPLv3")
set(PROJECT_DESCRIPTION "GUI for calculating resistor values")
set(PROJECT_GITHUB "https://github.com/DafexDV/ResistorGUI")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(GENERATED_INCLUDE_DIR
    ${CMAKE_CURRENT_BINARY_DIR}/generated
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildInfo.hpp.in
    ${GENERATED_INCLUDE_DIR}/BuildInfo.hpp
    @ONLY
)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)
file(GLOB_RECURSE HEADERS
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/include/*.hpp
)

add_executable(ResistorGUI
    ${SOURCES}
    ${HEADERS}
    resources.qrc
)

target_include_directories(ResistorGUI PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(ResistorGUI PRIVATE
    ${GENERATED_INCLUDE_DIR}
)

target_link_libraries(ResistorGUI PRIVATE
    Qt6::Widgets
)

include(GNUInstallDirs)

install(TARGETS ResistorGUI
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
