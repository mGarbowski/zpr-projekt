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

class BoxesSimulation {
 public:
  BoxesSimulation(std::vector<Rect> boxes, Rect ground);

  BoxesSimulation(const BoxesSimulation& other) = delete;
  BoxesSimulation(BoxesSimulation&& other) noexcept = delete;
  BoxesSimulation& operator=(const BoxesSimulation& other) = delete;
  BoxesSimulation& operator=(BoxesSimulation&& other) noexcept = delete;

  ~BoxesSimulation();

  void step();

  Rect getGroundRect() const;

  std::vector<Rect> getBoxes() const;

  Rect getBox(size_t index) const;

  void kickBox() const;

 private:
  static b2BodyId createStaticRectangle(b2WorldId world_id, Position position, Size size);
  static b2BodyId createDynamicRectangle(b2WorldId world_id, Position position, Size size,
                                         float density, float friction);

  Size getDimensions(b2BodyId body_id) const;
  Position getPosition(b2BodyId body_id) const;

  b2WorldId world_id_;
  b2BodyId ground_id_;
  std::vector<b2BodyId> boxes_;
  float time_step_;
  int sub_step_count_;
};

#endif  // SIMULATION_H
