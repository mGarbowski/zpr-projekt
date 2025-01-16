/**
 * @ingroup app
 * @brief Panel for configuring the evolution parameters before it starts.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "ConfigurationPanel.h"

#include <imgui.h>

#include "succession/SuccessionSchemeFactory.h"

struct SuccessionControlsVisitor {
  explicit SuccessionControlsVisitor( const int max_elite_size )
      : max_elite_size_( max_elite_size ) {}

  void operator()( GenerationSuccessionParams& ) const {}

  void operator()( ElitistSuccessionParams& params ) const {
    ImGui::SliderInt( "Elite Size", &params.elite_size_, 1, max_elite_size_ );
  }

  int max_elite_size_;
};

struct ReproductionControlsVisitor {
  void operator()( ProportionalReproductionParams& ) const {}

  void operator()( TournamentReproductionParams& params ) const {
    ImGui::SliderInt( "Tournament Size", &params.tournament_size_, 1, 15 );
  }

  void operator()( RandomReproductionParams& ) const {}
};

struct MutationControlsVisitor {
  void operator()( NoMutationParams& ) const {}

  void operator()( GaussianMutationParams& params ) const {
    ImGui::SliderFloat( "Mutation Strength", &params.mutation_strength_, 0.01f, 1.0f );
  }
};

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

SuccessionVariant ConfigurationPanel::successionVariant() const {
  return succession_variant_;
}

SuccessionParams ConfigurationPanel::successionParams() const {
  return succession_params_;
}

RoadGenParams ConfigurationPanel::roadGenParams() const {
  return road_gen_params_;
}

float ConfigurationPanel::gravity() const {
  return gravity_;
}

void ConfigurationPanel::render() {
  ImGui::Begin( "Configuration Panel" );

  ImGui::SeparatorText( "Evolution" );
  ImGui::SliderInt( "Population Size", &population_size_, 1, 50 );

  renderReproductionControls();
  renderMutationControls();
  renderSuccessionControls();

  renderRoadGeneratorControls();

  ImGui::SeparatorText( "Simulation" );
  renderGravityControl();

  if( ImGui::Button( "Start" ) ) {
    start_evolution_ = true;
  }

  ImGui::End();
}

void ConfigurationPanel::renderMutationControls() {
  ImGui::SeparatorText( "Mutation" );

  const char* mutation_variants[] = { "Gaussian", "None" };
  int current_variant = static_cast<int>( mutation_variant_ );
  if( ImGui::Combo( "Mutation Variant", &current_variant, mutation_variants,
                    IM_ARRAYSIZE( mutation_variants ) ) ) {
    mutation_variant_ = static_cast<MutationVariant>( current_variant );
    adjustMutationParamsType();
  }

  std::visit( MutationControlsVisitor{}, mutation_params_ );
}

void ConfigurationPanel::renderReproductionControls() {
  ImGui::SeparatorText( "Reproduction" );

  const char* reproduction_variants[] = { "Proportional", "Tournament", "Random" };
  int current_variant = static_cast<int>( reproduction_variant_ );
  if( ImGui::Combo( "Reproduction Variant", &current_variant, reproduction_variants,
                    IM_ARRAYSIZE( reproduction_variants ) ) ) {
    reproduction_variant_ = static_cast<ReproductionVariant>( current_variant );
    adjustReproductionParamsType();
  }

  std::visit( ReproductionControlsVisitor{}, reproduction_params_ );
}

void ConfigurationPanel::renderSuccessionControls() {
  ImGui::SeparatorText( "Succession" );

  const char* succession_variants[] = { "Generation", "Elitist" };
  int current_variant = static_cast<int>( succession_variant_ );
  if( ImGui::Combo( "Succession Variant", &current_variant, succession_variants,
                    IM_ARRAYSIZE( succession_variants ) ) ) {
    succession_variant_ = static_cast<SuccessionVariant>( current_variant );
    adjustSuccessionParamsType();
  }

  std::visit( SuccessionControlsVisitor{ population_size_ }, succession_params_ );
}

void ConfigurationPanel::adjustSuccessionParamsType() {
  switch( succession_variant_ ) {
    case SuccessionVariant::GENERATION:
      succession_params_ = GenerationSuccessionParams{};
      break;
    case SuccessionVariant::ELITIST:
      succession_params_ = ElitistSuccessionParams{ 1 };
      break;
  }
}

void ConfigurationPanel::adjustReproductionParamsType() {
  switch( reproduction_variant_ ) {
    case ReproductionVariant::TOURNAMENT:
      reproduction_params_ = TournamentReproductionParams{ 1 };
      break;
    case ReproductionVariant::PROPORTIONAL:
      reproduction_params_ = ProportionalReproductionParams{};
      break;
    case ReproductionVariant::RANDOM:
      reproduction_params_ = RandomReproductionParams{};
      break;
  }
}
void ConfigurationPanel::adjustMutationParamsType() {
  switch( mutation_variant_ ) {
    case MutationVariant::NONE:
      mutation_params_ = NoMutationParams{};
      break;
    case MutationVariant::GAUSSIAN:
      mutation_params_ = GaussianMutationParams{ 0.1 };
  }
}

void ConfigurationPanel::renderRoadGeneratorControls() {
  auto& params = road_gen_params_;
  ImGui::SeparatorText( "Road generator" );
  ImGui::SliderInt( "Number of points:", &params.length_, 1, 300 );
  ImGui::SliderInt( "Perlin grid size", &params.grid_size_, 1, 500 );
  ImGui::SliderInt( "Perlin Layers", &params.layers_, 1, 50 );
  ImGui::SliderFloat( "Y Scale", &params.scale_y_, 1, 15 );
  ImGui::SliderFloat( "X Scale", &params.scale_x_, 1, 15 );
}
void ConfigurationPanel::renderGravityControl() {
  ImGui::SliderFloat( "Gravity (in m/s^2):", &gravity_, 0, 20 );
}
