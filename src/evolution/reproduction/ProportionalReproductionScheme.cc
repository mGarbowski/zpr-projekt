/**
 * @ingroup evolution
 * @brief Implementation of ProportionalReproductionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ProportionalReproductionScheme.h"

Population ProportionalReproductionScheme::doReproducePopulation(const Population& population,
                                                                 std::vector<float> fitness) {
  Population new_population;
  new_population.reserve(population.size());

  std::discrete_distribution<> distribution(fitness.begin(), fitness.end());

  for (size_t i = 0; i < population.size(); ++i) {
    const int selected_index = distribution(random_engine_);
    new_population.push_back(population[selected_index]);
  }

  return new_population;
}