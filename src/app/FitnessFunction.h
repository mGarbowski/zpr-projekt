/**
 * @ingroup app
 * @brief Calculates fitness of a simulated car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef FITNESSFUNCTION_H
#define FITNESSFUNCTION_H
#include "CarSimulation.h"

class FitnessFunction {
 public:
  explicit FitnessFunction( const float distance_weight = 1.0f, const float speed_weight = 1.0f )
      : distance_weight_( distance_weight ), speed_weight_( speed_weight ) {}

  float calculateFitness( const CarSimulation& simulation ) const;

 private:
  float distance_weight_;
  float speed_weight_;
};

#endif  // FITNESSFUNCTION_H
