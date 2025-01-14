set(SIMULATION_SOURCES
        Size.h
        Rect.h
        CarSimulation.cc
        CarSimulation.h
        Utils.cc
        Utils.h
        CircleRot.h
        CarChassis.h
        CarChassis.cc
        Docs.h
        RoadModel.cpp
        RoadModel.h
        TriangleRot.cc
        TriangleRot.h
)
add_library(simulation ${SIMULATION_SOURCES})
target_link_libraries(simulation common road box2d)
target_include_directories(simulation INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})