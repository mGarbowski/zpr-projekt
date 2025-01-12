/**
 * @ingroup app
 * @brief Implementation of DebugInfoPanel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "DebugInfoPanel.h"

#include <imgui.h>

void DebugInfoPanel::setBestCarPosition( const Position& best_car_position ) {
  best_car_position_ = best_car_position;
}

void DebugInfoPanel::render() const {
  ImGui::Begin( "Debug Info" );
  ImGui::Text( "Best Position: (%.2f, %.2f)", best_car_position_.first, best_car_position_.second );
  ImGui::End();
}
