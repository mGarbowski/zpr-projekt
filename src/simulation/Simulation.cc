//
// Created by mgarbowski on 11/1/24.
//

#include "Simulation.h"

#include <box2d/box2d.h>
#include <cassert>
#include <vector>

Simulation::Simulation() : time_step_(1.0f / 60.0f), sub_step_count_(4) {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{0.0f, -10.0f};
  this->worldId = b2CreateWorld(&world_def);

  b2BodyDef ground_body_def = b2DefaultBodyDef();
  ground_body_def.position = b2Vec2{0.0f, -10.0f};
  this->groundId = b2CreateBody(worldId, &ground_body_def);
  b2Polygon ground_box = b2MakeBox(50.0f, 10.0f);
  b2ShapeDef ground_shape_def = b2DefaultShapeDef();
  b2CreatePolygonShape(groundId, &ground_shape_def, &ground_box);

  b2BodyDef body_def = b2DefaultBodyDef();
  body_def.type = b2_dynamicBody;
  body_def.position = b2Vec2{0.0f, 10.0f};
  this->bodyId = b2CreateBody(worldId, &body_def);
  b2Polygon dynamic_box = b2MakeBox(1.0f, 1.0f);
  b2ShapeDef shape_def = b2DefaultShapeDef();
  shape_def.density = 1.0f;
  shape_def.friction = 0.3f;
  b2CreatePolygonShape(bodyId, &shape_def, &dynamic_box);
}
Simulation::~Simulation() { b2DestroyWorld(worldId); }
void Simulation::step() { b2World_Step(worldId, time_step_, sub_step_count_); }
b2Vec2 Simulation::getBodyPosition() const {
  return b2Body_GetPosition(bodyId);
}
b2Vec2 Simulation::getGroundPosition() const {
  return b2Body_GetPosition(groundId);
}
b2Vec2 Simulation::getGroundDimensions() const {
  return getDimensions(groundId);
}
b2Vec2 Simulation::getBodyDimensions() const { return getDimensions(bodyId); }
void Simulation::kickBox() const {
  b2Body_ApplyForce(bodyId, {100.0f, 5000.0f}, getBodyPosition(), true);
}
b2Vec2 Simulation::getDimensions(b2BodyId bodyId) const {
  std::vector<b2ShapeId> shape_ids(5);
  auto n_shapes = b2Body_GetShapes(bodyId, shape_ids.data(), shape_ids.size());
  assert(n_shapes == 1);

  auto polygon = b2Shape_GetPolygon(shape_ids[0]);
  assert(polygon.count == 4);

  auto width = polygon.vertices[1].x * 2;
  auto height = polygon.vertices[2].y * 2;
  return {width, height};
}