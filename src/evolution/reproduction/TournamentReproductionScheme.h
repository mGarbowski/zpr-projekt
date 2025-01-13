/**
 * @ingroup evolution
 * @brief Randomly selects n specimens from the population and reproduces the best one
 * @authors Mikołaj Garbowski, Michał Łuszczek
 */
#ifndef EVOLUTION_TOURNAMENTREPRODUCTIONSCHEME_H
#define EVOLUTION_TOURNAMENTREPRODUCTIONSCHEME_H

#include "../reproduction/ReproductionScheme.h"
class TournamentReproductionScheme : public ReproductionScheme {
 public:
  explicit TournamentReproductionScheme( std::mt19937 random_engine, int tournament_size )
      : random_engine_( random_engine ), tournament_size_( tournament_size ) {}

 protected:
  Population doReproducePopulation( const Population& population,
                                    std::vector<float> fitness ) override;

 private:
  std::mt19937 random_engine_;
  int tournament_size_;
};

#endif  // EVOLUTION_TOURNAMENTREPRODUCTIONSCHEME_H
