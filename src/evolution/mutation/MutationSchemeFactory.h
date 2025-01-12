/**
 * @ingroup evolution
 * @brief Factory for creating mutation schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef MUTATIONSCHEMEFACTORY_H
#define MUTATIONSCHEMEFACTORY_H

#include <variant>

#include "MutationScheme.h"

enum class MutationVariant { GAUSSIAN, NONE };

struct GaussianMutationParams {
  float mutation_strength_;
};

struct NoMutationParams {};

using MutationParams = std::variant<GaussianMutationParams, NoMutationParams>;

class MutationSchemeFactory {
 public:
  static UMutationScheme create( const MutationVariant variant, const MutationParams params,
                                 std::mt19937 rng );
};

#endif  // MUTATIONSCHEMEFACTORY_H
