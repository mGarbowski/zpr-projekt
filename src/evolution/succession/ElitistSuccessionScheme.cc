/**
 * @ingroup evolution
 * @brief Succession with an elite
 * @authors Mikołaj Garbowski, Michał Łuszczek
 *
 * The elite are the best specimens from the original population.
 * the next population consists of elite and a subset of mutants (population_size - elite_size).
 */

#include "ElitistSuccessionScheme.h"

#include <algorithm>
#include <stdexcept>

ElitistSuccessionScheme::ElitistSuccessionScheme( const int elite_size )
    : elite_size_( elite_size ) {
  if( elite_size_ <= 0 ) {
    throw std::invalid_argument( "Invalid elite size" );
  }
}

Population ElitistSuccessionScheme::doNextGeneration( const Population& previous_population,
                                                      const Population& mutants,
                                                      const std::vector<float>& fitness ) const {
  if( elite_size_ > previous_population.size() ) {
    throw std::runtime_error( "Elite size is larger than the population size" );
  }

  // Create a vector of indices sorted by fitness in descending order
  std::vector<int> indices( previous_population.size() );
  std::iota( indices.begin(), indices.end(), 0 );
  std::sort( indices.begin(), indices.end(),
             [&fitness]( int a, int b ) { return fitness[a] > fitness[b]; } );

  // Select the elite specimens
  Population next_generation;
  for( int i = 0; i < elite_size_; ++i ) {
    next_generation.push_back( previous_population[indices[i]] );
  }

  // Add mutants to fill the rest of the next generation
  int remaining_size = previous_population.size() - elite_size_;
  for( int i = 0; i < remaining_size; ++i ) {
    next_generation.push_back( mutants[i] );
  }

  return next_generation;
}