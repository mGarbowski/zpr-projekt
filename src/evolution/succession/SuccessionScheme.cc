//
// Created by mgarbowski on 11/26/24.
//

#include <cassert>

#include "SuccessionScheme.h"

Population SuccessionScheme::nextGeneration(const Population& previous_population,
                                            const Population& mutants,
                                            const std::vector<float>& fitness) const {
  assert(previous_population.size() == fitness.size());
  return doNextGeneration(previous_population, mutants, fitness);
}