/**
 * @ingroup app
 * @brief Implementation of DebugInfoPanel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "DebugInfoPanel.h"

#include <imgui.h>

void DebugInfoPanel::update( const EvolutionManager& evolution_manager ) {
  best_car_position_ = evolution_manager.simulationsManager().getBestCarPosition().asPair();
}

void DebugInfoPanel::render() const {
  ImGui::Begin( "Debug Info" );
  ImGui::Text( "Best Position: (%.2f, %.2f)", best_car_position_.first, best_car_position_.second );
  ImGui::End();
}
