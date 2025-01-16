#include <CarDescription.h>
#include <CarSimulation.h>
#include <Road.h>
#include <StaticRoadGenerator.h>
#include <gtest/gtest.h>

namespace CarSimulationUnitTest {

CarDescription givenCarDescription() {
  const Position top_left = { -1, 1 };
  const Position top = { 0, 1 };
  const Position top_right = { 1, 1 };
  const Position right = { 1, 0 };
  const Position bottom_right = { 1, -1 };
  const Position bottom = { 0, -1 };
  const Position bottom_left = { -1, -1 };
  const Position left = { -1, 0 };
  constexpr float body_density = 1.0f;
  constexpr float rear_wheel_density = 1.0f;
  constexpr float front_wheel_density = 1.0f;
  constexpr float rear_wheel_radius = 1.0f;
  constexpr float front_wheel_radius = 1.0f;

  return CarDescription( top_left, top, top_right, right, bottom_right, bottom, bottom_left, left,
                         body_density, rear_wheel_density, front_wheel_density, rear_wheel_radius,
                         front_wheel_radius );
}

Road givenRoad() {
  StaticRoadGenerator generator;
  return generator.generateRoad();
}

TEST( CarSimulation, carReachesEndOfRoad ) {
  const auto road = givenRoad();
  const auto car_description = givenCarDescription();
  auto simulation = CarSimulation::create( car_description, road );

  EXPECT_FALSE( simulation.isFinished() );
  EXPECT_FALSE( simulation.isStuck() );
  EXPECT_EQ( simulation.getTotalSteps(), 0 );

  for( int i = 0; i < 1000; ++i ) {
    simulation.step();
  }

  EXPECT_TRUE( simulation.isFinished() );
  EXPECT_FALSE( simulation.isStuck() );
  EXPECT_EQ( simulation.getTotalSteps(), 1000 );
}

}  // namespace CarSimulationUnitTest