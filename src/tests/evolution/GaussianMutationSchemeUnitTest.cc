//
// Created by mgarbowski on 11/26/24.
//

#include <gtest/gtest.h>

#include "GaussianMutationScheme.h"
#include "Specimen.h"

namespace GaussianMutationSchemeUnitTest {

CarDescription givenCarDesciption() {
  return CarDescription(Position(1.0f, 2.0f), Position(3.0f, 4.0f), Position(5.0f, 6.0f),
                        Position(7.0f, 8.0f), Position(9.0f, 10.0f), Position(11.0f, 12.0f),
                        Position(13.0f, 14.0f), Position(15.0f, 16.0f), 17.0f, 18.0f, 19.0f, 20.0f,
                        21.0f);
}

TEST(GaussianMutationScheme, mutation) {
  std::mt19937 random_engine(42);  // Seed for reproducibility
  double mutation_strength = 0.1;
  UMutationScheme mutation_scheme =
      std::make_unique<GaussianMutationScheme>(mutation_strength, random_engine);

  const auto car_description = givenCarDesciption();
  const Specimen original_specimen(car_description);
  Specimen specimen(original_specimen);

  mutation_scheme->mutateSpecimen(specimen);
  const auto mutated_car = specimen.carDescription();

  // Always the same because of the hardcoded seed
  EXPECT_NEAR(mutated_car.topLeft().x, 0.944976, 1e-5);
  EXPECT_NEAR(mutated_car.topLeft().y, 2.05154324, 1e-5);
  EXPECT_NEAR(mutated_car.top().x, 3.04738617, 1e-5);
  EXPECT_NEAR(mutated_car.top().y, 4.13684511, 1e-5);

  for (auto i = 0; i < specimen.attributes().size(); ++i) {
    EXPECT_NE(original_specimen.attributes()[i], specimen.attributes()[i]);
  }
}

}  // namespace GaussianMutationSchemeUnitTest