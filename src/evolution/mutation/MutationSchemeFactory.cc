/**
 * @ingroup evolution
 * @brief Factory for creating mutation schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "MutationSchemeFactory.h"

#include "GaussianMutationScheme.h"
#include "NoMutationScheme.h"

struct MutationSchemeFactoryVisitor {
  std::mt19937& rng_;

  UMutationScheme operator()( const GaussianMutationParams& params ) const {
    return std::make_unique<GaussianMutationScheme>( params.mutation_strength_, rng_ );
  }

  UMutationScheme operator()( const NoMutationParams& ) const {
    return std::make_unique<NoMutationScheme>();
  }
};

UMutationScheme MutationSchemeFactory::create( const MutationParams params, std::mt19937 rng ) {
  return std::visit( MutationSchemeFactoryVisitor{ rng }, params );
}