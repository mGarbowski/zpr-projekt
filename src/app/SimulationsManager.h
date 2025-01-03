//
// Created by mgarbowski on 1/3/25.
//

#ifndef SIMULATIONSMANAGER_H
#define SIMULATIONSMANAGER_H
#include "CarSimulation.h"

class SimulationsManager {
 public:
  explicit SimulationsManager( std::vector<CarSimulation> simulations )
      : simulations_( std::move( simulations ) ) {}

  SimulationsManager( const Road& road_model, const int population_size ) {
    std::random_device rd;
    std::mt19937 gen( rd() );

    for( int i = 0; i < population_size; ++i ) {
      simulations_.push_back( CarSimulation::create( CarDescription::random( gen ), road_model ) );
    }
  }

  void update() {
    for( auto& simulation : simulations_ ) {
      simulation.step();
    }
  }

  std::vector<CarSimulation> simulations() const {
    return simulations_;
  }

  Position getBestCarPosition() const {
    Position best_position = simulations_[0].getCarChassis().getPosition();
    for( const auto& simulation : simulations_ ) {
      if( simulation.getCarChassis().getPosition().x_ > best_position.x_ ) {
        best_position = simulation.getCarChassis().getPosition();
      }
    }
    return best_position;
  }

  RoadModel getRoadModel() const {
    return simulations_[0].getRoadModel();
  }

 private:
  std::vector<CarSimulation> simulations_;
};

#endif  // SIMULATIONSMANAGER_H
