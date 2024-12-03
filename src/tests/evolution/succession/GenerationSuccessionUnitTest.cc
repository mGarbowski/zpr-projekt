/**
 * @brief GenerationSuccessionScheme unit tests
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "Specimen.h"
#include "succession/GenerationSuccessionScheme.h"
#include "succession/SuccessionScheme.h"

namespace GenerationSuccessionUnitTest {

TEST(GenerationSuccessionScheme, nextGeneration) {
  const Population previous_population = {givenSpecimen(0), givenSpecimen(1), givenSpecimen(2),
                                          givenSpecimen(3), givenSpecimen(4)};
  const Population mutants = {givenSpecimen(5), givenSpecimen(6), givenSpecimen(7),
                              givenSpecimen(8), givenSpecimen(9)};
  const std::vector<float> fitness = {1, 2, 3, 4, 5};
  const USuccessionScheme succession_scheme = std::make_unique<GenerationSuccessionScheme>();

  const auto next_generation =
      succession_scheme->nextGeneration(previous_population, mutants, fitness);

  EXPECT_EQ(next_generation, mutants);
}

}  // namespace GenerationSuccessionUnitTest