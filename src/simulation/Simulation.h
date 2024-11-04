//
// Created by mgarbowski on 11/1/24.
//

#ifndef SIMULATION_H
#define SIMULATION_H

#include <box2d/box2d.h>
#include <vector>

#include "Position.h"
#include "Rect.h"
#include "Size.h"

class Simulation {
 public:
  Simulation();
  Simulation(Position box_pos, Size box_size, Position ground_pos, Size ground_size);
  Simulation(std::vector<Rect> boxes, Rect ground);

  Simulation(const Simulation& other) = delete;
  Simulation(Simulation&& other) noexcept = delete;
  Simulation& operator=(const Simulation& other) = delete;
  Simulation& operator=(Simulation&& other) noexcept = delete;

  ~Simulation();

  void step();

  Position getBodyPosition() const;

  Position getGroundPosition() const;

  Size getGroundDimensions() const;

  Size getBodyDimensions() const;

  std::vector<Rect> getBoxes() const;
  Rect getBox(size_t index) const;

  void kickBox() const;

 private:
  static b2BodyId createStaticRectangle(b2WorldId world_id, Position position, Size size);
  static b2BodyId createDynamicRectangle(b2WorldId world_id, Position position, Size size, float density, float friction);

  Size getDimensions(b2BodyId body_id) const;
  Position getPosition(b2BodyId body_id) const;

  b2WorldId world_id_;
  b2BodyId ground_id_;
  std::vector<b2BodyId> boxes_;
  float time_step_;
  int sub_step_count_;

};

#endif  // SIMULATION_H
