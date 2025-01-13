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
      : car_color_( sf::Color::White ),
        road_color_( sf::Color::White ),
        is_running_( true ),
        dropdown_1_current_( 0 ),
        dropdown_2_current_( 0 ),
        is_display_enabled_( true ),
        simulation_speed_percent_( 100 ) {}

  bool getRunning() const;
  sf::Color getCarColor() const;
  sf::Color getRoadColor() const;
  bool isDisplayEnabled() const;
  int getDelayMicroseconds() const;

  void render();

 private:
  static const float MAX_SIMULATION_DELAY_MICROSECONDS;

  sf::Color car_color_;
  sf::Color road_color_;
  bool is_running_;
  int dropdown_1_current_;
  int dropdown_2_current_;
  bool is_display_enabled_;
  float simulation_speed_percent_;
};

#endif  // EVOLUTION_CONTROLPANEL_H
