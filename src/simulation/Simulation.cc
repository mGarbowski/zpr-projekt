//
// Created by mgarbowski on 11/1/24.
//

#include "Simulation.h"

#include <algorithm>
#include <box2d/box2d.h>
#include <cassert>
#include <stdexcept>
#include <vector>

Simulation::Simulation() : Simulation({0, 10}, {2, 2}, {0, -10}, {50, 20}) {}

Simulation::Simulation(Position box_pos, Size box_size, Position ground_pos, Size ground_size)
    : time_step_(1.0f / 60.0f), sub_step_count_(4) {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{0.0f, -10.0f};
  world_id_ = b2CreateWorld(&world_def);
  ground_id_ = createStaticRectangle(world_id_, ground_pos, ground_size);
  auto body_id = createDynamicRectangle(world_id_, box_pos, box_size, 1, 0.3);
  boxes_.push_back(body_id);
}

Simulation::Simulation(std::vector<Rect> boxes, Rect ground)
    : time_step_(1.0f / 60.0f), sub_step_count_(4) {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{0.0f, -10.0f};
  world_id_ = b2CreateWorld(&world_def);
  ground_id_ = createStaticRectangle(world_id_, ground.pos(), ground.size());
  for (const auto& box : boxes) {
    auto body_id = createDynamicRectangle(world_id_, box.pos(), box.size(), 1, 0.3);
    boxes_.push_back(body_id);
  }
}

Simulation::~Simulation() {
  b2DestroyWorld(world_id_);
}

void Simulation::step() {
  b2World_Step(world_id_, time_step_, sub_step_count_);
}

Position Simulation::getBodyPosition() const {
  return getPosition(boxes_[0]);
}

Position Simulation::getGroundPosition() const {
  return getPosition(ground_id_);
}

Size Simulation::getGroundDimensions() const {
  return getDimensions(ground_id_);
}

Size Simulation::getBodyDimensions() const {
  return getDimensions(boxes_[0]);
}
std::vector<Rect> Simulation::getBoxes() const {
  std::vector<Rect> result(boxes_.size());
  std::transform(boxes_.begin(), boxes_.end(), result.begin(), [this](const auto& id) {
    return Rect{getPosition(id), getDimensions(id)};
  });
  return result;
}
Rect Simulation::getBox(const size_t index) const {
  if (index >= boxes_.size()) {
    throw std::runtime_error("Index out of bounds");
  }

  const auto id = boxes_[index];
  return {getPosition(id), getDimensions(id)};
}

void Simulation::kickBox() const {
  auto [x, y] = getBodyPosition();
  b2Body_ApplyForce(boxes_[0], {100.0f, 5000.0f}, {x, y}, true);
}
b2BodyId Simulation::createStaticRectangle(b2WorldId world_id, Position position, Size size) {
  auto body_def = b2DefaultBodyDef();
  body_def.position = {position.x, position.y};
  const auto body_id = b2CreateBody(world_id, &body_def);

  const b2Polygon box = b2MakeBox(size.width / 2, size.height / 2);
  const b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  b2CreatePolygonShape(body_id, &ground_shape_def, &box);

  return body_id;
}
b2BodyId Simulation::createDynamicRectangle(b2WorldId world_id, Position position, Size size,
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

Size Simulation::getDimensions(b2BodyId bodyId) const {
  std::vector<b2ShapeId> shape_ids(5);
  auto n_shapes = b2Body_GetShapes(bodyId, shape_ids.data(), shape_ids.size());
  assert(n_shapes == 1);

  auto polygon = b2Shape_GetPolygon(shape_ids[0]);
  assert(polygon.count == 4);

  auto width = polygon.vertices[1].x * 2;
  auto height = polygon.vertices[2].y * 2;
  return {width, height};
}
Position Simulation::getPosition(b2BodyId body_id) const {
  auto [x, y] = b2Body_GetPosition(body_id);
  return {x, y};
}