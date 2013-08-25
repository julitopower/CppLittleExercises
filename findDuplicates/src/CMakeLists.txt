# Specify your header and source files
set(LIB_HDR FindDuplicates.hpp)
set(LIB_SRC Application.cpp
        FindDuplicates.cpp)
set(LIB ${LIB_SRC} ${LIB_HDR})
set(APP Application.cpp)

# Generate a library to be used by the executable
add_library(findDuplicatesLib ${LIB})

# Generate executable
add_executable(findDuplicates ${APP})
target_link_libraries(findDuplicates findDuplicatesLib)

