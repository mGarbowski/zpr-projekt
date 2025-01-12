/**
 * @ingroup app
 * @brief Manages the entire evolution process.
 * @authors Mikolaj Garbowski, Michal Luszczek
 *
 * Managing evolution includes:
 *  - maintaining the population
 *  - simulating the cars to calculate their fitness
 *  - evolving the population
 */

#ifndef EVOLUTIONMANAGER_H
#define EVOLUTIONMANAGER_H

#include "Evolution.h"
#include "FitnessFunction.h"
#include "RoadGenerator.h"
#include "SimulationsManager.h"
#include "mutation/GaussianMutationScheme.h"
#include "mutation/MutationSchemeFactory.h"
#include "reproduction/ProportionalReproductionScheme.h"

class EvolutionManager {
 public:
  static EvolutionManager create( int population_size, std::mt19937 random_generator,
                                  MutationVariant mutation_variant,
                                  MutationParams mutation_params );

  EvolutionManager( std::mt19937 random_generator, SimulationsManager simulations_manager,
                    URoadGenerator road_generator, Evolution evolution, Population population,
                    FitnessFunction fitness_function )
      : random_generator_( std::move( random_generator ) ),
        simulations_manager_( std::move( simulations_manager ) ),
        road_generator_( std::move( road_generator ) ),
        evolution_( std::move( evolution ) ),
        population_( std::move( population ) ),
        fitness_function_( std::move( fitness_function ) ),
        generation_( 0 ) {}

  int generation() const;

  SimulationsManager simulationsManager() const;

  void update();

 private:
  static Population createRandomPopulation( int population_size, std::mt19937 random_generator );

  void initializeSimulationsForNewGeneration();

  std::vector<float> calculateFitness() const;

  void handleEndOfSimulation();

  std::mt19937 random_generator_;
  SimulationsManager simulations_manager_;
  URoadGenerator road_generator_;
  Evolution evolution_;
  Population population_;
  FitnessFunction fitness_function_;
  int generation_;
};

#endif  // EVOLUTIONMANAGER_H
