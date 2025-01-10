/**
 * @ingroup app
 * @brief Manager for multiple car simulations.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "SimulationsManager.h"
SimulationsManager::SimulationsManager( const Road& road_model, const int population_size ) {
  std::random_device rd;
  std::mt19937 gen( rd() );

  for( int i = 0; i < population_size; ++i ) {
    simulations_.push_back( CarSimulation::create( CarDescription::random( gen ), road_model ) );
  }
}
void SimulationsManager::update() {
  for( auto& simulation : simulations_ ) {
    if (simulation.isStuck() || simulation.isFinished()) {
      continue;
    }
    simulation.step();
  }
}
std::vector<CarSimulation> SimulationsManager::simulations() const {
  return simulations_;
}
Position SimulationsManager::getBestCarPosition() const {
  Position best_position = simulations_[0].getCarChassis().getPosition();
  for( const auto& simulation : simulations_ ) {
    if( !simulation.isStuck() && !simulation.isFinished() && simulation.getCarChassis().getPosition().x_ > best_position.x_ ) {
      best_position = simulation.getCarChassis().getPosition();
    }
  }
  return best_position;
}
RoadModel SimulationsManager::getRoadModel() const {
  return simulations_[0].getRoadModel();
}

bool SimulationsManager::isFinished() const {
  int live_simulations = simulations_.size();
  for( CarSimulation simulation: simulations_ ) {
    if (simulation.isStuck() || simulation.isFinished()){
      live_simulations--;
    }
  }
  return live_simulations == 0;
}
