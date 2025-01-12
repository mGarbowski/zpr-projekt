set(ROAD_TEST_SOURCES StaticRoadGeneratorTest.cc
        PerlinRoadGenerator.cc)
add_executable(road_tests ${ROAD_TEST_SOURCES})
target_link_libraries(road_tests PUBLIC road GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(road_tests)