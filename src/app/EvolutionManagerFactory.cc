/**
 * @ingroup app
 * @brief Factory for creating EvolutionManager objects based on UI configuration.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "EvolutionManagerFactory.h"

#include "PerlinRoadGenerator.h"
#include "succession/GenerationSuccessionScheme.h"

EvolutionManager EvolutionManagerFactory::create( const ConfigurationPanel& configuration_panel,
                                                  std::mt19937 rng ) {
  auto population = Specimen::createRandomPopulation( configuration_panel.populationSize(), rng );
  auto fitness_function =
      FitnessFunction( configuration_panel.distanceWeight(), configuration_panel.speedWeight() );
  auto simulations_manager =
      SimulationsManager( configuration_panel.gravity(), configuration_panel.computationLimit() );
  auto road_gen_params = configuration_panel.roadGenParams();
  auto road_generator = std::make_unique<PerlinRoadGenerator>(
      road_gen_params.length_, road_gen_params.grid_size_, road_gen_params.layers_,
      road_gen_params.scale_y_, road_gen_params.scale_x_ );

  UReproductionScheme reproduction_scheme =
      ReproductionSchemeFactory::create( configuration_panel.reproductionParams(), rng );
  UMutationScheme mutation_scheme =
      MutationSchemeFactory::create( configuration_panel.mutationParams(), rng );
  USuccessionScheme succession_scheme =
      SuccessionSchemeFactory::create( configuration_panel.successionParams() );
  UCrossoverScheme crossover_scheme =
      CrossoverSchemeFactory::create( configuration_panel.crossoverParams(), rng );

  auto evolution = Evolution( std::move( reproduction_scheme ), std::move( mutation_scheme ),
                              std::move( succession_scheme ), std::move( crossover_scheme ) );

  EvolutionManager manager( std::move( rng ), std::move( simulations_manager ),
                            std::move( road_generator ), std::move( evolution ),
                            std::move( population ), std::move( fitness_function ) );

  manager.initializeSimulationsForNewGeneration();
  return manager;
}