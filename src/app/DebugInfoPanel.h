//
// Created by Michał on 02/12/2024.
//

#ifndef EVOLUTION_DEBUGINFOPANEL_H
#define EVOLUTION_DEBUGINFOPANEL_H

#include <utility>

#include "imgui.h"
class DebugInfoPanel {
 public:
  using Position = std::pair<float, float>;
  DebugInfoPanel() = default;
  void render() const;
  void setCarPosition(Position car_position);
  void setMutationRate(float mutation_rate);

 private:
  Position car_position_;
  float mutation_rate_;
};

#endif  // EVOLUTION_DEBUGINFOPANEL_H
