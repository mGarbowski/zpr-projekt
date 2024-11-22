set(ROAD_SOURCES Road.cc RoadStatic.cpp RoadStatic.h)
add_library(road ${ROAD_SOURCES})
target_include_directories(road INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})