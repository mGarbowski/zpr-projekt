//
// Created by mgarbowski on 1/12/25.
//

#ifndef FITNESSFUNCTION_H
#define FITNESSFUNCTION_H
#include "CarSimulation.h"

class FitnessFunction {
 public:
  explicit FitnessFunction( const float distance_weight = 1.0f, const float time_weight = 1.0f )
      : distance_weight_( distance_weight ), time_weight_( time_weight ) {}

  float calculateFitness( const CarSimulation& simulation ) const;

 private:
  float distance_weight_;
  float time_weight_;
};

#endif  // FITNESSFUNCTION_H
