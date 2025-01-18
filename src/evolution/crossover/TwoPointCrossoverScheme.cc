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
  std::uniform_real_distribution<float> real_distribution( 0.0, 1.0 );

  for( int parent_1_index = 1; parent_1_index < population.size(); parent_1_index += 2 ) {
    const auto parent_2_index = parent_1_index - 1;
    auto parent_1 = population[parent_1_index];
    auto parent_2 = population[parent_2_index];
    // check if this pair is to be crossed over
    if( real_distribution( random_number_generator_ ) < crossover_prob_ ) {
      auto [offspring1, offspring2] =
          twoPointCrossover( parent_1.attributes(), parent_2.attributes() );

      auto car_description_1 = CarDescription(
          Position( offspring1[0], offspring1[1] ), Position( 0, offspring1[2] ),
          Position( offspring1[3], offspring1[4] ), Position( offspring1[5], 0 ),
          Position( offspring1[6], offspring1[7] ), Position( 0, offspring1[8] ),
          Position( offspring1[9], offspring1[10] ), Position( offspring1[11], 0 ), offspring1[12],
          offspring1[13], offspring1[14], offspring1[15], offspring1[16] );
      auto car_description_2 = CarDescription(
          Position( offspring2[0], offspring2[1] ), Position( 0, offspring2[2] ),
          Position( offspring2[3], offspring2[4] ), Position( offspring2[5], 0 ),
          Position( offspring2[6], offspring2[7] ), Position( 0, offspring2[8] ),
          Position( offspring2[9], offspring2[10] ), Position( offspring2[11], 0 ), offspring2[12],
          offspring2[13], offspring2[14], offspring2[15], offspring2[16] );

      new_population.push_back( Specimen( car_description_1 ) );
      new_population.push_back( Specimen( car_description_2 ) );
    } else {
      new_population.push_back( parent_1 );
      new_population.push_back( parent_2 );
    }
  }
  // odd number of specimens, one left without a pair
  if (new_population.size() < population.size()){
    new_population.push_back(population[population.size()-1]);
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
