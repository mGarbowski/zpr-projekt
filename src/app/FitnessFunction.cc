/**
 * @ingroup app
 * @brief Calculates fitness of a simulated car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "FitnessFunction.h"
float FitnessFunction::calculateFitness( const CarSimulation& simulation ) const {
  const auto distance = simulation.getCarChassis().getPosition().x_;
  const auto steps = simulation.getTotalSteps();
  return distance * distance_weight_ + ( 1.0 / ( steps + 1.0 ) ) * time_weight_;
}