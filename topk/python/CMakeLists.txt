find_package(Python3 REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIR})

add_library(py_bindings SHARED py_bindings.cpp)
target_link_libraries(py_bindings ${PYTHON_LIBRARY})
set_target_properties(
    py_bindings
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME "topk"
        LINKER_LANGUAGE CXX
    )
