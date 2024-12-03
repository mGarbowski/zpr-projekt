//
// Created by mgarbowski on 11/26/24.
//

#ifndef GENERATIONSUCCESSIONSCHEME_H
#define GENERATIONSUCCESSIONSCHEME_H
#include "SuccessionScheme.h"

/**
* @ingroup evolution
* @brief The simplest succession scheme - the next generation is just the mutants
*/
class GenerationSuccessionScheme : public SuccessionScheme {
 protected:
  Population doNextGeneration(const Population& previous_population, const Population& mutants,
                              const std::vector<float>& fitness) const override;
};

#endif  // GENERATIONSUCCESSIONSCHEME_H
