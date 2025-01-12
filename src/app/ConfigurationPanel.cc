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

  renderMutationControls();

  if( ImGui::Button( "Start" ) ) {
    start_evolution_ = true;
  }

  ImGui::End();
}

void ConfigurationPanel::renderMutationControls() {
  const char* mutation_variants[] = { "Gaussian", "None" };
  int current_variant = static_cast<int>( mutation_variant_ );
  if( ImGui::Combo( "Mutation Variant", &current_variant, mutation_variants,
                    IM_ARRAYSIZE( mutation_variants ) ) ) {
    mutation_variant_ = static_cast<MutationVariant>( current_variant );
  }

  if( mutation_variant_ == MutationVariant::GAUSSIAN ) {
    auto& params = std::get<GaussianMutationParams>( mutation_params_ );
    ImGui::SliderFloat( "Mutation Strength", &params.mutation_strength_, 0.01f, 1.0f );
  }
}