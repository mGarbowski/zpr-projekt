/**
 * @ingroup evolution
 * @brief Implementation of TournamentReproductionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "TournamentReproductionScheme.h"
Population TournamentReproductionScheme::doReproducePopulation( const Population& population,
                                                                std::vector<float> fitness ) {
  Population new_population;
  new_population.reserve( population.size() );
  std::uniform_int_distribution<> distribution( 0, population.size() - 1 );
  for( int i = 0; i < population.size(); ++i ) {
    // first member
    int winner_idx = distribution( random_engine_ );

    // start from the second member, the first one is already selected
    for( int oppontent_idx = 1; oppontent_idx < tournament_size_; ++oppontent_idx ) {
      int oppontent = distribution( random_engine_ );
      if( fitness[oppontent] > fitness[winner_idx] ) {
        winner_idx = oppontent;
      }
    }
    new_population.push_back( population[winner_idx] );
  }

return new_population;
}
