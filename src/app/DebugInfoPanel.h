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

  Position setCarPosition( const Position& car_position );

  void setBestCarPosition( const Position& best_car_position );

  float setMutationRate( float mutation_rate );

 private:
  Position car_position_;
  Position best_car_position_;
  float mutation_rate_;
};

#endif  // EVOLUTION_DEBUGINFOPANEL_H
