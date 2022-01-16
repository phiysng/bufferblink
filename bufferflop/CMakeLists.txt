cmake_minimum_required(VERSION 3.21)
project(bufferflop)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} protobuf_3_19_3)
set_property(TARGET ${PROJECT_NAME} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")