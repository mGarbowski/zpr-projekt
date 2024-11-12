//
// Created by mgarbowski on 11/12/24.
//

#include "CarBody.h"

#include <stdexcept>
#include <vector>
CarBody CarBody::create(b2WorldId world_id, Position position) {
  // TODO: drawing in the documentation

  // Vertices
  const b2Vec2 center = {0, 0};
  const b2Vec2 top_left = {-4, 2};
  const b2Vec2 top = {0, 1};
  const b2Vec2 top_right = {4, 2};
  const b2Vec2 right = {2, 0};
  const b2Vec2 bottom_right = {4, -2};
  const b2Vec2 bottom = {0, -1};
  const b2Vec2 bottom_left = {-4, -2};
  const b2Vec2 left = {-2, 0};

  // Counter-clockwise
  const b2Vec2 tri_1_points[] = {center, top_left, left};
  const b2Vec2 tri_2_points[] = {center, top, top_left};
  const b2Vec2 tri_3_points[] = {center, top_right, top};
  const b2Vec2 tri_4_points[] = {center, right, top_right};
  const b2Vec2 tri_5_points[] = {center, bottom_right, right};
  const b2Vec2 tri_6_points[] = {center, bottom, bottom_right};
  const b2Vec2 tri_7_points[] = {center, bottom_left, bottom};
  const b2Vec2 tri_8_points[] = {center, left, bottom_left};
  auto triangles = {tri_1_points, tri_2_points, tri_3_points, tri_4_points,
                    tri_5_points, tri_6_points, tri_7_points, tri_8_points};

  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  body_def.type = b2_dynamicBody;
  const auto body_id = b2CreateBody(world_id, &body_def);

  b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  ground_shape_def.density = 1.0;
  ground_shape_def.friction = 0.3;

  for (auto triangle : triangles) {
    const auto hull = b2ComputeHull(triangle, 3);
    const b2Polygon poly = b2MakePolygon(&hull, 0);
    b2CreatePolygonShape(body_id, &ground_shape_def, &poly);
  }

  return CarBody(body_id);
}
b2Polygon CarBody::getTriangle(int idx) const {
  if (idx < 0 || idx > 7) {
    throw std::out_of_range("Triangle index out of range");
  }

  std::vector<b2ShapeId> shape_ids(8);
  auto n_shapes = b2Body_GetShapes(body_id_, shape_ids.data(), shape_ids.size());
  if (n_shapes != 8) {
    throw std::runtime_error("Expected 8 shapes");
  }

  return b2Shape_GetPolygon(shape_ids[idx]);
}
Position CarBody::getPosition() const {
  auto [x, y] = b2Body_GetPosition(body_id_);
  return {x, y};
}