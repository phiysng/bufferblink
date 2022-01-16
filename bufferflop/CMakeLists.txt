cmake_minimum_required(VERSION 3.21)
project(bufferflop)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} common)
set_property(TARGET ${PROJECT_NAME} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")