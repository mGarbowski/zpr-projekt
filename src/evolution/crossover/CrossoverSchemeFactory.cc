/**
 * @ingroup evolution
 * @brief Implementation of CrossoverSchemeFactory
 * @authors Mikolaj Garbowski, Michal Luszczek
 */
#include "CrossoverSchemeFactory.h"

#include <stdexcept>

#include "NoCrossoverScheme.h"
#include "TwoPointCrossoverScheme.h"

// Crossover variants have no parameters, so I forgo the visitors.
UCrossoverScheme CrossoverSchemeFactory::create( CrossoverVariant variant, std::mt19937 rng ) {
  switch( variant ) {
    case CrossoverVariant::NONE: {
      return std::make_unique<NoCrossoverScheme>();
    }
    case CrossoverVariant::TWO_POINT: {
      return std::make_unique<TwoPointCrossoverScheme>( rng );
    }
    default: {
      throw std::invalid_argument( "Invalid crossover scheme selected" );
    }
  }
}
