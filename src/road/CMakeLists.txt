set(ROAD_SOURCES Road.cc StaticRoadGenerator.cc StaticRoadGenerator.h
        Road.h RoadGenerator.h
        Docs.h PerlinRoadGenerator.cc PerlinRoadGenerator.h)
add_library(road ${ROAD_SOURCES})
target_include_directories(road INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})