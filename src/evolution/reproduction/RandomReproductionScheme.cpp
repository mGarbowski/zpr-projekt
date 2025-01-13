/**
* @ingroup evolution
* @brief Implementation of RandomReproductionScheme
* @authors Mikolaj Garbowski, Michal Luszczek
*/

#include "RandomReproductionScheme.h"
Population RandomReproductionScheme::doReproducePopulation( const Population& population,
                                                            std::vector<float> fitness ) {
  Population new_population;
  new_population.reserve(population.size());
  std::uniform_int_distribution<> distribution(0, population.size() - 1);
  for (size_t i = 0; i < population.size(); ++i) {
    const int selected_index = distribution(random_engine_);
    new_population.push_back(population[selected_index]);
  }


  return new_population;
}
