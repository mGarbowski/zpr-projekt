set(SIMULATION_SOURCES
        Simulation.cc
        Simulation.h
        Size.h
        Position.h
        Rect.h
)
add_library(simulation ${SIMULATION_SOURCES})
target_link_libraries(simulation evolution box2d)
target_include_directories(simulation INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})