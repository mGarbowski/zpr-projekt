/**
 * @ingroup simulation
 * @brief Physical simulation with a single car on a road using Box2D.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef CARSIMULATION_H
#define CARSIMULATION_H

#include <box2d/box2d.h>
#include <utility>

#include "CarChassis.h"
#include "CarDescription.h"
#include "CircleRot.h"
#include "RoadModel.h"

class CarSimulation {
 public:
  static CarSimulation create( const CarDescription& car_description, const Road road );

  ~CarSimulation() = default;

  RoadModel getRoadModel() const;
  CircleRot getRearWheelCircle() const;
  CircleRot getFrontWheelCircle() const;

  CarChassis getCarChassis() const;
  bool isFinished() const;
  bool isStuck() const;

  void step();

 private:
  CarSimulation( b2WorldId world_id, const float time_step, const int sub_step_count,
                 RoadModel road_model, b2BodyId rear_wheel_id, b2BodyId front_wheel_id,
                 b2JointId rear_joint_id, b2JointId front_joint_id, const CarChassis car_chassis,
                 int max_stuck_steps = 400, float min_move_distance = 0.2f )
      : world_id_( std::move( world_id ) ),
        time_step_( time_step ),
        sub_step_count_( sub_step_count ),
        road_model_( std::move( road_model ) ),
        rear_wheel_id_( std::move( rear_wheel_id ) ),
        front_wheel_id_( std::move( front_wheel_id ) ),
        rear_joint_id_( std::move( rear_joint_id ) ),
        front_joint_id_( std::move( front_joint_id ) ),
        car_chassis_( car_chassis ),
        stuck_steps_( 0 ),
        max_distance_( 0 ),
        max_stuck_steps_( max_stuck_steps ),
        min_move_distance_( min_move_distance ) {}

  b2WorldId world_id_;
  float time_step_;
  int sub_step_count_;
  RoadModel road_model_;
  b2BodyId rear_wheel_id_;
  b2BodyId front_wheel_id_;
  b2JointId rear_joint_id_;
  b2JointId front_joint_id_;
  CarChassis car_chassis_;
  int stuck_steps_;
  float max_distance_;
  int max_stuck_steps_;
  float min_move_distance_;
};

#endif  // CARSIMULATION_H
