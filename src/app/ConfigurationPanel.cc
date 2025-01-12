/**
 * @ingroup app
 * @brief Panel for configuring the evolution parameters before it starts.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ConfigurationPanel.h"

#include <imgui.h>

int ConfigurationPanel::populationSize() const {
  return population_size_;
}

bool ConfigurationPanel::shouldStartEvolution() const {
  return start_evolution_;
}

void ConfigurationPanel::render() {
  ImGui::Begin( "Configuration Panel" );

  ImGui::SliderInt( "Population Size", &population_size_, 1, 50 );

  if( ImGui::Button( "Start" ) ) {
    start_evolution_ = true;
  }

  ImGui::End();
}