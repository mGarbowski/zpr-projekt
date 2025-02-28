/**
 * @ingroup evolution
 * @brief Implementation of the evolution algorithm.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_H
#define EVOLUTION_H

#include "crossover/CrossoverScheme.h"
#include "mutation/MutationScheme.h"
#include "reproduction/ReproductionScheme.h"
#include "succession/SuccessionScheme.h"

class Evolution {
 public:
  Evolution( UReproductionScheme reproduction_scheme, UMutationScheme mutation_scheme,
             USuccessionScheme succession_scheme, UCrossoverScheme crossover_scheme )
      : reproduction_scheme_( std::move( reproduction_scheme ) ),
        mutation_scheme_( std::move( mutation_scheme ) ),
        succession_scheme_( std::move( succession_scheme ) ),
        crossover_scheme_( std::move( crossover_scheme ) ) {}

  /**
   * @brief Perform one iteration of evolution
   * @param population The current population
   * @param fitness The fitness of each specimen in the population (at corresponding indices)
   */
  Population evolve( const Population& population, const std::vector<float>& fitness ) const;

 private:
  UReproductionScheme reproduction_scheme_;
  UMutationScheme mutation_scheme_;
  USuccessionScheme succession_scheme_;
  UCrossoverScheme crossover_scheme_;
};

#endif  // EVOLUTION_H
