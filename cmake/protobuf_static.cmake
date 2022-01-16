function (add_protobuf_static)
    message("define precompiled protobuf_library")
    add_library(protobuf_3_19_3 STATIC IMPORTED GLOBAL)
    set_target_properties(protobuf_3_19_3 PROPERTIES
        IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/third_party/lib_x64/protobuf/Debug/libprotobufd.lib"
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/third_party/lib_x64/protobuf/RelWithDebInfo/libprotobuf.lib"
        IMPORTED_CONFIGURATIONS "RELEASE;DEBUG"
        )
    target_include_directories(protobuf_3_19_3 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/third_party/include/protobuf")
endfunction()