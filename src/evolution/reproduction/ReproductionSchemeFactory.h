//
// Created by Michał on 13/01/2025.
//

#ifndef EVOLUTION_REPRODUCTIONSCHEMEFACTORY_H
#define EVOLUTION_REPRODUCTIONSCHEMEFACTORY_H
#include "ProportionalReproductionScheme.h"
#include "ReproductionScheme.h"
#include "TournamentReproductionScheme.h"
#include "variant"

enum class ReproductionVariant { PROPORTIONAL, TOURNAMENT };

struct ProportionalReproductionParams {
  std::mt19937 random_engine_;
};

struct TournamentReproductionParams {
  std::mt19937 random_engine;
  int tournament_size;
};

using ReproductionParams =
    std::variant<ProportionalReproductionParams, TournamentReproductionParams>;
class ReproductionSchemeFactory {
 public:
  static UReproductionScheme create( ReproductionVariant variant, ReproductionParams params );
};

#endif  // EVOLUTION_REPRODUCTIONSCHEMEFACTORY_H
