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

MutationVariant ConfigurationPanel::mutationVariant() const {
  return mutation_variant_;
}

MutationParams ConfigurationPanel::mutationParams() const {
  return mutation_params_;
}

void ConfigurationPanel::render() {
  ImGui::Begin( "Configuration Panel" );

  ImGui::SliderInt( "Population Size", &population_size_, 1, 50 );

  renderReproductionControls();
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

void ConfigurationPanel::renderReproductionControls() {
  const char* reproduction_variants[] = { "Proportional", "Tournament" };
  int current_variant = static_cast<int>( reproduction_variant_ );
  if( ImGui::Combo( "Reproduction Variant", &current_variant, reproduction_variants,
                    IM_ARRAYSIZE( reproduction_variants ) ) ) {
    reproduction_variant_ = static_cast<ReproductionVariant>( current_variant );
  }
  switch( reproduction_variant_ ) {
    case ReproductionVariant::TOURNAMENT: {
      try {
        auto& params = std::get<TournamentReproductionParams>( reproduction_params_ );
        ImGui::SliderInt( "Torunament Size", &params.tournament_size_, 1, 15 );

      } catch( std::bad_variant_access error ) {
        reproduction_params_ = TournamentReproductionParams{ 1 };
      }
      break;
    }
    case ReproductionVariant::PROPORTIONAL: {
      try {
        auto& params = std::get<ProportionalReproductionParams>( reproduction_params_ );
      } catch( std::bad_variant_access error ) {
        reproduction_params_ = ProportionalReproductionParams{ };
      }
      break;
    }
  }
}