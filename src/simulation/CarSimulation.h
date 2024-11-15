//
// Created by mgarbowski on 11/5/24.
//

#ifndef CARSIMULATION_H
#define CARSIMULATION_H
#include <utility>

#include "Rect.h"
#include "RectRot.h"
#include "CircleRot.h"
#include "box2d/id.h"

class CarSimulation {
 public:
  //! create a simulation with objects inside it
  static CarSimulation create();

  ~CarSimulation() = default;
  CarSimulation(const CarSimulation& other) = delete;
  CarSimulation(CarSimulation&& other) noexcept = delete;
  CarSimulation& operator=(const CarSimulation& other) = delete;
  CarSimulation& operator=(CarSimulation&& other) noexcept = delete;

  Rect getGroundRect() const;
  RectRot getCarBodyRect() const;
  RectRot getRearWheelRect() const;
  RectRot getFrontWheelRect() const;
  CircleRot getRearWheelCircle() const;
  CircleRot getFrontWheelCircle() const;

  void step();

 private:
  CarSimulation(b2WorldId world_id, float time_step, int sub_step_count, b2BodyId car_body_id,
                b2BodyId ground_id, b2BodyId rear_wheel_id, b2BodyId front_wheel_id,
                b2JointId rear_joint_id, b2JointId front_joint_id)
      : world_id_(std::move(world_id)),
        time_step_(time_step),
        sub_step_count_(sub_step_count),
        car_body_id_(std::move(car_body_id)),
        ground_id_(std::move(ground_id)),
        rear_wheel_id_(std::move(rear_wheel_id)),
        front_wheel_id_(std::move(front_wheel_id)),
        rear_joint_id_(std::move(rear_joint_id)),
        front_joint_id_(std::move(front_joint_id)) {}

  b2WorldId world_id_;
  float time_step_;
  int sub_step_count_;
  b2BodyId car_body_id_;
  b2BodyId ground_id_;
  b2BodyId rear_wheel_id_;
  b2BodyId front_wheel_id_;
  b2JointId rear_joint_id_;
  b2JointId front_joint_id_;
};

#endif  // CARSIMULATION_H
