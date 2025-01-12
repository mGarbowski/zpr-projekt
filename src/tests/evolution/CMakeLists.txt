set(EVOLUTION_TEST_SOURCES EvolutionUnitTest.cc
        SpecimenUnitTest.cc
        mutation/GaussianMutationSchemeUnitTest.cc
        reproduction/ProportionalReproductionSchemeUnitTest.cc
        succession/GenerationSuccessionUnitTest.cc
        TestUtils.cc
        TestUtils.h)
add_executable(evolution_tests ${EVOLUTION_TEST_SOURCES})

target_link_libraries(evolution_tests PUBLIC evolution GTest::gtest_main)
target_compile_options(evolution_tests PRIVATE -coverage)
target_link_options(evolution_tests PRIVATE -coverage)

include(GoogleTest)
gtest_discover_tests(evolution_tests)