/**
 * @ingroup evolution
 * @brief Two-point crossover
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "TwoPointCrossoverScheme.h"

#include <stdexcept>

Population TwoPointCrossoverScheme::doCrossoverPopulation( const Population& population ) {
  Population new_population;
  new_population.reserve( population.size() );
  std::uniform_int_distribution<> distribution( 0, population.size() - 1 );

  while( new_population.size() < population.size() ) {
    auto parent_1_idx = distribution( random_number_generator_ );
    auto parent_2_idx = distribution( random_number_generator_ );
    auto parent_1 = population[parent_1_idx];
    auto parent_2 = population[parent_2_idx];
    auto [offspring1, offspring2] =
        twoPointCrossover( parent_1.attributes(), parent_2.attributes() );

    auto car_description_1 = CarDescription(
        { offspring1[0], offspring1[1] }, { offspring1[2], offspring1[3] },
        { offspring1[4], offspring1[5] }, { offspring1[6], offspring1[7] },
        { offspring1[8], offspring1[9] }, { offspring1[10], offspring1[11] },
        { offspring1[12], offspring1[13] }, { offspring1[14], offspring1[15] }, offspring1[16],
        offspring1[17], offspring1[18], offspring1[19], offspring1[20] );

    new_population.push_back( Specimen( car_description_1 ) );
    if( new_population.size() < population.size() ) {
      auto car_description_2 = CarDescription(
          { offspring2[0], offspring2[1] }, { offspring2[2], offspring2[3] },
          { offspring2[4], offspring2[5] }, { offspring2[6], offspring2[7] },
          { offspring2[8], offspring2[9] }, { offspring2[10], offspring2[11] },
          { offspring2[12], offspring2[13] }, { offspring2[14], offspring2[15] }, offspring2[16],
          offspring2[17], offspring2[18], offspring2[19], offspring2[20] );
      new_population.push_back( Specimen( car_description_2 ) );
    }
  }
  return new_population;
}

std::pair<std::vector<float>, std::vector<float>> TwoPointCrossoverScheme::twoPointCrossover(
    const std::vector<float>& parent1, const std::vector<float>& parent2 ) {
  if( parent1.size() != parent2.size() ) {
    throw std::invalid_argument( "Both parents must have the same size." );
  }

  size_t length = parent1.size();

  // Random number generator
  std::uniform_int_distribution<size_t> dist( 0, length - 1 );

  // Select two random crossover points
  size_t point1 = dist( random_number_generator_ );
  size_t point2 = dist( random_number_generator_ );

  // Create offspring
  std::vector<float> offspring1 = parent1;
  std::vector<float> offspring2 = parent2;

  if( point1 <= point2 ) {
    // Regular case: swap segment between point1 and point2
    for( size_t i = point1; i < point2; ++i ) {
      std::swap( offspring1[i], offspring2[i] );
    }
  } else {
    // Wrapping case: swap from point1 to the end and from the beginning to point2
    for( size_t i = point1; i < length; ++i ) {
      std::swap( offspring1[i], offspring2[i] );
    }
    for( size_t i = 0; i < point2; ++i ) {
      std::swap( offspring1[i], offspring2[i] );
    }
  }

  return { offspring1, offspring2 };
}
