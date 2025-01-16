#include <gtest/gtest.h>

#include "ControlPanel.h"
#include "EvolutionManager.h"
#include "EvolutionManagerFactory.h"

namespace EvolutionManagerUnitTest {

EvolutionManager givenManager() {
  const ConfigurationPanel configuration_panel;
  EvolutionManagerFactory factory;
  const std::mt19937 rng( 42 );
  return factory.create( configuration_panel, rng );
}

TEST( EvolutionManager, initializeSimulationsForNewGeneration ) {
  const ConfigurationPanel configuration_panel;
  EvolutionManagerFactory factory;
  const std::mt19937 rng( 42 );
  auto evolution_manager = factory.create( configuration_panel, rng );

  evolution_manager.initializeSimulationsForNewGeneration();

  EXPECT_EQ( evolution_manager.simulationsManager().simulations().size(),
             configuration_panel.populationSize() );
}

TEST( EvolutionManager, generationNumberIncrementsAfterSimulationsFinish ) {
  const ConfigurationPanel configuration_panel;
  EvolutionManagerFactory factory;
  const std::mt19937 rng( 42 );
  auto evolution_manager = factory.create( configuration_panel, rng );

  evolution_manager.initializeSimulationsForNewGeneration();
  EXPECT_EQ( evolution_manager.generation(), 0 );

  // Run the simulation until the first generation is finished
  while( evolution_manager.generation() == 0 ) {
    evolution_manager.update();
  }

  EXPECT_EQ( evolution_manager.generation(), 1 );
}

TEST( EvolutionManager, bestCarIsInitiallyEmpty ) {
  const auto evolution_manager = givenManager();
  EXPECT_FALSE( evolution_manager.bestCar().has_value() );
}

TEST( EvolutionManager, bestCarIsSetAfterFirstGeneration ) {
  auto evolution_manager = givenManager();

  // Run the simulation until the first generation is finished
  while( evolution_manager.generation() == 0 ) {
    evolution_manager.update();
  }

  EXPECT_TRUE( evolution_manager.bestCar().has_value() );
  const auto best_car = evolution_manager.bestCar().value();
  EXPECT_TRUE( best_car.distance_ > 0 );
  EXPECT_TRUE( best_car.iterations_ > 0 );
  EXPECT_TRUE( best_car.fitness_ > 0 );
}

}  // namespace EvolutionManagerUnitTest