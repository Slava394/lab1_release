cmake_minimum_required(VERSION 3.28.3)

project(SmartPtr)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON) 

set(CMAKE_AUTORCC ON) 

set(CMAKE_AUTOUIC ON) 

include(CTest)

add_subdirectory(test)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(SmartPtr
    main.cpp
    MainWindow.hpp
    MainWindow.cpp
    sequences/ListSequence.hpp
)

target_link_libraries(SmartPtr Qt6::Widgets)