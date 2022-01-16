cmake_minimum_required(VERSION 3.16)

project(bufferblink)

include(cmake/protobuf_static.cmake)
add_protobuf_static()

option(USE_PROTOBUF_FROM_SOURCE "link protobuf build from source." OFF)

if(${USE_PROTOBUF_FROM_SOURCE})
add_subdirectory(protobuf-3.19.3/cmake)
endif()

add_subdirectory(common)
# use protobuf from source file
add_subdirectory(bufferflip)
# use imported protobuf library
add_subdirectory(bufferflop)