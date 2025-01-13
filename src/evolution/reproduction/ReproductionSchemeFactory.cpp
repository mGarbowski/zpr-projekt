//
// Created by Michał on 13/01/2025.
//

#include "stdexcept"

#include "ReproductionSchemeFactory.h"
UReproductionScheme ReproductionSchemeFactory::create( ReproductionVariant variant,
                                                       ReproductionParams params ) {
  switch( variant ) {
    case ReproductionVariant::PROPORTIONAL: {
      auto proportional_params = std::get<ProportionalReproductionParams>( params );
      return std::make_unique<ProportionalReproductionScheme>( proportional_params.random_engine_ );
    }
    case ReproductionVariant::TOURNAMENT: {
      auto tournament_params = std::get<TournamentReproductionParams>( params );
      return std::make_unique<TournamentReproductionScheme>( tournament_params.random_engine,
                                                             tournament_params.tournament_size );
    }
    default:
      throw std::runtime_error( "Unknown reproduction variant" );
  }
}