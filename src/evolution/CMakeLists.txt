set(EVOLUTION_SOURCES Evolution.cc)
add_library(evolution ${EVOLUTION_SOURCES})
target_include_directories(evolution INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})