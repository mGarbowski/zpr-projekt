/**
 * @ingroup app
 * @brief UI element for displaying parameters of the best car.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "BestCarParamsPanel.h"

#include <imgui.h>

void BestCarParamsPanel::render() {
  if (!best_car_.has_value()) {
    renderEmpty();
    return;
  }

  renderNormal();
}

void BestCarParamsPanel::update( const EvolutionManager& evolution_manager ) {
  best_car_ = evolution_manager.bestCar();
}

void BestCarParamsPanel::renderEmpty() {
  ImGui::Begin( "Best Car so far" );
  ImGui::Text( "Wait for the end of the first generation" );
  ImGui::End();
}

void BestCarParamsPanel::renderNormal() {
  ImGui::Begin( "Best Car so far" );

  ImGui::Text( "Fitness: %.2f", best_car_->fitness_ );
  ImGui::Text( "Distance: %.2f", best_car_->distance_ );
  ImGui::Text( "Iterations (time): %d", best_car_->iterations_ );

  ImGui::SeparatorText( "Chassis vertices" );
  ImGui::Text( "Top left: %s", best_car_->description_.topLeft().toString().c_str() );
  ImGui::Text( "Top: %s", best_car_->description_.top().toString().c_str() );
  ImGui::Text( "Top Right: %s", best_car_->description_.topRight().toString().c_str() );
  ImGui::Text( "Right: %s", best_car_->description_.right().toString().c_str() );
  ImGui::Text( "Bottom Right: %s", best_car_->description_.bottomRight().toString().c_str() );
  ImGui::Text( "Bottom: %s", best_car_->description_.bottom().toString().c_str() );
  ImGui::Text( "Bottom Left: %s", best_car_->description_.bottomLeft().toString().c_str() );
  ImGui::Text( "Left: %s", best_car_->description_.left().toString().c_str() );

  ImGui::SeparatorText( "Wheels" );
  ImGui::Text( "Front wheel radius: %.2f", best_car_->description_.frontWheelRadius() );
  ImGui::Text( "Rear wheel radius: %.2f", best_car_->description_.rearWheelRadius() );
  ImGui::Text( "Front wheel density: %.2f", best_car_->description_.frontWheelDensity() );
  ImGui::Text( "Rear wheel density: %.2f", best_car_->description_.rearWheelDensity() );

  ImGui::End();
}
