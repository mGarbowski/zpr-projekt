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

#include <algorithm>
#include <iostream>

#include "PerlinRoadGenerator.h"

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
std::optional<BestCar> EvolutionManager::bestCar() const {
  return best_car_;
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

  const auto fitness = calculateFitness();
  updateBestCar( fitness );

  population_ = evolution_.evolve( population_, fitness );
  for( auto& specimen : population_ ) {
    specimen.clampAttributes();
  }

  ++generation_;
  initializeSimulationsForNewGeneration();
}

void EvolutionManager::updateBestCar( std::vector<float> fitness ) {
  const auto best_car_idx =
      std::distance( fitness.begin(), std::max_element( fitness.begin(), fitness.end() ) );
  const auto best_fitness = fitness[best_car_idx];

  if( best_car_.has_value() && best_fitness <= best_car_->fitness_ ) {
    return;
  }

  const auto simulation = simulations_manager_.simulations()[best_car_idx];
  const auto description = population_[best_car_idx].carDescription();
  const auto distance = simulation.getCarChassis().getPosition().x_;
  const auto iterations = simulation.getTotalSteps();

  best_car_ = BestCar{ description, distance, iterations, best_fitness, generation_ };
}