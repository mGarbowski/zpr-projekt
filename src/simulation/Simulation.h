//
// Created by mgarbowski on 11/1/24.
//

#ifndef SIMULATION_H
#define SIMULATION_H

#include <box2d/box2d.h>

class Simulation {
 public:
  Simulation();

  Simulation(const Simulation& other) = delete;
  Simulation(Simulation&& other) noexcept = delete;
  Simulation& operator=(const Simulation& other) = delete;
  Simulation& operator=(Simulation&& other) noexcept = delete;

  ~Simulation();

  void step();

  b2Vec2 getBodyPosition() const;

  b2Vec2 getGroundPosition() const;

  b2Vec2 getGroundDimensions() const;

  b2Vec2 getBodyDimensions() const;

  void kickBox() const;

 private:
  b2Vec2 getDimensions(b2BodyId bodyId) const;

  b2WorldId world_id_;
  b2BodyId ground_id_;
  b2BodyId body_id_;
  float time_step_;
  int sub_step_count_;
};

#endif  // SIMULATION_H
