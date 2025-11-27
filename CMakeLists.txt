cmake_minimum_required(VERSION 3.16)
project(QtGuiSample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
endif()

if(Qt6_FOUND)
    set(QT_PREFIX Qt6)
else()
    set(QT_PREFIX Qt5)
endif()

set(SRC_FILES src/main.cpp)

add_executable(QtGuiSample ${SRC_FILES})
target_link_libraries(QtGuiSample PRIVATE ${QT_PREFIX}::Widgets)

if(WIN32)
    set_target_properties(QtGuiSample PROPERTIES WIN32_EXECUTABLE ON)
endif()


