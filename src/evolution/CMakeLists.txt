set(EVOLUTION_SOURCES Evolution.cc
        docs.h
        Specimen.h
        Specimen.cc
        MutationScheme.cc
        MutationScheme.h
)
add_library(evolution ${EVOLUTION_SOURCES})
target_link_libraries(evolution common)
target_include_directories(evolution INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})