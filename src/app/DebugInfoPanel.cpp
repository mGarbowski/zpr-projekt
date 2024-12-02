//
// Created by Michał on 02/12/2024.
//

#include "DebugInfoPanel.h"
void DebugInfoPanel::setCarPosition(Position car_position) {
  car_position_ = car_position;
}
void DebugInfoPanel::setMutationRate(float mutation_rate) {
  mutation_rate_ = mutation_rate;
}
void DebugInfoPanel::render() const {
  ImGui::Begin("Debug Info");
  ImGui::Text("Car Position: (%.2f, %.2f)", car_position_.first, car_position_.second);
  ImGui::Text("Mutation Rate: %.2f", mutation_rate_);
  ImGui::End();
}
