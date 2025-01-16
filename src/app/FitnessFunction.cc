/**
 * @ingroup app
 * @brief Calculates fitness of a simulated car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "FitnessFunction.h"
float FitnessFunction::calculateFitness( const CarSimulation& simulation ) const {
  const auto distance = simulation.getCarChassis().getPosition().x_;
  const auto steps = simulation.getTotalSteps();
  const auto speed = distance / ( steps + 1 );  // +1 to avoid division by 0

  return distance * distance_weight_ + speed * speed_weight_;
}