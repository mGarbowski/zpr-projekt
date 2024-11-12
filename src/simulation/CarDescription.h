//
// Created by mgarbowski on 11/12/24.
//

#ifndef CARDESCRIPTION_H
#define CARDESCRIPTION_H

#include "Position.h"

class CarDescription {
 public:
  CarDescription(Position top_left, Position top, Position top_right, Position right,
                 Position bottom_right, Position bottom, Position bottom_left, Position left,
                 float body_density, float rear_wheel_density, float front_wheel_density,
                 float rear_wheel_radius, float front_wheel_radius)
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
        front_wheel_radius_(front_wheel_radius) {}

  Position topLeft() const {
    return top_left_;
  }
  Position top() const {
    return top_;
  }
  Position topRight() const {
    return top_right_;
  }
  Position right() const {
    return right_;
  }
  Position bottomRight() const {
    return bottom_right_;
  }
  Position bottom() const {
    return bottom_;
  }
  Position bottomLeft() const {
    return bottom_left_;
  }
  Position left() const {
    return left_;
  }
  float bodyDensity() const {
    return body_density_;
  }
  float rearWheelDensity() const {
    return rear_wheel_density_;
  }
  float frontWheelDensity() const {
    return front_wheel_density_;
  }
  float rearWheelRadius() const {
    return rear_wheel_radius_;
  }
  float frontWheelRadius() const {
    return front_wheel_radius_;
  }

 private:
  Position top_left_;
  Position top_;
  Position top_right_;
  Position right_;
  Position bottom_right_;
  Position bottom_;
  Position bottom_left_;
  Position left_;
  float body_density_;
  float rear_wheel_density_;
  float front_wheel_density_;
  float rear_wheel_radius_;
  float front_wheel_radius_;
};

#endif  // CARDESCRIPTION_H
