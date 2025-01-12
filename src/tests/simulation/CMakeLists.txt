set(SIMULATION_TEST_SOURCES
        CarChassisTest.cc
)
add_executable(simulation_tests ${SIMULATION_TEST_SOURCES})

target_link_libraries(simulation_tests PUBLIC simulation GTest::gtest_main)
target_compile_options(simulation_tests PRIVATE -coverage)
target_link_options(simulation_tests PRIVATE -coverage)

include(GoogleTest)
gtest_discover_tests(simulation_tests)