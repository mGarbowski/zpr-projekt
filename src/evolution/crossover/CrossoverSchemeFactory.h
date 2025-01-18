/**
 * @ingroup evolution
 * @brief Factory for creating crossover schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_CROSSOVERSCHEMEFACTORY_H
#define EVOLUTION_CROSSOVERSCHEMEFACTORY_H
#include "CrossoverScheme.h"
enum class CrossoverVariant { TWO_POINT, NONE };


class CrossoverSchemeFactory {

 public:
  static UCrossoverScheme create(CrossoverVariant variant, std::mt19937 rng );
};

#endif  // EVOLUTION_CROSSOVERSCHEMEFACTORY_H
