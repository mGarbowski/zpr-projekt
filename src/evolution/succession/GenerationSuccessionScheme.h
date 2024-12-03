/**
 * @ingroup evolution
 * @brief The simplest succession scheme - the next generation is just the mutants
 * @authors Mikołaj Garbowski, Michał Łuszczek
 */

#ifndef GENERATIONSUCCESSIONSCHEME_H
#define GENERATIONSUCCESSIONSCHEME_H
#include "SuccessionScheme.h"

class GenerationSuccessionScheme : public SuccessionScheme {
 protected:
  Population doNextGeneration( const Population& previous_population, const Population& mutants,
                               const std::vector<float>& fitness ) const override;
};

#endif  // GENERATIONSUCCESSIONSCHEME_H
