#include <FitnessFunction.h>
#include <gtest/gtest.h>

#include "TestUtils.h"

namespace FitnessFunctionUnitTest {

TEST( FitnessFunction, fitnessIncreasesWithTravelledDistance ) {
  const FitnessFunction fitness_function( 1.0f, 0.0f );
  CarSimulation simulation = givenSimulation();
  const auto initial_fitness = fitness_function.calculateFitness( simulation );

  for( int i = 0; i < 300; ++i ) {
    simulation.step();
  }
  const auto later_fitness = fitness_function.calculateFitness( simulation );

  EXPECT_TRUE( later_fitness > initial_fitness );
}

TEST( FitnessFunction, fitnessDecreasesWithTime ) {
  const FitnessFunction fitness_function( 0.0f, 1.0f );
  CarSimulation simulation = givenSimulation();
  const auto initial_fitness = fitness_function.calculateFitness( simulation );

  for( int i = 0; i < 300; ++i ) {
    simulation.step();
  }
  const auto later_fitness = fitness_function.calculateFitness( simulation );

  EXPECT_TRUE( later_fitness < initial_fitness );
}

}  // namespace FitnessFunctionUnitTest