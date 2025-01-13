//
// Created by Michał on 13/01/2025.
//

#include "ReproductionSchemeFactory.h"

#include "stdexcept"
UReproductionScheme ReproductionSchemeFactory::create( ReproductionVariant variant,
                                                       ReproductionParams params,
                                                       std::mt19937 rng ) {
  switch( variant ) {
    case ReproductionVariant::PROPORTIONAL: {
      return std::make_unique<ProportionalReproductionScheme>( rng );
    }
    case ReproductionVariant::TOURNAMENT: {
      auto tournament_params = std::get<TournamentReproductionParams>( params );
      return std::make_unique<TournamentReproductionScheme>( rng,
                                                             tournament_params.tournament_size_ );
    }
    default:
      throw std::runtime_error( "Unknown reproduction variant" );
  }
}