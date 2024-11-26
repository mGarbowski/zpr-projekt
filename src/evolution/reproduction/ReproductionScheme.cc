//
// Created by mgarbowski on 11/26/24.
//

#include "ReproductionScheme.h"

#include <cassert>

Population ReproductionScheme::reproducePopulation(const Population& population,
                                                   const std::vector<float>& fitness) {
  assert(population.size() == fitness.size());
  return doReproducePopulation(population, fitness);
}