set(VISUALISATION_SOURCES
        Docs.h
        VisualisationUtils.h
        VisualisationUtils.cc
)
add_library(visualisation ${VISUALISATION_SOURCES})
target_link_libraries(visualisation common simulation sfml-graphics)
target_include_directories(visualisation INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})