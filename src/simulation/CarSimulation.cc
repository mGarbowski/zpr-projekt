/**
 * @ingroup simulation
 * @brief Implementation of CarSimulation
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "CarSimulation.h"

#include <box2d/box2d.h>

#include "Utils.h"

CarSimulation CarSimulation::create(const CarDescription& car_description, Road road) {
  constexpr auto time_step = 1.0f / 60.0f;
  constexpr auto sub_step_count = 4;

  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{0.0f, -9.81f};

  const auto rear_wheel_position = car_description.bottomRight();
  const auto front_wheel_position = car_description.bottomLeft();
  const auto world_id = b2CreateWorld(&world_def);

  const auto rear_wheel_id =
      Utils::createDynamicCircle(world_id, rear_wheel_position, car_description.rearWheelRadius(),
                                 car_description.rearWheelDensity(), 0.3);
  const auto front_wheel_id =
      Utils::createDynamicCircle(world_id, front_wheel_position, car_description.frontWheelRadius(),
                                 car_description.frontWheelDensity(), 0.3);

  const auto car_chassis = CarChassis::create(world_id, {5, 3}, car_description);
  const auto car_chassis_body_id = car_chassis.bodyId();

  auto rear_joint_def = b2DefaultRevoluteJointDef();
  rear_joint_def.bodyIdA = car_chassis_body_id;
  rear_joint_def.bodyIdB = rear_wheel_id;
  rear_joint_def.localAnchorA = Utils::asVec(car_description.bottomLeft());
  rear_joint_def.localAnchorB = {0, 0};
  rear_joint_def.enableMotor = true;
  rear_joint_def.motorSpeed = 1.0f;
  rear_joint_def.maxMotorTorque = 1000.0f;
  const auto rear_joint_id = b2CreateRevoluteJoint(world_id, &rear_joint_def);

  auto front_joint_def = b2DefaultRevoluteJointDef();
  front_joint_def.bodyIdA = car_chassis_body_id;
  front_joint_def.bodyIdB = front_wheel_id;
  front_joint_def.localAnchorA = Utils::asVec(car_description.bottomRight());
  front_joint_def.localAnchorB = {0, 0};
  front_joint_def.enableMotor = true;
  front_joint_def.motorSpeed = 1.0f;
  front_joint_def.maxMotorTorque = 1000.0f;
  const auto front_joint_id = b2CreateRevoluteJoint(world_id, &front_joint_def);

  // Road
  const RoadModel road_model = RoadModel::create(world_id, road, {-1, -10});

  return CarSimulation(world_id, time_step, sub_step_count, road_model, rear_wheel_id,
                       front_wheel_id, rear_joint_id, front_joint_id, car_chassis);
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
CarChassis CarSimulation::getCarChassis() const {
  return car_chassis_;
}

RoadModel CarSimulation::getRoadModel() const {
  return road_model_;
}
