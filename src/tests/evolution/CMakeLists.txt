set(EVOLUTION_TEST_SOURCES EvolutionUnitTest.cc
        SpecimenUnitTest.cc
        mutation/GaussianMutationSchemeUnitTest.cc
        reproduction/ProportionalReproductionSchemeUnitTest.cc)
add_executable(evolution_tests ${EVOLUTION_TEST_SOURCES})
target_link_libraries(evolution_tests PUBLIC evolution GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(evolution_tests)