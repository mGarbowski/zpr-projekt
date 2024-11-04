//
// Created by mgarbowski on 11/4/24.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <box2d/box2d.h>

#include "Position.h"
#include "Size.h"

class Rectangle {
 public:
  Rectangle(b2WorldId world_id, Position position, Size size);
  ~Rectangle();

  b2BodyId bodyId() const;
  Position position() const {return position_; };

 private:
  b2WorldId world_id_;
  b2BodyId body_id_;
  Position position_;
  Size size_;
};

#endif  // RECTANGLE_H
