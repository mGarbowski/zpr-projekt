set(SIMULATION_SOURCES Simulation.cc)
add_library(simulation ${SIMULATION_SOURCES})
target_link_libraries(simulation box2d)
target_include_directories(simulation INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})