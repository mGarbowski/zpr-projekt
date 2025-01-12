/**
 * @ingroup app
 * @brief Panel for displaying debug information about the simulation.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_DEBUGINFOPANEL_H
#define EVOLUTION_DEBUGINFOPANEL_H

#include <utility>

#include "EvolutionManager.h"

class DebugInfoPanel {
 public:
  using Position = std::pair<float, float>;

  DebugInfoPanel() = default;

  void update(const EvolutionManager& evolution_manager);

  void render() const;

 private:
  Position best_car_position_;
  int generation_number_;
};

#endif  // EVOLUTION_DEBUGINFOPANEL_H
