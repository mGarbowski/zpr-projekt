/**
 * @ingroup evolution
 * @brief Dummy crossover variant that does not crossover any specimens
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_NOCROSSOVERSCHEME_H
#define EVOLUTION_NOCROSSOVERSCHEME_H
#include "CrossoverScheme.h"

class NoCrossoverScheme: public CrossoverScheme {
 protected:
  virtual Population doCrossoverPopulation( const Population& population );
};

#endif  // EVOLUTION_NOCROSSOVERSCHEME_H
