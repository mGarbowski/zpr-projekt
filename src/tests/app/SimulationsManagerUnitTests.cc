#include <gtest/gtest.h>

#include "SimulationsManager.h"
#include "TestUtils.h"

namespace SimulationsManagerUnitTest {

SimulationsManager givenManager() {
  constexpr auto gravity = 9.81;
  constexpr auto computation_limit = 10000;
  return SimulationsManager( gravity, computation_limit );
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

  // Cars move to the right after landing (towards positive x)
  for( int i = 0; i < 300; ++i ) {
    manager.update();
  }
  const auto later_best_position = manager.getBestCarPosition();

  // After a while, the best car position should move to the right
  EXPECT_TRUE( initial_best_position.x_ < later_best_position.x_ );
}

TEST( SimulationsManager, isFinishedWhenAllSimulationsAreFinished ) {
  const auto simulations = { givenFinishedSimulation(), givenFinishedSimulation(),
                             givenFinishedSimulation() };

  auto manager = SimulationsManager( simulations );
  manager.update();

  EXPECT_TRUE( manager.isFinished() );
}

TEST( SimulationManager, isNotFinishedWhenAnySimulationIsNotFinished ) {
  const auto simulations = { givenFinishedSimulation(), givenSimulation(),
                             givenFinishedSimulation() };

  auto manager = SimulationsManager( simulations );
  manager.update();

  EXPECT_FALSE( manager.isFinished() );
}

TEST( SimulationManager, liveSimulationsCount ) {
  const auto simulations = { givenFinishedSimulation(), givenSimulation(),
                             givenFinishedSimulation() };

  auto manager = SimulationsManager( simulations );
  manager.update();

  EXPECT_EQ( manager.liveSimulationsCount(), 1 );
}

TEST( SimulationManager, updateUpdatesAllSimulations ) {
  const auto road = givenRoad();
  const auto population = givenPopulation();
  auto manager = givenManager();
  manager.initializeForPopulation( road, population );

  EXPECT_FALSE( manager.isFinished() );
  EXPECT_TRUE( manager.liveSimulationsCount() > 0 );

  // After enough time all simulations finish
  for( int i = 0; i < 1000; ++i ) {
    manager.update();
  }

  EXPECT_TRUE( manager.isFinished() );
  EXPECT_EQ( manager.liveSimulationsCount(), 0 );
}

}  // namespace SimulationsManagerUnitTest