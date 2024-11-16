//
// Created by Michał on 07/11/2024.
//

#ifndef EVOLUTION_CIRCLEROT_H
#define EVOLUTION_CIRCLEROT_H

#include "Position.h"
#include "Size.h"

/**
 * @ingroup simulation
 * @brief A circle with a position, radius, and rotation.
 */
class CircleRot {
 public:
  CircleRot(const Position& pos, const float radius, float rotation)
      : pos_(pos), radius_(radius), rotation_(rotation) {}

  Position pos() const {
    return pos_;
  }
  float radius() const {
    return radius_;
  }
  float rotation() const {
    return rotation_;
  }

 private:
  Position pos_;
  float radius_;
  float rotation_;
};

#endif  // EVOLUTION_CIRCLEROT_H
