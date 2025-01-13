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
  auto fitness_function = FitnessFunction();
  auto simulations_manager = SimulationsManager();
  auto roadroad_gen_params = configuration_panel.roadGenParams();
  auto road_generator = std::make_unique<PerlinRoadGenerator>(
      roadroad_gen_params.length_, roadroad_gen_params.grid_size_, roadroad_gen_params.layers_,
      roadroad_gen_params.scale_y_, roadroad_gen_params.scale_x_ );

  UReproductionScheme reproduction_scheme = ReproductionSchemeFactory::create(
      configuration_panel.reproductionVariant(), configuration_panel.reproductionParams(), rng );
  UMutationScheme mutation_scheme = MutationSchemeFactory::create(
      configuration_panel.mutationVariant(), configuration_panel.mutationParams(), rng );

  USuccessionScheme succession_scheme = std::make_unique<GenerationSuccessionScheme>();

  auto evolution = Evolution( std::move( reproduction_scheme ), std::move( mutation_scheme ),
                              std::move( succession_scheme ) );

  EvolutionManager manager( std::move( rng ), std::move( simulations_manager ),
                            std::move( road_generator ), std::move( evolution ),
                            std::move( population ), std::move( fitness_function ) );

  manager.initializeSimulationsForNewGeneration();
  return manager;
}