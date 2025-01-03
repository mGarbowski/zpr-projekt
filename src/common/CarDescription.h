/**
 * @ingroup simulation
 * @brief Holds all parameters required to construct a car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef CARDESCRIPTION_H
#define CARDESCRIPTION_H

#include <random>

#include "Position.h"

class CarDescription {
 public:
  static CarDescription random( std::mt19937& random_engine );

  CarDescription( Position top_left, Position top, Position top_right, Position right,
                  Position bottom_right, Position bottom, Position bottom_left, Position left,
                  float body_density, float rear_wheel_density, float front_wheel_density,
                  float rear_wheel_radius, float front_wheel_radius );

  bool operator==( const CarDescription& other ) const;

  Position topLeft() const;
  Position top() const;
  Position topRight() const;
  Position right() const;
  Position bottomRight() const;
  Position bottom() const;
  Position bottomLeft() const;
  Position left() const;
  float bodyDensity() const;
  float rearWheelDensity() const;
  float frontWheelDensity() const;
  float rearWheelRadius() const;
  float frontWheelRadius() const;

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
