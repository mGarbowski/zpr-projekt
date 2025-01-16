/**
 * @ingroup app
 * @brief Manager for multiple car simulations.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "SimulationsManager.h"

#include <iostream>
void SimulationsManager::initializeForPopulation( const Road& road_model,
                                                  const Population& population ) {
  // Delete previous simulations
  for( auto& simulation : simulations_ ) {
    simulation.destroyWorld();
  }
  simulations_.clear();
  std::cout << "Cleared simulations" << std::endl;

  for( const auto& specimen : population ) {
    simulations_.push_back(
        CarSimulation::create( specimen.carDescription(), road_model, gravity_, computation_limit_ ) );
  }

  live_simulations_count_ = population.size();
}

void SimulationsManager::update() {
  auto live_simulations = 0;

  for( auto& simulation : simulations_ ) {
    if( simulation.isFinished() ) {
      continue;
    }
    ++live_simulations;
    simulation.step();
  }

  live_simulations_count_ = live_simulations;
}
std::vector<CarSimulation> SimulationsManager::simulations() const {
  return simulations_;
}
Position SimulationsManager::getBestCarPosition() const {
  Position best_position = { 0, 0 };
  for( const auto& simulation : simulations_ ) {
    if( !simulation.isFinished() && simulation.getDistance() > best_position.x_ ) {
      best_position = simulation.getCarChassis().getPosition();
    }
  }
  return best_position;
}
int SimulationsManager::liveSimulationsCount() const {
  return live_simulations_count_;
}

RoadModel SimulationsManager::getRoadModel() const {
  return simulations_[0].getRoadModel();
}

bool SimulationsManager::isFinished() const {
  return live_simulations_count_ == 0;
}
