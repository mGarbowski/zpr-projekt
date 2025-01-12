/**
 * @ingroup evolution
 * @brief Factory for creating mutation schemes
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "MutationSchemeFactory.h"

#include <stdexcept>

#include "GaussianMutationScheme.h"
#include "NoMutationScheme.h"

UMutationScheme MutationSchemeFactory::create( const MutationVariant variant,
                                               const MutationParams params, std::mt19937 rng ) {
  switch( variant ) {
    case MutationVariant::GAUSSIAN: {
      auto gauss_params = std::get<GaussianMutationParams>( params );
      return std::make_unique<GaussianMutationScheme>( gauss_params.mutation_strength_, rng );
    }
    case MutationVariant::NONE:
      return std::make_unique<NoMutationScheme>();
    default:
      throw std::runtime_error( "Unknown mutation variant" );
  }
}