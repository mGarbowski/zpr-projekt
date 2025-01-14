include_directories(${CMAKE_SOURCE_DIR}/src/app)
include_directories(${CMAKE_SOURCE_DIR}/src/common)
include_directories(${CMAKE_SOURCE_DIR}/src/simulation)
include_directories(${CMAKE_SOURCE_DIR}/src/road)
include_directories(${CMAKE_SOURCE_DIR}/src/visualisation)
include_directories(${CMAKE_SOURCE_DIR}/src/evolution)

set(APP_TEST_SOURCES
        SimulationsManagerUnitTests.cc
        TestUtils.cc
        TestUtils.h
        FitnessFunctionUnitTest.cc
        EvolutionManagerUnitTest.cc
)
add_executable(app_tests ${APP_TEST_SOURCES})

target_link_libraries(app_tests PUBLIC GTest::gtest_main
        app-lib
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        simulation
        road
        visualisation
        evolution
)
include(GoogleTest)
gtest_discover_tests(app_tests)