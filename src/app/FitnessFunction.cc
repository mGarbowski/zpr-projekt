/**
 * @ingroup app
 * @brief Calculates fitness of a simulated car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "FitnessFunction.h"
float FitnessFunction::calculateFitness( const CarSimulation& simulation ) const {
  const auto distance = simulation.getDistance();
  const auto speed = simulation.getSpeed();
  return distance * distance_weight_ + speed * speed_weight_;
}