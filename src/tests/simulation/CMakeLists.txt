set(SIMULATION_TEST_SOURCES SimulationUnitTest.cc
)
add_executable(simulation_tests ${SIMULATION_TEST_SOURCES})
target_link_libraries(simulation_tests PUBLIC simulation GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(simulation_tests)