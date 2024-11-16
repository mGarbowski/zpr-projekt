//
// Created by mgarbowski on 11/12/24.
//

#include "CarDescription.h"
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