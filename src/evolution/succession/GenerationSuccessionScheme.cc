/**
 * @ingroup evolution
 * @brief Implementation of GenerationSuccessionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "GenerationSuccessionScheme.h"
Population GenerationSuccessionScheme::doNextGeneration(const Population& previous_population,
                                                        const Population& mutants,
                                                        const std::vector<float>& fitness) const {
  return mutants;
}