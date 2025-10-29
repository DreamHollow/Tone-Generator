cmake_minimum_required(VERSION 3.25.1)
project(tonegenerator LANGUAGES CXX)
find_package(SFML 2 REQUIRED COMPONENTS graphics system audio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE true)
set(SFML_STATIC_LIBRARIES true)

add_executable(${PROJECT_NAME} src/Main.cpp
)

# sfml graphics and system not technically necessary
# but if you want to program in a visualizer you may
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio)

include_directories(include)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

if(UNIX)
   message(STATUS UNIX_build.)
endif()

if(WIN32)
   message(STATUS WIN32_build.)
endif()

# Auto-generated comment:
# This list made with CMakeEasy.
