#include <gtest/gtest.h>
#include <random>

#include "Evolution.h"
#include "mutation/GaussianMutationScheme.h"
#include "reproduction/ProportionalReproductionScheme.h"
#include "succession/GenerationSuccessionScheme.h"

namespace EvolutionUnitTest {

Specimen givenSpecimen(const int i) {
  return Specimen(CarDescription(Position(i + 0.0f, i + 1.0f), Position(i + 2.0f, i + 3.0f),
                                 Position(i + 4.0f, i + 5.0f), Position(i + 6.0f, i + 7.0f),
                                 Position(i + 8.0f, i + 9.0f), Position(i + 10.0f, i + 11.0f),
                                 Position(i + 12.0f, i + 13.0f), Position(i + 14.0f, i + 15.0f),
                                 i + 16.0f, i + 17.0f, i + 18.0f, i + 19.0f, i + 20.0f));
}

TEST(Evolution, evolve) {
  const Population population = {givenSpecimen(0), givenSpecimen(1), givenSpecimen(2),
                                 givenSpecimen(3), givenSpecimen(4)};
  const std::vector<float> fitness = {1, 2, 3, 4, 5};

  UReproductionScheme reproduction_scheme =
      std::make_unique<ProportionalReproductionScheme>(std::mt19937(42));
  UMutationScheme mutation_scheme = std::make_unique<GaussianMutationScheme>(0.1, std::mt19937(42));
  USuccessionScheme succession_scheme = std::make_unique<GenerationSuccessionScheme>();

  const Evolution evolution(std::move(reproduction_scheme), std::move(mutation_scheme),
                            std::move(succession_scheme));

  const auto next_population = evolution.evolve(population, fitness);

  EXPECT_EQ(population.size(), next_population.size());
}

}  // namespace EvolutionUnitTest