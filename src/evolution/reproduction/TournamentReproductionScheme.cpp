/**
 * @ingroup evolution
 * @brief Implementation of TorunamentSuccessionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "TournamentReproductionScheme.h"
Population TournamentReproductionScheme::doReproducePopulation( const Population& population,
                                                                std::vector<float> fitness ) {
  Population new_population;
  new_population.reserve( population.size() );

  std::uniform_int_distribution<> distribution( 0, population.size() - 1 );
  for( int i = 0; i < population.size(); ++i ) {
    const auto first = distribution( random_engine_ );
    const auto second = distribution( random_engine_ );
    if( fitness[first] > fitness[second] ) {
      new_population.push_back( population[first] );
    } else {
      new_population.push_back( population[second] );
    }
  }

  return new_population;
}
