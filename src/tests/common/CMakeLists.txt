set(COMMON_TEST_SOURCES
    CarDescriptionUnitTest.cc
)
add_executable(common_tests ${COMMON_TEST_SOURCES})

target_link_libraries(common_tests PUBLIC common GTest::gtest_main)
target_compile_options(common_tests PRIVATE -coverage)
target_link_options(common_tests PRIVATE -coverage)

include(GoogleTest)
gtest_discover_tests(common_tests)