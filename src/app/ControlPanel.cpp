//
// Created by Michał on 27/11/2024.
//

#include "ControlPanel.h"

#include "imgui.h"
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
  const char* items[] = {"Option 1", "Option 2", "Option 3"};
  const char* items2[] = {"Option A", "Option B", "Option C"};

  // First dropdown, invisible label
  ImGui::Text("Dropdown 1:");
  ImGui::Combo("##dropdown1", &dropdown_1_current_, items, IM_ARRAYSIZE(items));

  // Second dropdown, invisible label
  ImGui::Text("Dropdown 2:");
  ImGui::Combo("##dropdown2", &dropdown_2_current_, items, IM_ARRAYSIZE(items));

  ImGui::End();
}
