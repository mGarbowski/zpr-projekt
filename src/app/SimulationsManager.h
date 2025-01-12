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
#include "Specimen.h"

class SimulationsManager {
 public:
  explicit SimulationsManager( std::vector<CarSimulation> simulations )
      : simulations_( std::move( simulations ) ), live_simulations_count_( simulations.size() ) {}

  SimulationsManager( const Road& road_model, const int population_size );
  SimulationsManager() = default;

  void initializeForPopulation( const Road& road_model, const Population& population );

  void update();

  std::vector<CarSimulation> simulations() const;

  Position getBestCarPosition() const;

  int liveSimulationsCount() const;

  RoadModel getRoadModel() const;

  bool isFinished() const;

 private:
  std::vector<CarSimulation> simulations_;
  int live_simulations_count_;
};

#endif  // SIMULATIONSMANAGER_H
