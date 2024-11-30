#include <gtest/gtest.h>

#include "CarDescription.h"
#include "Specimen.h"
#include "TestUtils.h"

namespace SpecimenUnitTest {

TEST(Specimen, twoWayConversion) {
  const auto car_description = givenCarDescription(0);

  const auto specimen = Specimen(car_description);
  const auto new_car_description = specimen.carDescription();

  ASSERT_EQ(car_description, new_car_description);
}

TEST(Specimen, convertCarDescriptionToSpecimen) {
  const auto car_description = givenCarDescription(0);
  const auto specimen = Specimen(car_description);
  const auto attributes = specimen.attributes();

  EXPECT_EQ(attributes.size(), 17);
  EXPECT_EQ(attributes[0], car_description.topLeft().x);
  EXPECT_EQ(attributes[1], car_description.topLeft().y);
  EXPECT_EQ(attributes[2], car_description.top().y);
  EXPECT_EQ(attributes[3], car_description.topRight().x);
  EXPECT_EQ(attributes[4], car_description.topRight().y);
  EXPECT_EQ(attributes[5], car_description.right().x);
  EXPECT_EQ(attributes[6], car_description.bottomRight().x);
  EXPECT_EQ(attributes[7], car_description.bottomRight().y);
  EXPECT_EQ(attributes[8], car_description.bottom().y);
  EXPECT_EQ(attributes[9], car_description.bottomLeft().x);
  EXPECT_EQ(attributes[10], car_description.bottomLeft().y);
  EXPECT_EQ(attributes[11], car_description.left().x);
  EXPECT_EQ(attributes[12], car_description.bodyDensity());
  EXPECT_EQ(attributes[13], car_description.rearWheelDensity());
  EXPECT_EQ(attributes[14], car_description.frontWheelDensity());
  EXPECT_EQ(attributes[15], car_description.rearWheelRadius());
  EXPECT_EQ(attributes[16], car_description.frontWheelRadius());
}

}  // namespace SpecimenUnitTest
