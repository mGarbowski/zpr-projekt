/**
 * @brief Evolution unit tests
 * @authors  Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>
#include <random>

#include "Evolution.h"
#include "TestUtils.h"
#include "mutation/GaussianMutationScheme.h"
#include "reproduction/ProportionalReproductionScheme.h"
#include "succession/GenerationSuccessionScheme.h"
#include "crossover/NoCrossoverScheme.h"


namespace EvolutionUnitTest {

TEST(Evolution, evolve) {
  const Population population = {givenSpecimen(0), givenSpecimen(1), givenSpecimen(2),
                                 givenSpecimen(3), givenSpecimen(4)};
  const std::vector<float> fitness = {1, 2, 3, 4, 5};

  UReproductionScheme reproduction_scheme =
      std::make_unique<ProportionalReproductionScheme>(std::mt19937(42));
  UMutationScheme mutation_scheme = std::make_unique<GaussianMutationScheme>(0.1, std::mt19937(42));
  USuccessionScheme succession_scheme = std::make_unique<GenerationSuccessionScheme>();
  UCrossoverScheme crossover_scheme = std::make_unique<NoCrossoverScheme>();
  const Evolution evolution(std::move(reproduction_scheme), std::move(mutation_scheme),
                            std::move(succession_scheme), std::move( crossover_scheme ));

  const auto next_population = evolution.evolve(population, fitness);

  EXPECT_EQ(population.size(), next_population.size());
}

}  // namespace EvolutionUnitTest