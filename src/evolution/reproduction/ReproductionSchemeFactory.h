/**
* @ingroup evolution
* @brief Factory for creating reproduction schemes
* @authors Mikolaj Garbowski, Michal Luszczek
*/

#ifndef EVOLUTION_REPRODUCTIONSCHEMEFACTORY_H
#define EVOLUTION_REPRODUCTIONSCHEMEFACTORY_H
#include "ProportionalReproductionScheme.h"
#include "RandomReproductionScheme.h"
#include "ReproductionScheme.h"
#include "TournamentReproductionScheme.h"
#include "variant"

enum class ReproductionVariant { PROPORTIONAL, TOURNAMENT, RANDOM };

struct ProportionalReproductionParams {};

struct TournamentReproductionParams {
  int tournament_size_;
};

struct RandomReproductionParams {};

using ReproductionParams = std::variant<ProportionalReproductionParams,
                                        TournamentReproductionParams, RandomReproductionParams>;
class ReproductionSchemeFactory {
 public:
  static UReproductionScheme create( ReproductionVariant variant, ReproductionParams params,
                                     std::mt19937 rng );
};

#endif  // EVOLUTION_REPRODUCTIONSCHEMEFACTORY_H
