/**
 * @ingroup evolution
 * @brief Implementation of ReproductionSchemeFactory
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ReproductionSchemeFactory.h"

#include "ProportionalReproductionScheme.h"
#include "RandomReproductionScheme.h"
#include "TournamentReproductionScheme.h"

struct ReproductionSchemeFactoryVisitor {
  std::mt19937& rng_;

  UReproductionScheme operator()( const ProportionalReproductionParams& ) const {
    return std::make_unique<ProportionalReproductionScheme>( rng_ );
  }

  UReproductionScheme operator()( const TournamentReproductionParams& params ) const {
    return std::make_unique<TournamentReproductionScheme>( rng_, params.tournament_size_ );
  }

  UReproductionScheme operator()( const RandomReproductionParams& ) const {
    return std::make_unique<RandomReproductionScheme>( rng_ );
  }
};

UReproductionScheme ReproductionSchemeFactory::create( ReproductionParams params,
                                                       std::mt19937 rng ) {
  return std::visit( ReproductionSchemeFactoryVisitor{ rng }, params );
}