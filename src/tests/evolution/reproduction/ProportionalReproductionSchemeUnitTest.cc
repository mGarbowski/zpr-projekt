/**
 * @brief ProportionalReproductionScheme unit tests
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "reproduction/ProportionalReproductionScheme.h"
#include "reproduction/ReproductionScheme.h"

namespace ProportionalReproductionSchemeUnitTest {

Population givenPopulation() {
  return { givenSpecimen( 0 ), givenSpecimen( 1 ), givenSpecimen( 2 ), givenSpecimen( 3 ),
           givenSpecimen( 4 ) };
}

std::mt19937 givenRandomEngine() {
  return std::mt19937( 42 );  // Seed for reproducibility
}

TEST( ProportionalReproductionScheme, reproduction ) {
  const auto random_engine = givenRandomEngine();
  const auto population = givenPopulation();
  const std::vector<float> fitness = { 1, 2, 3, 4, 5 };
  const UReproductionScheme reproduction_scheme =
      std::make_unique<ProportionalReproductionScheme>( random_engine );

  const auto new_population = reproduction_scheme->reproducePopulation( population, fitness );

  EXPECT_EQ( new_population.size(), population.size() );
  for( const auto& specimen : new_population ) {
    assertContainsElement( population, specimen );
  }
}

}  // namespace ProportionalReproductionSchemeUnitTest