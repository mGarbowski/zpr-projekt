//
// Created by mgarbowski on 11/5/24.
//

#ifndef CARSIMULATION_H
#define CARSIMULATION_H

#include <utility>

#include "CarBody.h"
#include "CarDescription.h"
#include "CircleRot.h"
#include "Rect.h"
#include "box2d/id.h"

/**
 * @ingroup simulation
 * @brief Simulation with a single car on a road.
 */
class CarSimulation {
 public:
  static CarSimulation create(const CarDescription& car_description);

  ~CarSimulation() = default;
  CarSimulation(const CarSimulation& other) = delete;
  CarSimulation(CarSimulation&& other) noexcept = delete;
  CarSimulation& operator=(const CarSimulation& other) = delete;
  CarSimulation& operator=(CarSimulation&& other) noexcept = delete;

  Rect getGroundRect() const;
  CircleRot getRearWheelCircle() const;
  CircleRot getFrontWheelCircle() const;

  CarBody getCarBody() const;

  void step();

 private:
  CarSimulation(b2WorldId world_id, const float time_step, const int sub_step_count,
                b2BodyId ground_id, b2BodyId rear_wheel_id, b2BodyId front_wheel_id,
                b2JointId rear_joint_id, b2JointId front_joint_id, const CarBody car_body)
      : world_id_(std::move(world_id)),
        time_step_(time_step),
        sub_step_count_(sub_step_count),
        ground_id_(std::move(ground_id)),
        rear_wheel_id_(std::move(rear_wheel_id)),
        front_wheel_id_(std::move(front_wheel_id)),
        rear_joint_id_(std::move(rear_joint_id)),
        front_joint_id_(std::move(front_joint_id)),
        car_body_(car_body) {}

  b2WorldId world_id_;
  float time_step_;
  int sub_step_count_;
  b2BodyId ground_id_;
  b2BodyId rear_wheel_id_;
  b2BodyId front_wheel_id_;
  b2JointId rear_joint_id_;
  b2JointId front_joint_id_;
  CarBody car_body_;
};

#endif  // CARSIMULATION_H
