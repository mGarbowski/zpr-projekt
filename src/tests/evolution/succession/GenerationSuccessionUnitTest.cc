//
// Created by mgarbowski on 11/26/24.
//

#include <gtest/gtest.h>

#include "succession/GenerationSuccessionScheme.h"
#include "succession/SuccessionScheme.h"
#include "Specimen.h"

namespace GenerationSuccessionUnitTest {

Specimen givenSpecimen(const int i) {
  return Specimen(CarDescription(Position(i + 0.0f, i + 1.0f), Position(i + 2.0f, i + 3.0f),
                                 Position(i + 4.0f, i + 5.0f), Position(i + 6.0f, i + 7.0f),
                                 Position(i + 8.0f, i + 9.0f), Position(i + 10.0f, i + 11.0f),
                                 Position(i + 12.0f, i + 13.0f), Position(i + 14.0f, i + 15.0f),
                                 i + 16.0f, i + 17.0f, i + 18.0f, i + 19.0f, i + 20.0f));
}

TEST(GenerationSuccessionScheme, nextGeneration) {
  const Population previous_population = {givenSpecimen(0), givenSpecimen(1), givenSpecimen(2),
                                          givenSpecimen(3), givenSpecimen(4)};
  const Population mutants = {givenSpecimen(5), givenSpecimen(6), givenSpecimen(7),
                              givenSpecimen(8), givenSpecimen(9)};
  const std::vector<float> fitness = {1, 2, 3, 4, 5};
  const USuccessionScheme succession_scheme = std::make_unique<GenerationSuccessionScheme>();

  const auto next_generation = succession_scheme->nextGeneration(previous_population, mutants, fitness);

  EXPECT_EQ(next_generation, mutants);
}

}  // namespace GenerationSuccessionUnitTest