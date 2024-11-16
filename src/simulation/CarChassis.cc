//
// Created by mgarbowski on 11/12/24.
//

#include <stdexcept>
#include <vector>

#include "CarChassis.h"
#include "Utils.h"
CarChassis CarChassis::create(b2WorldId world_id, Position position,
                        const CarDescription& car_description) {
  const auto center = Position{0, 0};
  const auto top_left = car_description.topLeft();
  const auto top = car_description.top();
  const auto top_right = car_description.topRight();
  const auto right = car_description.right();
  const auto bottom_right = car_description.bottomRight();
  const auto bottom = car_description.bottom();
  const auto bottom_left = car_description.bottomLeft();
  const auto left = car_description.left();

  // Counter-clockwise
  const Position tri_1_points[] = {center, top_left, left};
  const Position tri_2_points[] = {center, top, top_left};
  const Position tri_3_points[] = {center, top_right, top};
  const Position tri_4_points[] = {center, right, top_right};
  const Position tri_5_points[] = {center, bottom_right, right};
  const Position tri_6_points[] = {center, bottom, bottom_right};
  const Position tri_7_points[] = {center, bottom_left, bottom};
  const Position tri_8_points[] = {center, left, bottom_left};
  auto triangles = {tri_1_points, tri_2_points, tri_3_points, tri_4_points,
                    tri_5_points, tri_6_points, tri_7_points, tri_8_points};

  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  body_def.type = b2_dynamicBody;
  const auto body_id = b2CreateBody(world_id, &body_def);

  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = car_description.bodyDensity();
  shape_def.friction = 0.3;

  for (auto triangle : triangles) {
    const b2Vec2 points[] = {Utils::asVec(triangle[0]), Utils::asVec(triangle[1]),
                             Utils::asVec(triangle[2])};
    const auto hull = b2ComputeHull(points, 3);
    const b2Polygon poly = b2MakePolygon(&hull, 0);
    b2CreatePolygonShape(body_id, &shape_def, &poly);
  }

  return CarChassis(body_id);
}
b2BodyId CarChassis::bodyId() const {
  return body_id_;
}
b2Polygon CarChassis::getTriangle(const int idx) const {
  if (idx < 0 || idx > 7) {
    throw std::out_of_range("Triangle index out of range");
  }

  std::vector<b2ShapeId> shape_ids(8);
  if (const auto n_shapes = b2Body_GetShapes(body_id_, shape_ids.data(), shape_ids.size());
      n_shapes != 8) {
    throw std::runtime_error("Expected 8 shapes");
  }

  return b2Shape_GetPolygon(shape_ids[idx]);
}
Position CarChassis::getPosition() const {
  auto [x, y] = b2Body_GetPosition(body_id_);
  return {x, y};
}