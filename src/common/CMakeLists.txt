set(COMMON_SOURCES
        CarDescription.h
        CarDescription.cc
        Position.h
        Position.cc
        Docs.h
)
add_library(common ${COMMON_SOURCES})
target_include_directories(common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})