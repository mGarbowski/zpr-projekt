/**
 * @ingroup app
 * @brief Manager for multiple car simulations.
 * @authors Mikolaj Garbowski, Michal Luszczek
 *
 * All cars are simulated in independent Box2D worlds.
 */

#ifndef SIMULATIONSMANAGER_H
#define SIMULATIONSMANAGER_H

#include "CarSimulation.h"

class SimulationsManager {
 public:
  explicit SimulationsManager( std::vector<CarSimulation> simulations )
      : simulations_( std::move( simulations ) ) {}

  SimulationsManager( const Road& road_model, const int population_size );
  SimulationsManager() = default;


  void update();

  std::vector<CarSimulation> simulations() const;

  Position getBestCarPosition() const;

  RoadModel getRoadModel() const;

  bool isFinished() const;

 private:
  std::vector<CarSimulation> simulations_;
};

#endif  // SIMULATIONSMANAGER_H
