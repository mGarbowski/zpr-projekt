set(EVOLUTION_SOURCES Evolution.cc
        Docs.h
        Specimen.h
        Specimen.cc
        mutation/MutationScheme.cc
        mutation/MutationScheme.h
        mutation/GaussianMutationScheme.cc
        mutation/GaussianMutationScheme.h
        reproduction/ReproductionScheme.cc
        reproduction/ReproductionScheme.h
        reproduction/ProportionalReproductionScheme.cc
        reproduction/ProportionalReproductionScheme.h
        succession/SuccessionScheme.cc
        succession/SuccessionScheme.h
        succession/GenerationSuccessionScheme.cc
        succession/GenerationSuccessionScheme.h
        mutation/NoMutationScheme.cc
        mutation/NoMutationScheme.h
        mutation/MutationSchemeFactory.cc
        mutation/MutationSchemeFactory.h
        reproduction/TournamentReproductionScheme.cc
        reproduction/TournamentReproductionScheme.h
        reproduction/ReproductionSchemeFactory.cc
        reproduction/ReproductionSchemeFactory.h
        reproduction/RandomReproductionScheme.cc
        reproduction/RandomReproductionScheme.h
        succession/ElitistSuccessionScheme.cc
        succession/ElitistSuccessionScheme.h
        succession/SuccessionSchemeFactory.cc
        succession/SuccessionSchemeFactory.h
        crossover/CrossoverScheme.cc
        crossover/CrossoverScheme.h
        crossover/CrossoverSchemeFactory.cc
        crossover/CrossoverSchemeFactory.h
        crossover/NoCrossoverScheme.cc
        crossover/NoCrossoverScheme.h crossover/TwoPointCrossoverScheme.cc crossover/TwoPointCrossoverScheme.h)
add_library(evolution ${EVOLUTION_SOURCES})
target_link_libraries(evolution common)
target_include_directories(evolution INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})