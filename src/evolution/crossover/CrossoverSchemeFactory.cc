/**
 * @ingroup evolution
 * @brief Implementation of CrossoverSchemeFactory
 * @authors Mikolaj Garbowski, Michal Luszczek
 */
#include "CrossoverSchemeFactory.h"

#include <stdexcept>

#include "NoCrossoverScheme.h"
#include "TwoPointCrossoverScheme.h"

struct CrossoverSchemeFactoryVisitor {
  std::mt19937& rng_;

  UCrossoverScheme operator()( const TwoPointCrossoverParams& params ) const {
    return std::make_unique<TwoPointCrossoverScheme>( rng_, params.crossover_prob_ );
  }

  UCrossoverScheme operator()( const NoCrossoverParams& ) const {
    return std::make_unique<NoCrossoverScheme>();
  }
};

UCrossoverScheme CrossoverSchemeFactory::create( CrossoverParams params, std::mt19937 rng ) {
  return std::visit( CrossoverSchemeFactoryVisitor{ rng }, params );
}