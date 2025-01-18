/**
 * @ingroup evolution
 * @brief Factory for creating crossover schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_CROSSOVERSCHEMEFACTORY_H
#define EVOLUTION_CROSSOVERSCHEMEFACTORY_H
#include <variant>

#include "CrossoverScheme.h"
enum class CrossoverVariant { TWO_POINT, NONE };

struct TwoPointCrossoverParams {
  float crossover_prob_;
};

struct NoCrossoverParams {};

using CrossoverParams = std::variant<TwoPointCrossoverParams, NoCrossoverParams>;


class CrossoverSchemeFactory {

 public:
  static UCrossoverScheme create(CrossoverParams params, std::mt19937 rng );
};

#endif  // EVOLUTION_CROSSOVERSCHEMEFACTORY_H
