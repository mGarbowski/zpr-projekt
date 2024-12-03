/**
 * @ingroup app
 * @brief Implementation of DebugInfoPanel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "DebugInfoPanel.h"

#include <imgui.h>

std::pair<float, float> DebugInfoPanel::setCarPosition(const Position& car_position) {
  car_position_ = car_position;
  return car_position_;
}

float DebugInfoPanel::setMutationRate(const float mutation_rate) {
  mutation_rate_ = mutation_rate;
  return mutation_rate_;
}

void DebugInfoPanel::render() const {
  ImGui::Begin("Debug Info");
  ImGui::Text("Car Position: (%.2f, %.2f)", car_position_.first, car_position_.second);
  ImGui::Text("Mutation Rate: %.2f", mutation_rate_);
  ImGui::End();
}
