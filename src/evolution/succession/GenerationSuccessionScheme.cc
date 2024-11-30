//
// Created by mgarbowski on 11/26/24.
//

#include "GenerationSuccessionScheme.h"
Population GenerationSuccessionScheme::doNextGeneration(const Population& previous_population,
                                                        const Population& mutants,
                                                        const std::vector<float>& fitness) const {
  return mutants;
}