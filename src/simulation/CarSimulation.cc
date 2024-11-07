//
// Created by mgarbowski on 11/5/24.
//

#include "CarSimulation.h"

#include "Utils.h"
#include "box2d/box2d.h"
CarSimulation CarSimulation::create() {
  const auto time_step = 1.0f / 60.0f;
  const auto sub_step_count = 4;

  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{0.0f, -9.81f};

  const auto rear_wheel_position = Position(-2, -1);
  const auto front_wheel_position = Position(2, -1);
  const auto world_id = b2CreateWorld(&world_def);
  const auto ground_id = Utils::createStaticRectangle(world_id, {0, -10}, {20, 1});
  const auto car_body_id = Utils::createDynamicRectangle(world_id, {0, 0}, {4, 2}, 1, 0.3);
  const auto rear_wheel_id =
      Utils::createDynamicCircle(world_id, rear_wheel_position, 0.5f, 1, 0.3);
  const auto front_wheel_id =
      Utils::createDynamicCircle(world_id, front_wheel_position, 0.5f, 1, 0.3);

  auto rear_joint_def = b2DefaultRevoluteJointDef();
  rear_joint_def.bodyIdA = car_body_id;
  rear_joint_def.bodyIdB = rear_wheel_id;
  rear_joint_def.localAnchorA = b2Body_GetLocalPoint(car_body_id, {rear_wheel_position.x, rear_wheel_position.y});
  rear_joint_def.localAnchorB = {0, 0};
  rear_joint_def.enableMotor = true;
  rear_joint_def.motorSpeed = 1.0f;
  rear_joint_def.maxMotorTorque = 1000.0f;
  const auto rear_joint_id = b2CreateRevoluteJoint(world_id, &rear_joint_def);

  auto front_joint_def = b2DefaultRevoluteJointDef();
  front_joint_def.bodyIdA = car_body_id;
  front_joint_def.bodyIdB = front_wheel_id;
  front_joint_def.localAnchorA = b2Body_GetLocalPoint(car_body_id, {front_wheel_position.x, front_wheel_position.y});
  front_joint_def.localAnchorB = {0, 0};
  front_joint_def.enableMotor = true;
  front_joint_def.motorSpeed = 1.0f;
  front_joint_def.maxMotorTorque = 1000.0f;
  const auto front_joint_id = b2CreateRevoluteJoint(world_id, &front_joint_def);

  return CarSimulation(world_id, time_step, sub_step_count, car_body_id, ground_id, rear_wheel_id,
                       front_wheel_id, rear_joint_id, front_joint_id);
}
Rect CarSimulation::getGroundRect() const {
  return Utils::getRectangleRect(ground_id_);
}
RectRot CarSimulation::getCarBodyRect() const {
  return Utils::getRectangleRectRot(car_body_id_);
}
RectRot CarSimulation::getRearWheelRect() const {
  return Utils::getRectangleRectRot(rear_wheel_id_);
}
RectRot CarSimulation::getFrontWheelRect() const {
  return Utils::getRectangleRectRot(front_wheel_id_);
}
void CarSimulation::step() {
  b2World_Step(world_id_, time_step_, sub_step_count_);
}
CircleRot CarSimulation::getRearWheelCircle() const {
  return Utils::getCircleRot(rear_wheel_id_);
}
CircleRot CarSimulation::getFrontWheelCircle() const {
  return Utils::getCircleRot(front_wheel_id_);
}
