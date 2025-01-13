/**
 * @brief TournamentReproductionScheme unit tests
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "reproduction/ReproductionScheme.h"
#include "reproduction/TournamentReproductionScheme.h"

namespace TournamentReproductionSchemeUnitTest {

Population givenPopulation() {
  return { givenSpecimen( 0 ), givenSpecimen( 1 ), givenSpecimen( 2 ), givenSpecimen( 3 ),
           givenSpecimen( 4 ) };
}

std::mt19937 givenRandomEngine() {
  return std::mt19937( 42 );  // Seed for reproducibility
}

void assertContainsElement( const Population& population, const Specimen& specimen ) {
  if( std::find( population.begin(), population.end(), specimen ) == population.end() ) {
    FAIL() << "Population does not contain specimen";
  }
}

TEST( TournamentReproductionScheme, tournament_2_reproduction ) {
  const auto random_engine = givenRandomEngine();
  const auto population = givenPopulation();
  const std::vector<float> fitness = { 1, 2, 3, 4, 5 };
  const UReproductionScheme reproduction_scheme =
      std::make_unique<TournamentReproductionScheme>( random_engine, 2 );

  const auto new_population = reproduction_scheme->reproducePopulation( population, fitness );

  EXPECT_EQ( new_population.size(), population.size() );
  for( const auto& specimen : new_population ) {
    assertContainsElement( population, specimen );
  }
}

TEST( TournamentReproductionScheme, tournament_5_reproduction ) {
  const auto random_engine = givenRandomEngine();
  const auto population = givenPopulation();
  const std::vector<float> fitness = { 1, 2, 3, 4, 5 };
  const UReproductionScheme reproduction_scheme =
      std::make_unique<TournamentReproductionScheme>( random_engine, 5 );

  const auto new_population = reproduction_scheme->reproducePopulation( population, fitness );

  EXPECT_EQ( new_population.size(), population.size() );
  for( const auto& specimen : new_population ) {
    assertContainsElement( population, specimen );
  }
}

TEST( TournamentReproductionScheme, tournament_larger_than_population_reproduction ) {
  const auto random_engine = givenRandomEngine();
  const auto population = givenPopulation();
  const std::vector<float> fitness = { 1, 2, 3, 4, 5 };
  const UReproductionScheme reproduction_scheme =
      std::make_unique<TournamentReproductionScheme>( random_engine, 10 );

  const auto new_population = reproduction_scheme->reproducePopulation( population, fitness );

  EXPECT_EQ( new_population.size(), population.size() );
  for( const auto& specimen : new_population ) {
    assertContainsElement( population, specimen );
  }
}

}  // namespace TournamentReproductionSchemeUnitTest