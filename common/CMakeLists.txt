cmake_minimum_required(VERSION 3.21)

project(common)

file(GLOB PROTOBUF_DEFINITION_FILES "${PROJECT_SOURCE_DIR}/proto/*.proto")

foreach(file ${PROTOBUF_DEFINITION_FILES})
    execute_process(COMMAND ../binary/protoc -I "${PROJECT_SOURCE_DIR}/proto/" ${file} --cpp_out=./generated
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            RESULT_VARIABLE PROTOBUF_RESULT
            OUTPUT_VARIABLE PROTOBUF_OUTPUT_VARIABLE)
            MESSAGE( STATUS "generate proto RESULT_VARIABLE:" ${PROTOBUF_RESULT})
            MESSAGE( STATUS "generate proto OUTPUT_VARIABLE:" ${PROTOBUF_OUTPUT_VARIABLE})
endforeach()

file(GLOB PROTOBUF_MODELS_INCLUDES "generated/*.pb.cc" "generated/*.hpp")

# subproject for shared protobuf files.
add_library(${PROJECT_NAME} ${PROTOBUF_MODELS_INCLUDES})
target_link_libraries(${PROJECT_NAME} PUBLIC protobuf_3_19_3)
target_include_directories(${PROJECT_NAME} PUBLIC generated/)
set_property(TARGET ${PROJECT_NAME} PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")