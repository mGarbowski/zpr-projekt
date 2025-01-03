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

  void update() {
    for( auto& simulation : simulations_ ) {
      simulation.step();
    }
  }

  std::vector<CarSimulation> simulations() const {
    return simulations_;
  }

 private:
  std::vector<CarSimulation> simulations_;
};

#endif  // SIMULATIONSMANAGER_H
