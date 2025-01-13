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

ReproductionVariant ConfigurationPanel::reproductionVariant() const {
  return reproduction_variant_;
}

ReproductionParams ConfigurationPanel::reproductionParams() const {
  return reproduction_params_;
}

RoadGenParams ConfigurationPanel::roadGenParams() const {
  return road_gen_params_;
}

float ConfigurationPanel::gravity() const {
  return gravity_;
}

void ConfigurationPanel::render() {
  ImGui::Begin( "Configuration Panel" );

  ImGui::SliderInt( "Population Size", &population_size_, 1, 50 );

  ImGui::Text( "Evolution parameters:" );
  renderReproductionControls();
  renderMutationControls();

  renderRoadGeneratorControls();
  renderGravityControl();

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
  const char* reproduction_variants[] = { "Proportional", "Tournament", "Random" };
  int current_variant = static_cast<int>( reproduction_variant_ );
  if( ImGui::Combo( "Reproduction Variant", &current_variant, reproduction_variants,
                    IM_ARRAYSIZE( reproduction_variants ) ) ) {
    reproduction_variant_ = static_cast<ReproductionVariant>( current_variant );
  }

  adjustReproductionParamsType();
  switch( reproduction_variant_ ) {
    case ReproductionVariant::TOURNAMENT: {
      auto& params = std::get<TournamentReproductionParams>( reproduction_params_ );
      ImGui::SliderInt( "Torunament Size", &params.tournament_size_, 1, 15 );
    }
    case ReproductionVariant::PROPORTIONAL: {
      break;
    }
    case ReproductionVariant::RANDOM: {
      break;
    }
  }
}

void ConfigurationPanel::adjustReproductionParamsType() {
  switch( reproduction_variant_ ) {
    case ReproductionVariant::TOURNAMENT: {
      try {
        std::get<TournamentReproductionParams>( reproduction_params_ );
      } catch( std::bad_variant_access error ) {
        reproduction_params_ = TournamentReproductionParams{ 1 };
      }
      break;
    }
    case ReproductionVariant::PROPORTIONAL: {
      try {
        std::get<ProportionalReproductionParams>( reproduction_params_ );
      } catch( std::bad_variant_access error ) {
        reproduction_params_ = ProportionalReproductionParams{};
      }
      break;
    }
    case ReproductionVariant::RANDOM: {
      try {
        std::get<RandomReproductionParams>( reproduction_params_ );
      } catch( std::bad_variant_access error ) {
        reproduction_params_ = RandomReproductionParams{};
      }
      break;
    }
  }
}

void ConfigurationPanel::renderRoadGeneratorControls() {
  auto& params = road_gen_params_;
  ImGui::Text( "Road generator parameters:" );
  ImGui::SliderInt( "Number of points:", &params.length_, 1, 300 );
  ImGui::SliderInt( "Perlin grid size", &params.grid_size_, 1, 500 );
  ImGui::SliderInt( "Perlin Layers", &params.layers_, 1, 50 );
  ImGui::SliderFloat( "Y Scale", &params.scale_y_, 1, 15 );
  ImGui::SliderFloat( "X Scale", &params.scale_x_, 1, 15 );
}
void ConfigurationPanel::renderGravityControl() {
  ImGui::Text( "Gravity of the simulation:" );
  ImGui::SliderFloat( "Gravity (in m/s^2):", &gravity_, 0, 50 );
}
