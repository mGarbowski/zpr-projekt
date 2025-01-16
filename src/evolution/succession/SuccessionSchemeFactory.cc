/**
 * @ingroup evolution
 * @brief Factory for creating succession schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "SuccessionSchemeFactory.h"

#include "ElitistSuccessionScheme.h"
#include "GenerationSuccessionScheme.h"

struct SuccessionSchemeFactoryVisitor {
  USuccessionScheme operator()( const GenerationSuccessionParams& ) const {
    return std::make_unique<GenerationSuccessionScheme>();
  }

  USuccessionScheme operator()( const ElitistSuccessionParams& params ) const {
    return std::make_unique<ElitistSuccessionScheme>( params.elite_size_ );
  }
};

USuccessionScheme SuccessionSchemeFactory::create( SuccessionParams params ) {
  return std::visit( SuccessionSchemeFactoryVisitor{}, params );
}