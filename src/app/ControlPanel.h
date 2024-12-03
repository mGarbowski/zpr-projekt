/**
 * @ingroup app
 * @brief Panel for controlling the simulation.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_CONTROLPANEL_H
#define EVOLUTION_CONTROLPANEL_H

#include <SFML/Graphics.hpp>

class ControlPanel {
 public:
  ControlPanel()
      : car_color_(sf::Color::White),
        road_color_(sf::Color::White),
        is_running_(true),
        mutation_rate_(1.0f),
        dropdown_1_current_(0),
        dropdown_2_current_(0){};

  bool getRunning() const;
  bool setRunning(bool is_running);
  float getMutationRate() const;
  sf::Color getCarColor() const;
  sf::Color getRoadColor() const;
  void render();

 private:
  sf::Color car_color_;
  sf::Color road_color_;
  bool is_running_;
  float mutation_rate_;
  int dropdown_1_current_;
  int dropdown_2_current_;
};

#endif  // EVOLUTION_CONTROLPANEL_H
