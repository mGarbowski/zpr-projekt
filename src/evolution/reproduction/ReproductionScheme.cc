/**
 * @ingroup evolution
 * @brief Implementation of ReproductionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ReproductionScheme.h"

#include <cassert>

Population ReproductionScheme::reproducePopulation(const Population& population,
                                                   const std::vector<float>& fitness) {
  assert(population.size() == fitness.size());
  return doReproducePopulation(population, fitness);
}