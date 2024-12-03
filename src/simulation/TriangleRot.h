//
// Created by mgarbowski on 12/3/24.
//

#ifndef TRIANGLEROT_H
#define TRIANGLEROT_H
#include "Position.h"

/**
 * @ingroup simulation
 * @brief A triangle with three vertices and rotation (degrees).
 */
class TriangleRot {
 public:
  TriangleRot(const Position& a, const Position& b, const Position& c, const float rotation)
      : a_(a), b_(b), c_(c), rotation_(rotation) {}

  Position a() const;
  Position b() const;
  Position c() const;
  float rotation() const;

 private:
  Position a_;
  Position b_;
  Position c_;
  /// Rotation in degrees
  float rotation_;
};

#endif  // TRIANGLEROT_H
