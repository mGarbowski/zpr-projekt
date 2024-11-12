//
// Created by mgarbowski on 11/12/24.
//

#ifndef CARBODY_H
#define CARBODY_H

#include <box2d/box2d.h>

#include "CarDescription.h"
#include "Position.h"

class CarBody {
 public:
  static CarBody create(b2WorldId world_id, Position position, const CarDescription& car_description);

  b2BodyId bodyId() const;
  b2Polygon getTriangle(int idx) const;
  Position getPosition() const;

 private:
  explicit CarBody(const b2BodyId body_id) : body_id_(body_id) {}

  b2BodyId body_id_;
};

#endif  // CARBODY_H
