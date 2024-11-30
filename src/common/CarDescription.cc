//
// Created by mgarbowski on 11/12/24.
//

#include "CarDescription.h"
CarDescription::CarDescription(const Position top_left, const Position top,
                               const Position top_right, const Position right,
                               const Position bottom_right, const Position bottom,
                               const Position bottom_left, const Position left,
                               const float body_density, const float rear_wheel_density,
                               const float front_wheel_density, const float rear_wheel_radius,
                               const float front_wheel_radius)
    : top_left_(top_left),
      top_(top),
      top_right_(top_right),
      right_(right),
      bottom_right_(bottom_right),
      bottom_(bottom),
      bottom_left_(bottom_left),
      left_(left),
      body_density_(body_density),
      rear_wheel_density_(rear_wheel_density),
      front_wheel_density_(front_wheel_density),
      rear_wheel_radius_(rear_wheel_radius),
      front_wheel_radius_(front_wheel_radius) {
  if (top.x != 0 || bottom.x != 0 || left.y != 0 || right.y != 0) {
    throw std::invalid_argument(
        "top, left, bottom, right points must be constrained to the x and y axes");
  }

  if (!(top_left.x < 0 && top_left.y > 0) || !(top_right.x > 0 && top_right.y > 0) ||
      !(bottom_right.x > 0 && bottom_right.y < 0) || !(bottom_left.x < 0 && bottom_left.y < 0)) {
    throw std::invalid_argument(
        "top_left, top_right, bottom_right, bottom_left points must be restricted to their "
        "respective quadrants");
  }
}
bool CarDescription::operator==(const CarDescription& other) const {
  return (top_left_ == other.topLeft() && top_ == other.top() && top_right_ == other.topRight() &&
          right_ == other.right() && bottom_right_ == other.bottomRight() &&
          bottom_ == other.bottom() && bottom_left_ == other.bottomLeft() &&
          left_ == other.left() && body_density_ == other.bodyDensity() &&
          rear_wheel_density_ == other.rearWheelDensity() &&
          front_wheel_density_ == other.frontWheelDensity() &&
          rear_wheel_radius_ == other.rearWheelRadius() &&
          front_wheel_radius_ == other.frontWheelRadius());
}

Position CarDescription::topLeft() const {
  return top_left_;
}
Position CarDescription::top() const {
  return top_;
}
Position CarDescription::topRight() const {
  return top_right_;
}
Position CarDescription::right() const {
  return right_;
}
Position CarDescription::bottomRight() const {
  return bottom_right_;
}
Position CarDescription::bottom() const {
  return bottom_;
}
Position CarDescription::bottomLeft() const {
  return bottom_left_;
}
Position CarDescription::left() const {
  return left_;
}
float CarDescription::bodyDensity() const {
  return body_density_;
}
float CarDescription::rearWheelDensity() const {
  return rear_wheel_density_;
}
float CarDescription::frontWheelDensity() const {
  return front_wheel_density_;
}
float CarDescription::rearWheelRadius() const {
  return rear_wheel_radius_;
}
float CarDescription::frontWheelRadius() const {
  return front_wheel_radius_;
}