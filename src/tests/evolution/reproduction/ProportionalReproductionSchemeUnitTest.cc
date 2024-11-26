//
// Created by mgarbowski on 11/26/24.
//

#include <gtest/gtest.h>
#include <reproduction/ProportionalReproductionScheme.h>
#include <reproduction/ReproductionScheme.h>

namespace ProportionalReproductionSchemeUnitTest {

Specimen givenSpecimen(const int i) {
  return Specimen(CarDescription(Position(i + 0.0f, i + 1.0f), Position(i + 2.0f, i + 3.0f),
                                 Position(i + 4.0f, i + 5.0f), Position(i + 6.0f, i + 7.0f),
                                 Position(i + 8.0f, i + 9.0f), Position(i + 10.0f, i + 11.0f),
                                 Position(i + 12.0f, i + 13.0f), Position(i + 14.0f, i + 15.0f),
                                 i + 16.0f, i + 17.0f, i + 18.0f, i + 19.0f, i + 20.0f));
}

Population givenPopulation() {
  return {givenSpecimen(0), givenSpecimen(1), givenSpecimen(2), givenSpecimen(3), givenSpecimen(4)};
}

std::mt19937 givenRandomEngine() {
  return std::mt19937(42);  // Seed for reproducibility
}

TEST(ProportionalReproductionScheme, reproduction) {
  const auto random_engine = givenRandomEngine();
  const auto population = givenPopulation();
  const std::vector<float> fitness = {1, 2, 3, 4, 5};
  const UReproductionScheme reproduction_scheme =
      std::make_unique<ProportionalReproductionScheme>(random_engine);

  const auto new_population = reproduction_scheme->reproducePopulation(population, fitness);

  EXPECT_EQ(new_population.size(), population.size());
  EXPECT_EQ(new_population[0], population[4]);
  EXPECT_EQ(new_population[1], population[1]);
  EXPECT_EQ(new_population[2], population[4]);
  EXPECT_EQ(new_population[3], population[3]);
  EXPECT_EQ(new_population[4], population[3]);
}

}  // namespace ProportionalReproductionSchemeUnitTest