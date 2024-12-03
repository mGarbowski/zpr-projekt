/**
 * @ingroup evolution
 * @brief Implementation of Evolution
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "Evolution.h"

#include <cassert>

Population Evolution::evolve(const Population& population,
                             const std::vector<float>& fitness) const {
  assert(population.size() == fitness.size());

  auto new_population = reproduction_scheme_->reproducePopulation(population, fitness);
  mutation_scheme_->mutatePopulation(new_population);
  return succession_scheme_->nextGeneration(population, new_population, fitness);
}