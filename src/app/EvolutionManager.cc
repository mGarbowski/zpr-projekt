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