#include "TestUtils.h"

#include <cassert>

#include "StaticRoadGenerator.h"

Road givenRoad() {
  StaticRoadGenerator generator;
  return generator.generateRoad();
}

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

CarSimulation givenSimulation() {
  const auto simulation = CarSimulation::create( givenCarDescription(), givenRoad() );
  assert( !simulation.isFinished() );
  return simulation;
}

CarSimulation givenFinishedSimulation() {
  auto simulation = givenSimulation();
  for( int i = 0; i < 1000; ++i ) {
    simulation.step();
  }
  assert( simulation.isFinished() );
  return simulation;
}

Specimen givenSpecimen( const int i ) {
  return Specimen( givenCarDescription() );
}

Population givenPopulation() {
  Population population;
  for( int i = 0; i < 10; ++i ) {
    population.push_back( givenSpecimen( i ) );
  }
  return population;
}