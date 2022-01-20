function (generate_proto output_required_files)

file(GLOB PROTOBUF_DEFINITION_FILES "${PROJECT_SOURCE_DIR}/proto/*.proto")
foreach(file ${PROTOBUF_DEFINITION_FILES})
    execute_process(COMMAND ../binary/protoc -I "${PROJECT_SOURCE_DIR}/proto/" ${file} --cpp_out=./generated
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            RESULT_VARIABLE PROTOBUF_RESULT
            OUTPUT_VARIABLE PROTOBUF_OUTPUT_VARIABLE)
            MESSAGE( STATUS "generate proto RESULT_VARIABLE:" ${PROTOBUF_RESULT})
            MESSAGE( STATUS "generate proto OUTPUT_VARIABLE:" ${PROTOBUF_OUTPUT_VARIABLE})
endforeach()
file(GLOB PROTOBUF_MODELS_INCLUDES "generated/*.pb.cc" "generated/*.h")
set(${output_required_files} ${PROTOBUF_MODELS_INCLUDES} PARENT_SCOPE)
endfunction()