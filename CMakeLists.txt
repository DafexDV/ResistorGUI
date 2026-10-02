cmake_minimum_required(VERSION 3.16)

project(ResistorGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

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

target_link_libraries(ResistorGUI PRIVATE
    Qt6::Widgets
)

set_target_properties(ResistorGUI PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
