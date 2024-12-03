/**
 * @brief  GaussianMutationScheme unit tests
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include <gtest/gtest.h>

#include "../TestUtils.h"
#include "Specimen.h"
#include "mutation/GaussianMutationScheme.h"

namespace GaussianMutationSchemeUnitTest {

TEST(GaussianMutationScheme, mutation) {
  std::mt19937 random_engine(42);  // Seed for reproducibility
  double mutation_strength = 0.1;
  UMutationScheme mutation_scheme =
      std::make_unique<GaussianMutationScheme>(mutation_strength, random_engine);

  const auto car_description = givenCarDescription(0);
  const Specimen original_specimen(car_description);
  Specimen specimen(original_specimen);

  mutation_scheme->mutateSpecimen(specimen);

  for (auto i = 0; i < specimen.attributes().size(); ++i) {
    EXPECT_NE(original_specimen.attributes()[i], specimen.attributes()[i]);
  }
}

}  // namespace GaussianMutationSchemeUnitTest