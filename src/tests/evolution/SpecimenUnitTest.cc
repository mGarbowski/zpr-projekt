#include <gtest/gtest.h>

#include "CarDescription.h"
#include "Specimen.h"

namespace SpecimenUnitTest {

TEST(Specimen, conversionBetweenCarDescriptionAndAttributes) {

  const auto car_description = CarDescription(
      Position(1.0f, 2.0f), Position(3.0f, 4.0f), Position(5.0f, 6.0f), Position(7.0f, 8.0f),
      Position(9.0f, 10.0f), Position(11.0f, 12.0f), Position(13.0f, 14.0f), Position(15.0f, 16.0f),
      17.0f, 18.0f, 19.0f, 20.0f, 21.0f);

  const auto specimen = Specimen(car_description);
  const auto new_car_description = specimen.carDescription();

  ASSERT_EQ(car_description, new_car_description);
}

}
