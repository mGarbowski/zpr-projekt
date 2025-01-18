/**
 * @brief  TwoPointCrossoverScheme unit tests
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "Specimen.h"
#include "crossover/TwoPointCrossoverScheme.h"

namespace TwoPointCrossoverSchemeUnitTest {

TEST( TwoPointCrossoverScheme, sizeCheck ) {
  std::mt19937 random_engine( 42 );  // Seed for reproducibility
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };

  UCrossoverScheme crossover_scheme = std::make_unique<TwoPointCrossoverScheme>( random_engine );
  const Population new_population = crossover_scheme->crossoverPopulation( original_population );
  EXPECT_EQ( new_population.size(), original_population.size() );
}

}  // namespace TwoPointCrossoverSchemeUnitTest