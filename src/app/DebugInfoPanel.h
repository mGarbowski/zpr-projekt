/**
 * @ingroup app
 * @brief Panel for displaying debug information about the simulation.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_DEBUGINFOPANEL_H
#define EVOLUTION_DEBUGINFOPANEL_H

#include <utility>

class DebugInfoPanel {
 public:
  using Position = std::pair<float, float>;

  DebugInfoPanel() = default;

  void render() const;

  void setBestCarPosition( const Position& best_car_position );

 private:
  Position best_car_position_;
};

#endif  // EVOLUTION_DEBUGINFOPANEL_H
