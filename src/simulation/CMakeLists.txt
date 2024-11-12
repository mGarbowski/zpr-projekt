set(SIMULATION_SOURCES
        Size.h
        Position.h
        Rect.h
        CarSimulation.cc
        CarSimulation.h
        Utils.cc
        Utils.h
        RectRot.h
        CircleRot.h
        CarBody.h
        CarBody.cc
        CarDescription.h
        CarDescription.cc
)
add_library(simulation ${SIMULATION_SOURCES})
target_link_libraries(simulation box2d)
target_include_directories(simulation INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})