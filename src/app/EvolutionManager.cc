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

#include "EvolutionManager.h"

#include <iostream>

#include "PerlinRoadGenerator.h"
#include "succession/GenerationSuccessionScheme.h"

EvolutionManager EvolutionManager::create( int population_size, std::mt19937 random_generator, MutationVariant mutation_variant, MutationParams mutation_params ) {
  auto population = createRandomPopulation( population_size, random_generator );
  auto fitness_function = FitnessFunction();
  auto simulations_manager = SimulationsManager();
  auto road_generator = std::make_unique<PerlinRoadGenerator>( 50, 200, 20, 10, 8 );

  UReproductionScheme reproduction_scheme =
      std::make_unique<ProportionalReproductionScheme>( random_generator );
  UMutationScheme mutation_scheme = MutationSchemeFactory::create( mutation_variant, mutation_params, random_generator );
  USuccessionScheme succession_scheme = std::make_unique<GenerationSuccessionScheme>();

  auto evolution = Evolution( std::move( reproduction_scheme ), std::move( mutation_scheme ),
                              std::move( succession_scheme ) );

  EvolutionManager manager( std::move( random_generator ), std::move( simulations_manager ),
                            std::move( road_generator ), std::move( evolution ),
                            std::move( population ), std::move( fitness_function ) );

  manager.initializeSimulationsForNewGeneration();
  return manager;
}

int EvolutionManager::generation() const {
  return generation_;
}

void EvolutionManager::update() {
  if( !simulations_manager_.isFinished() ) {
    simulations_manager_.update();
    return;
  }

  handleEndOfSimulation();
}

SimulationsManager EvolutionManager::simulationsManager() const {
  return simulations_manager_;
}

Population EvolutionManager::createRandomPopulation( int population_size,
                                                     std::mt19937 random_generator ) {
  Population population;
  for( int i = 0; i < population_size; ++i ) {
    const CarDescription car_description = CarDescription::random( random_generator );
    Specimen specimen( car_description );
    population.push_back( specimen );
  }

  return population;
}

void EvolutionManager::initializeSimulationsForNewGeneration() {
  const auto road = road_generator_->generateRoad();
  simulations_manager_.initializeForPopulation( road, population_ );
}

std::vector<float> EvolutionManager::calculateFitness() const {
  std::vector<float> fitness;
  for( auto& simulation : simulations_manager_.simulations() ) {
    fitness.push_back( fitness_function_.calculateFitness( simulation ) );
  }
  return fitness;
}

void EvolutionManager::handleEndOfSimulation() {
  std::cout << "Finished generation " << generation_ << std::endl;
  ++generation_;

  const auto fitness = calculateFitness();
  population_ = evolution_.evolve( population_, fitness );
  for( auto& specimen : population_ ) {
    specimen.clampAttributes();
  }

  initializeSimulationsForNewGeneration();
}