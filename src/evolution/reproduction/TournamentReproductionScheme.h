/**
* @ingroup evolution
* @brief Randomly selects two specimens from both populations and picks the better one until filled
* @authors Mikołaj Garbowski, Michał Łuszczek
*/
#ifndef EVOLUTION_TOURNAMENTREPRODUCTIONSCHEME_H
#define EVOLUTION_TOURNAMENTREPRODUCTIONSCHEME_H

#include "../reproduction/ReproductionScheme.h"
class TournamentReproductionScheme : public ReproductionScheme {
 public:
  explicit TournamentReproductionScheme( std::mt19937 random_engine )
      : random_engine_( random_engine ) {}

 protected:
  Population doReproducePopulation( const Population& population,
                                    std::vector<float> fitness ) override;

 private:
  std::mt19937 random_engine_;
};

#endif  // EVOLUTION_TOURNAMENTREPRODUCTIONSCHEME_H
