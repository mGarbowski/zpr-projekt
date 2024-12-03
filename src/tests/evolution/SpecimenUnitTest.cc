/**
 * @brief Unit tests for Specimen
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

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
  EXPECT_EQ(attributes[0], car_description.topLeft().x_);
  EXPECT_EQ(attributes[1], car_description.topLeft().y_);
  EXPECT_EQ(attributes[2], car_description.top().y_);
  EXPECT_EQ(attributes[3], car_description.topRight().x_);
  EXPECT_EQ(attributes[4], car_description.topRight().y_);
  EXPECT_EQ(attributes[5], car_description.right().x_);
  EXPECT_EQ(attributes[6], car_description.bottomRight().x_);
  EXPECT_EQ(attributes[7], car_description.bottomRight().y_);
  EXPECT_EQ(attributes[8], car_description.bottom().y_);
  EXPECT_EQ(attributes[9], car_description.bottomLeft().x_);
  EXPECT_EQ(attributes[10], car_description.bottomLeft().y_);
  EXPECT_EQ(attributes[11], car_description.left().x_);
  EXPECT_EQ(attributes[12], car_description.bodyDensity());
  EXPECT_EQ(attributes[13], car_description.rearWheelDensity());
  EXPECT_EQ(attributes[14], car_description.frontWheelDensity());
  EXPECT_EQ(attributes[15], car_description.rearWheelRadius());
  EXPECT_EQ(attributes[16], car_description.frontWheelRadius());
}

}  // namespace SpecimenUnitTest
