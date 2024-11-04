//
// Created by mgarbowski on 11/4/24.
//

#include "Rectangle.h"
Rectangle::Rectangle(b2WorldId world_id, Position position, Size size)
    : world_id_(world_id), position_(position), size_(size) {
  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  body_id_ = b2CreateBody(world_id_, &body_def);
  const b2Polygon box = b2MakeBox(size.width / 2, size.height / 2);
  const b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  b2CreatePolygonShape(body_id_, &ground_shape_def, &box);
}
Rectangle::~Rectangle() {
  b2DestroyBody(body_id_);
}
b2BodyId Rectangle::bodyId() const {
  return body_id_;
}