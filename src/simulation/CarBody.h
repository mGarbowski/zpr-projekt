//
// Created by mgarbowski on 11/12/24.
//

#ifndef CARBODY_H
#define CARBODY_H

#include <box2d/box2d.h>

#include "Position.h"

class CarBody {
 public:
  static CarBody create(b2WorldId world_id, Position position);
  b2BodyId bodyId() const {
    return body_id_;
  }
  b2Polygon getTriangle(int idx) const;
  Position getPosition() const;

 private:
  explicit CarBody(b2BodyId body_id) : body_id_(body_id) {}

  b2BodyId body_id_;
};

#endif  // CARBODY_H
