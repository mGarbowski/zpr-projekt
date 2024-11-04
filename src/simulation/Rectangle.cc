//
// Created by mgarbowski on 11/4/24.
//

#include "Rectangle.h"

b2BodyId makeStaticRectangle(const b2WorldId world_id, const Position position, const Size size) {
  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  const auto body_id = b2CreateBody(world_id, &body_def);

  const b2Polygon box = b2MakeBox(size.width / 2, size.height / 2);
  const b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  b2CreatePolygonShape(body_id, &ground_shape_def, &box);

  return body_id;
}
b2BodyId makeDynamicRectangle(b2WorldId world_id, Position position, Size size, float density,
                              float friction) {
  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  body_def.type = b2_dynamicBody;
  const auto body_id = b2CreateBody(world_id, &body_def);

  const b2Polygon box = b2MakeBox(size.width / 2, size.height / 2);
  b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  ground_shape_def.density = density;
  ground_shape_def.friction = friction;

  b2CreatePolygonShape(body_id, &ground_shape_def, &box);

  return body_id;
}