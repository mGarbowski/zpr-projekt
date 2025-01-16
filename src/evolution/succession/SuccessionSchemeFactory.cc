/**
 * @ingroup evolution
 * @brief Factory for creating succession schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "SuccessionSchemeFactory.h"

#include <stdexcept>

#include "ElitistSuccessionScheme.h"
#include "GenerationSuccessionScheme.h"

USuccessionScheme SuccessionSchemeFactory::create( SuccessionVariant variant,
                                                   SuccessionParams params ) {
  switch( variant ) {
    case SuccessionVariant::GENERATION:
      return std::make_unique<GenerationSuccessionScheme>();
    case SuccessionVariant::ELITIST:
      return std::make_unique<ElitistSuccessionScheme>(
          std::get<ElitistSuccessionParams>( params ).elite_size_ );
    default:
      throw std::runtime_error( "Unknown succession variant" );
  }
}