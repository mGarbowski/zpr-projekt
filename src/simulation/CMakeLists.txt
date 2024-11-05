set(SIMULATION_SOURCES
        BoxesSimulation.cc
        BoxesSimulation.h
        Size.h
        Position.h
        Rect.h
        CarSimulation.cc
        CarSimulation.h
        Utils.cc
        Utils.h
        RectRot.h
)
add_library(simulation ${SIMULATION_SOURCES})
target_link_libraries(simulation box2d)
target_include_directories(simulation INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})