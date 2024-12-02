//
// Created by Michał on 27/11/2024.
//

#ifndef EVOLUTION_CONTROLPANEL_H
#define EVOLUTION_CONTROLPANEL_H

#include <string>
#include <SFML/Graphics.hpp>
#include "imgui.h"
class ControlPanel {
 public:
  ControlPanel() : is_running_(false), mutation_rate_(1.0f), dropdown_1_current_(0), dropdown_2_current_(0), car_color_(sf::Color::White), road_color_(sf::Color::White){};

  bool getRunning() const;
  bool setRunning(bool is_running);
  float getMutationRate() const;
  std::string getDropdown1CurrentItem() const;
  std::string getDropdown2CurrentItem() const;
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
