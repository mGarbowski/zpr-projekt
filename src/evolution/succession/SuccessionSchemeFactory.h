/**
 * @ingroup evolution
 * @brief Factory for creating succession schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef SUCCESSIONSCHEMEFACTORY_H
#define SUCCESSIONSCHEMEFACTORY_H
#include <variant>

#include "SuccessionScheme.h"

enum class SuccessionVariant { GENERATION, ELITIST };

struct GenerationSuccessionParams {};

struct ElitistSuccessionParams {
  int elite_size_;
};

using SuccessionParams = std::variant<GenerationSuccessionParams, ElitistSuccessionParams>;

class SuccessionSchemeFactory {
 public:
  static USuccessionScheme create( SuccessionParams params );
};

#endif  // SUCCESSIONSCHEMEFACTORY_H
