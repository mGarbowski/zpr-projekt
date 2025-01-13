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
    // first participant
    int winner_idx = distribution( random_engine_ );

    // Select the rest of participants
    for( int j = 0; j < tournament_size_ - 1; ++j ) {
      int oppontent_idx = distribution( random_engine_ );
      if( fitness[oppontent_idx] > fitness[winner_idx] ) {
        winner_idx = oppontent_idx;
      }
    }
    new_population.push_back( population[winner_idx] );
  }

  return new_population;
}
