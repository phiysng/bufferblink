cmake_minimum_required(VERSION 3.20)

project(bufferblink)

include(CTest)
include(FetchContent)
include(cmake/protobuf_static.cmake)
add_protobuf_static()

option(USE_PROTOBUF_FROM_SOURCE "link protobuf build from source." OFF)

if(${USE_PROTOBUF_FROM_SOURCE})
add_subdirectory(protobuf-3.19.3/cmake)
endif()

FetchContent_Declare(
        doctest
        GIT_REPOSITORY "https://github.com/onqtam/doctest"
        GIT_TAG "932a2ca50666138256dae56fbb16db3b1cae133a"
        LOG_DOWNLOAD ON
)
FetchContent_MakeAvailable(doctest)

add_subdirectory(common)
add_subdirectory(bufferflip)
add_subdirectory(bufferflop)
add_subdirectory(buffertest)