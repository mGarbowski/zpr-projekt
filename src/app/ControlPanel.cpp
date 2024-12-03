/**
 * @ingroup app
 * @brief Implementation of ControlPanel
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ControlPanel.h"

#include <imgui.h>

bool ControlPanel::getRunning() const {
  return is_running_;
}

bool ControlPanel::setRunning( bool is_running ) {
  return is_running_ = is_running;
}

float ControlPanel::getMutationRate() const {
  return mutation_rate_;
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

  const char* color_options[] = { "White", "Blue", "Red" };
  const sf::Color colors[] = { sf::Color::White, sf::Color::Blue, sf::Color::Red };
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

  // Mutation slider
  ImGui::Text( "Mutation rate:" );
  ImGui::SliderFloat( "##slider", &mutation_rate_, 0.0f, 1.0f, "%.2f" );
  ImGui::End();
}

sf::Color ControlPanel::getCarColor() const {
  return car_color_;
}

sf::Color ControlPanel::getRoadColor() const {
  return road_color_;
}
