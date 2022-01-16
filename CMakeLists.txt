cmake_minimum_required(VERSION 3.16)

project(bufferblink)

include(cmake/protobuf_static.cmake)
add_protobuf_static()

add_subdirectory(protobuf-3.19.3/cmake)
# use protobuf from source file
add_subdirectory(bufferflip)
# use imported protobuf library
add_subdirectory(bufferflop)