set(EVOLUTION_TEST_SOURCES EvolutionUnitTest.cc
        SpecimenUnitTest.cc
        mutation/GaussianMutationSchemeUnitTest.cc
        reproduction/ProportionalReproductionSchemeUnitTest.cc
        succession/GenerationSuccessionUnitTest.cc
        TestUtils.cc
        TestUtils.h
        reproduction/TournamentReproductionSchemeUnitTest.cc
        reproduction/RandomReproductionSchemeUnitTests.cc
        succession/ElitistSuccessionUnitTest.cc
        crossover/TwoPointCrossoverSchemeUnitTest.cc
        crossover/NoCrossoverSchemeUnitTest.cc)
add_executable(evolution_tests ${EVOLUTION_TEST_SOURCES})
target_link_libraries(evolution_tests PUBLIC evolution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(evolution_tests)