#include <gtest/gtest.h>

#include "ControlPanel.h"
#include "EvolutionManager.h"
#include "EvolutionManagerFactory.h"

namespace EvolutionManagerUnitTest {

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

}  // namespace EvolutionManagerUnitTest