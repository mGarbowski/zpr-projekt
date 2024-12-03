/**
 * @ingroup evolution
 * @brief Implementation of SuccessionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "SuccessionScheme.h"

#include <cassert>

Population SuccessionScheme::nextGeneration(const Population& previous_population,
                                            const Population& mutants,
                                            const std::vector<float>& fitness) const {
  assert(previous_population.size() == fitness.size());
  return doNextGeneration(previous_population, mutants, fitness);
}