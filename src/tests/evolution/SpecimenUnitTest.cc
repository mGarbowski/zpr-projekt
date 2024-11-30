#include <gtest/gtest.h>

#include "CarDescription.h"
#include "Specimen.h"
#include "TestUtils.h"

namespace SpecimenUnitTest {

TEST(Specimen, conversionBetweenCarDescriptionAndAttributes) {

  const auto car_description = givenCarDescription(0);
  const auto specimen = Specimen(car_description);
  const auto new_car_description = specimen.carDescription();

  ASSERT_EQ(car_description, new_car_description);
}

}
