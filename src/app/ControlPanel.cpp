/**
 * @ingroup app
 * @brief Implementation of ControlPanel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ControlPanel.h"

#include <imgui.h>

const float ControlPanel::MAX_SIMULATION_DELAY_MICROSECONDS = 5000.0f;

bool ControlPanel::getRunning() const {
  return is_running_;
}

void ControlPanel::render() {
  ImGui::Begin( "Control Panel" );

  if( ImGui::Button( "Start" ) ) {
    is_running_ = true;
  }
  ImGui::SameLine();  // Places the next element on the same line
  if( ImGui::Button( "Stop" ) ) {
    is_running_ = false;
  }

  ImGui::Checkbox( "Display", &is_display_enabled_ );

  const char* color_options[] = { "White", "Blue", "Red" };
  const sf::Color colors[] = { sf::Color( 255, 255, 255, 128 ), sf::Color( 0, 0, 255, 128 ),
                               sf::Color( 255, 0, 0, 128 ) };

  // First dropdown, invisible label
  ImGui::Text( "Car color:" );
  ImGui::Combo( "##dropdown1", &dropdown_1_current_, color_options, IM_ARRAYSIZE( color_options ) );

  if( dropdown_1_current_ >= 0 && dropdown_1_current_ < IM_ARRAYSIZE( colors ) ) {
    car_color_ = colors[dropdown_1_current_];
  }

  // Second dropdown, invisible label
  ImGui::Text( "Road color:" );
  ImGui::Combo( "##dropdown2", &dropdown_2_current_, color_options, IM_ARRAYSIZE( color_options ) );
  if( dropdown_2_current_ >= 0 && dropdown_2_current_ < IM_ARRAYSIZE( colors ) ) {
    road_color_ = colors[dropdown_2_current_];
  }

  ImGui::SliderFloat( "Simulation speed", &simulation_speed_percent_, 0, 100 );

  ImGui::End();
}

sf::Color ControlPanel::getCarColor() const {
  return car_color_;
}

sf::Color ControlPanel::getRoadColor() const {
  return road_color_;
}

bool ControlPanel::isDisplayEnabled() const {
  return is_display_enabled_;
}

int ControlPanel::getDelayMicroseconds() const {
  return static_cast<int>( MAX_SIMULATION_DELAY_MICROSECONDS * ( 100 - simulation_speed_percent_ ) /
                           100 );
}
