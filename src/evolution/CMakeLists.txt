set(EVOLUTION_SOURCES Evolution.cc
        docs.h)
add_library(evolution ${EVOLUTION_SOURCES})
target_include_directories(evolution INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})