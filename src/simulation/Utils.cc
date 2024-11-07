//
// Created by mgarbowski on 11/5/24.
//

#include "Utils.h"

#include <box2d/box2d.h>
#include <cassert>
#include <vector>

b2BodyId Utils::createStaticRectangle(b2WorldId world_id, Position position, Size size) {
  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  const auto body_id = b2CreateBody(world_id, &body_def);

  const b2Polygon box = b2MakeBox(size.width / 2, size.height / 2);
  const b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  b2CreatePolygonShape(body_id, &ground_shape_def, &box);

  return body_id;
}
b2BodyId Utils::createDynamicRectangle(b2WorldId world_id, Position position, Size size,
                                       float density, float friction) {
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
Rect Utils::getRectangleRect(const b2BodyId body_id) {
  return {getRectanglePosition(body_id), getRectangleSize(body_id)};
}
RectRot Utils::getRectangleRectRot(const b2BodyId body_id) {
  return {
      getRectanglePosition(body_id),
      getRectangleSize(body_id),
      radToDeg(getRectangleAngleRadians(body_id)),
  };
}
Size Utils::getRectangleSize(b2BodyId body_id) {
  std::vector<b2ShapeId> shape_ids(5);
  auto n_shapes = b2Body_GetShapes(body_id, shape_ids.data(), shape_ids.size());
  assert(n_shapes == 1);

  auto polygon = b2Shape_GetPolygon(shape_ids[0]);
  assert(polygon.count == 4);

  auto width = polygon.vertices[1].x * 2;
  auto height = polygon.vertices[2].y * 2;
  return {width, height};
}
Position Utils::getRectanglePosition(b2BodyId body_id) {
  auto [x, y] = b2Body_GetPosition(body_id);
  return {x, y};
}
float Utils::getRectangleAngleRadians(b2BodyId body_id) {
  const auto rotation = b2Body_GetRotation(body_id);
  return b2Rot_GetAngle(rotation);
}
float Utils::radToDeg(const float rad) {
  return rad * 180.0f / M_PI;
}
b2BodyId Utils::createDynamicCircle(b2WorldId world_id, Position position, Size size, float density,
                                    float friction) {


  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = density;
  shape_def.friction = friction;
  b2Circle circle = { { 0.0f, 0.0f }, 0.4f * 1.0f };

  auto body_def = b2DefaultBodyDef();
  body_def.type = b2_dynamicBody;
  body_def.position = {position.x, position.y};
  body_def.allowFastRotation = true;
  b2BodyId wheel_id = b2CreateBody(world_id, &body_def);
  b2CreateCircleShape( wheel_id, &shape_def, &circle );


  return wheel_id;
}
