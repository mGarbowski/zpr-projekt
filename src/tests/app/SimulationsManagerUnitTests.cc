#include <gtest/gtest.h>

#include "SimulationsManager.h"
#include "StaticRoadGenerator.h"

namespace SimulationsManagerUnitTest {

Road givenRoad() {
  StaticRoadGenerator generator;
  return generator.generateRoad();
}

CarDescription givenCarDescription( const int i ) {
  const Position top_left = { -1, static_cast<float>( 1 + 0.1 * i ) };
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

Specimen givenSpecimen( const int i ) {
  return Specimen( givenCarDescription( i ) );
}

Population givenPopulation() {
  Population population;
  for( int i = 0; i < 10; ++i ) {
    population.push_back( givenSpecimen( i ) );
  }
  return population;
}

SimulationsManager givenManager() {
  constexpr auto gravity = 9.81;
  return SimulationsManager( gravity );
}

TEST( SimulationsManager, initializeForPopulation ) {
  const auto road = givenRoad();
  const auto population = givenPopulation();
  auto manager = givenManager();

  manager.initializeForPopulation( road, population );

  EXPECT_EQ( manager.liveSimulationsCount(), population.size() );
  EXPECT_EQ( manager.simulations().size(), population.size() );
  EXPECT_FALSE( manager.isFinished() );
}

TEST( SimulationsManager, getBestCarPosition ) {
  const auto road = givenRoad();
  const auto population = givenPopulation();
  auto manager = givenManager();
  manager.initializeForPopulation( road, population );
  const auto initial_best_position = manager.getBestCarPosition();

  // Cars move to the right (towards positive x)
  for( int i = 0; i < 100; ++i ) {
    manager.update();
  }
  const auto later_best_position = manager.getBestCarPosition();

  // After a while, the best car position should move to the right
  EXPECT_TRUE( initial_best_position.x_ < later_best_position.x_ );
}

}  // namespace SimulationsManagerUnitTest