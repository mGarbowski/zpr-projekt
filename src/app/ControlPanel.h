//
// Created by Michał on 27/11/2024.
//

#ifndef EVOLUTION_CONTROLPANEL_H
#define EVOLUTION_CONTROLPANEL_H

#include <string>
class ControlPanel {
 public:
  ControlPanel() : is_running_(false), mutation_rate_(1.0f), dropdown_1_current_(0), dropdown_2_current_(0){};

  bool getRunning() const;
  bool setRunning(bool is_running);
  float getMutationRate() const;
  std::string getDropdown1CurrentItem() const;
  std::string getDropdown2CurrentItem() const;
  void render();

 private:
  bool is_running_;
  float mutation_rate_;
  int dropdown_1_current_;
  int dropdown_2_current_;
};

#endif  // EVOLUTION_CONTROLPANEL_H
