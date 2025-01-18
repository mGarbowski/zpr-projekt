/**
 * @brief  NoCrossoverScheme unit tests
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "Specimen.h"
#include "crossover/NoCrossoverScheme.h"

namespace NoCrossoverSchemeUnitTest {

TEST( NoCrossoverScheme, sizeCheck ) {
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };

  UCrossoverScheme crossover_scheme = std::make_unique<NoCrossoverScheme>();
  const Population new_population = crossover_scheme->crossoverPopulation( original_population );
  EXPECT_EQ( new_population.size(), original_population.size() );
}
TEST( NoCrossoverScheme, noChange ) {
  const Population original_population = { givenSpecimen( 0 ), givenSpecimen( 1 ),
                                           givenSpecimen( 2 ) };

  UCrossoverScheme crossover_scheme = std::make_unique<NoCrossoverScheme>();
  const Population new_population = crossover_scheme->crossoverPopulation( original_population );
  EXPECT_EQ( new_population, original_population );
}

}  // namespace NoCrossoverSchemeUnitTest