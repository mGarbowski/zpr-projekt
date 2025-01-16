/**
 * @ingroup evolution
 * @brief Succession with an elite
 * @authors Mikołaj Garbowski, Michał Łuszczek
 *
 * The elite are the best specimens from the original population.
 * the next population consists of elite and a subset of mutants.
 */

#ifndef ELITISTSUCCESSIONSCHEME_H
#define ELITISTSUCCESSIONSCHEME_H
#include "SuccessionScheme.h"

class ElitistSuccessionScheme : public SuccessionScheme {
 public:
  explicit ElitistSuccessionScheme( const int elite_size ) : elite_size_( elite_size ) {}

 protected:
  Population doNextGeneration( const Population& previous_population, const Population& mutants,
                               const std::vector<float>& fitness ) const override;

 private:
  int elite_size_;
};

#endif  // ELITISTSUCCESSIONSCHEME_H
