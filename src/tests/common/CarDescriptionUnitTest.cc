//
// Created by mgarbowski on 11/30/24.
//

#include <gtest/gtest.h>

#include "CarDescription.h"

namespace CarDescriptionUnitTest {

TEST(CarDescription, createValidDescription) {
  const Position top_left = {-1, 1};
  const Position top = {0, 1};
  const Position top_right = {1, 1};
  const Position right = {1, 0};
  const Position bottom_right = {1, -1};
  const Position bottom = {0, -1};
  const Position bottom_left = {-1, -1};
  const Position left = {-1, 0};
  constexpr float body_density = 1.0f;
  constexpr float rear_wheel_density = 1.0f;
  constexpr float front_wheel_density = 1.0f;
  constexpr float rear_wheel_radius = 1.0f;
  constexpr float front_wheel_radius = 1.0f;

  const auto car_description = CarDescription(
      top_left, top, top_right, right, bottom_right, bottom, bottom_left, left, body_density,
      rear_wheel_density, front_wheel_density, rear_wheel_radius, front_wheel_radius);

  EXPECT_EQ(top_left, car_description.topLeft());
  EXPECT_EQ(top, car_description.top());
  EXPECT_EQ(top_right, car_description.topRight());
  EXPECT_EQ(right, car_description.right());
  EXPECT_EQ(bottom_right, car_description.bottomRight());
  EXPECT_EQ(bottom, car_description.bottom());
  EXPECT_EQ(bottom_left, car_description.bottomLeft());
  EXPECT_EQ(left, car_description.left());
  EXPECT_EQ(body_density, car_description.bodyDensity());
  EXPECT_EQ(rear_wheel_density, car_description.rearWheelDensity());
  EXPECT_EQ(front_wheel_density, car_description.frontWheelDensity());
  EXPECT_EQ(rear_wheel_radius, car_description.rearWheelRadius());
  EXPECT_EQ(front_wheel_radius, car_description.frontWheelRadius());
}

TEST(CarDescription, throwsIfPointsAreNotConstrainedToXYAxes) {
  // top, left, bottom, right points must be constrained to the x and y axes
  const Position top_left = {-1, 1};
  const Position top = {0, 1};
  const Position top_right = {1, 1};
  const Position right = {1, 0};
  const Position bottom_right = {1, -1};
  const Position bottom = {0, -1};
  const Position bottom_left = {-1, -1};
  const Position left = {-1, 0};
  constexpr float body_density = 1.0f;
  constexpr float rear_wheel_density = 1.0f;
  constexpr float front_wheel_density = 1.0f;
  constexpr float rear_wheel_radius = 1.0f;
  constexpr float front_wheel_radius = 1.0f;

  EXPECT_THROW(CarDescription(top_left, Position{0.1, 1}, top_right, right, bottom_right, bottom,
                              bottom_left, left, body_density, rear_wheel_density,
                              front_wheel_density, rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);

  EXPECT_THROW(CarDescription(top_left, top, top_right, {1, 0.1}, bottom_right, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);

  EXPECT_THROW(CarDescription(top_left, top, top_right, right, bottom_right, {-0.1, -1},
                              bottom_left, left, body_density, rear_wheel_density,
                              front_wheel_density, rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);

  EXPECT_THROW(CarDescription(top_left, top, top_right, right, bottom_right, bottom, bottom_left,
                              {-1, 0.1}, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
}

TEST(CarDescription, throwsIfCornerPointsAreNotRestrictedToQuadrants) {
  // top_left, top_right, bottom_right, bottom_left points must be restricted to their respective quadrants
  const Position top_left = {-1, 1};
  const Position top = {0, 1};
  const Position top_right = {1, 1};
  const Position right = {1, 0};
  const Position bottom_right = {1, -1};
  const Position bottom = {0, -1};
  const Position bottom_left = {-1, -1};
  const Position left = {-1, 0};
  constexpr float body_density = 1.0f;
  constexpr float rear_wheel_density = 1.0f;
  constexpr float front_wheel_density = 1.0f;
  constexpr float rear_wheel_radius = 1.0f;
  constexpr float front_wheel_radius = 1.0f;

  EXPECT_THROW(CarDescription({0.1, 1}, top, top_right, right, bottom_right, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription({-1, -0.1}, top, top_right, right, bottom_right, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription({0.1, -0.1}, top, top_right, right, bottom_right, bottom, bottom_left,
                                left, body_density, rear_wheel_density, front_wheel_density,
                                rear_wheel_radius, front_wheel_radius),
                 std::invalid_argument);


  EXPECT_THROW(CarDescription(top_left, top, {-0.1, 1}, right, bottom_right, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription(top_left, top, {1, -0.1}, right, bottom_right, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription(top_left, top, top_right, {-0.1, -0.1}, bottom_right, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);


  EXPECT_THROW(CarDescription(top_left, top, top_right, right, {-0.1, -1}, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription(top_left, top, top_right, right, {1, 0.1}, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription(top_left, top, top_right, right, {-0.1, 0.1}, bottom, bottom_left,
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);


  EXPECT_THROW(CarDescription(top_left, top, top_right, right, bottom_right, bottom, {0.1, -1},
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription(top_left, top, top_right, right, bottom_right, bottom, {-1, 0.1},
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
  EXPECT_THROW(CarDescription(top_left, top, top_right, right, bottom_right, bottom, {0.1, 0.1},
                              left, body_density, rear_wheel_density, front_wheel_density,
                              rear_wheel_radius, front_wheel_radius),
               std::invalid_argument);
}

}  // namespace CarDescriptionUnitTest