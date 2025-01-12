/**
 * @ingroup app
 * @brief Factory for creating EvolutionManager objects based on UI confiugration.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTIONMANAGERFACTORY_H
#define EVOLUTIONMANAGERFACTORY_H

#include "ConfigurationPanel.h"
#include "EvolutionManager.h"
#include "PerlinRoadGenerator.h"
#include "succession/GenerationSuccessionScheme.h"

class EvolutionManagerFactory {
 public:
  static EvolutionManager create( const ConfigurationPanel& configuration_panel,
                                  std::mt19937 rng ) {
    auto population = Specimen::createRandomPopulation( configuration_panel.populationSize(), rng );
    auto fitness_function = FitnessFunction();
    auto simulations_manager = SimulationsManager();
    auto road_generator = std::make_unique<PerlinRoadGenerator>( 50, 200, 20, 10, 8 );

    UReproductionScheme reproduction_scheme =
        std::make_unique<ProportionalReproductionScheme>( rng );
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
};

#endif  // EVOLUTIONMANAGERFACTORY_H
