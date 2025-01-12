/**
 * @ingroup app
 * @brief Implementation of DebugInfoPanel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "DebugInfoPanel.h"

#include <imgui.h>

void DebugInfoPanel::update( const EvolutionManager& evolution_manager ) {
  best_car_position_ = evolution_manager.simulationsManager().getBestCarPosition().asPair();
  generation_number_ = evolution_manager.generation();
  active_cars_count_ = evolution_manager.simulationsManager().liveSimulationsCount();
}

void DebugInfoPanel::render() const {
  ImGui::Begin( "Debug Info" );
  ImGui::Text( "Generation: %d", generation_number_ );
  ImGui::Text( "Active cars: %d", active_cars_count_ );
  ImGui::Text( "Best Position: (%.2f, %.2f)", best_car_position_.first, best_car_position_.second );
  ImGui::End();
}
