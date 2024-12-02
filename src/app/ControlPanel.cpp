//
// Created by Michał on 27/11/2024.
//

#include "ControlPanel.h"


bool ControlPanel::getRunning() const {
  return is_running_;
}

bool ControlPanel::setRunning(bool is_running) {
  return is_running_ = is_running;
}

float ControlPanel::getMutationRate() const {
  return mutation_rate_;
}

std::string ControlPanel::getDropdown1CurrentItem() const {
  return "";
}

std::string ControlPanel::getDropdown2CurrentItem() const {
  return "";
}
void ControlPanel::render() {

  ImGui::Begin("Control Panel");

  // Buttons
  if (ImGui::Button("Start")) {
    is_running_ = true;
  }
  ImGui::SameLine();  // Places the next element on the same line
  if (ImGui::Button("Stop")) {
    is_running_ = false;
  }

  // Items for dropdowns
  const char* color_options[] = {"White", "Blue", "Red"};
  const sf::Color colors[] = {sf::Color::White, sf::Color::Blue, sf::Color::Red};
  // First dropdown, invisible label
  ImGui::Text("Car color:");
  ImGui::Combo("##dropdown1", &dropdown_1_current_, color_options, IM_ARRAYSIZE(color_options));

  if (dropdown_1_current_ >= 0 && dropdown_1_current_ < IM_ARRAYSIZE(colors)) {
    car_color_ = colors[dropdown_1_current_];
  }

  // Second dropdown, invisible label
  ImGui::Text("Road color:");
  ImGui::Combo("##dropdown2", &dropdown_2_current_, color_options, IM_ARRAYSIZE(color_options));
  if (dropdown_2_current_ >= 0 && dropdown_2_current_ < IM_ARRAYSIZE(colors)) {
    road_color_ = colors[dropdown_2_current_];
  }

  ImGui::End();
}
sf::Color ControlPanel::getCarColor() const {
  return car_color_;
}
sf::Color ControlPanel::getRoadColor() const {
  return road_color_;
}
