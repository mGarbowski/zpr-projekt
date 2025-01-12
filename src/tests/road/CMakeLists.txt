set(ROAD_TEST_SOURCES StaticRoadGeneratorTest.cc)
add_executable(road_tests ${ROAD_TEST_SOURCES})
target_link_libraries(road_tests PUBLIC road GTest::gtest_main)
target_compile_options(road_tests PRIVATE -coverage)
target_link_options(road_tests PRIVATE -coverage)

include(GoogleTest)
gtest_discover_tests(road_tests)