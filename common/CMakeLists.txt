cmake_minimum_required(VERSION 3.21)

project(common)

include(../cmake/generate_proto.cmake)
generate_proto(PROTOBUF_MODELS_INCLUDES)

# subproject for shared protobuf files.
add_library(${PROJECT_NAME} ${PROTOBUF_MODELS_INCLUDES})

if(${USE_PROTOBUF_FROM_SOURCE})
set(protobuf_version protobuf::libprotobuf)
else()
set(protobuf_version protobuf_3_19_3)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC ${protobuf_version})
target_include_directories(${PROJECT_NAME} PUBLIC generated/)
set_property(TARGET ${PROJECT_NAME} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")