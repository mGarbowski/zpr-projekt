set(COMMON_TEST_SOURCES
    CarDescriptionUnitTest.cc
        PositionUnitTest.cc
)
add_executable(common_tests ${COMMON_TEST_SOURCES})

target_link_libraries(common_tests PUBLIC common GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(common_tests)