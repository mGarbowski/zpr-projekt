/**
 * @ingroup app
 * @brief Panel for configuring the evolution parameters before it starts.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef CONFIGURATIONPANEL_H
#define CONFIGURATIONPANEL_H

#include <variant>

#include "mutation/MutationSchemeFactory.h"
#include "reproduction/ReproductionSchemeFactory.h"
#include "succession/SuccessionSchemeFactory.h"
#include "crossover/CrossoverSchemeFactory.h"

struct RoadGenParams {
  int length_;
  int grid_size_;
  int layers_;
  float scale_y_;
  float scale_x_;
};

class ConfigurationPanel {
 public:
  explicit ConfigurationPanel()
      : population_size_( 10 ),
        start_evolution_( false ),
        mutation_variant_( MutationVariant::GAUSSIAN ),
        mutation_params_( GaussianMutationParams{ 0.1 } ),
        reproduction_variant_( ReproductionVariant::PROPORTIONAL ),
        reproduction_params_( ProportionalReproductionParams{} ),
        succession_variant_( SuccessionVariant::GENERATION ),
        succession_params_( GenerationSuccessionParams{} ),
        crossover_variant_(CrossoverVariant::NONE),
        crossover_params_(NoCrossoverParams{}),
        gravity_( 9.81 ),
        road_gen_params_( RoadGenParams{ 50, 200, 20, 10, 8 } ),
        distance_weight_( 1.0 ),
        speed_weight_( 1000.0 ),
        computation_limit_( 10000 ) {}

  int populationSize() const;
  bool shouldStartEvolution() const;
  MutationVariant mutationVariant() const;
  MutationParams mutationParams() const;
  ReproductionVariant reproductionVariant() const;
  ReproductionParams reproductionParams() const;
  SuccessionVariant successionVariant() const;
  SuccessionParams successionParams() const;
  CrossoverVariant crossoverVariant() const;
  CrossoverParams crossoverParams() const;
  RoadGenParams roadGenParams() const;
  float gravity() const;
  float distanceWeight() const;
  float speedWeight() const;
  int computationLimit() const;

  void render();

 private:
  void renderFitnessFunctionControls();
  void renderMutationControls();
  void renderReproductionControls();
  void renderSuccessionControls();
  void renderCrossoverControls();
  void adjustSuccessionParamsType();
  void adjustReproductionParamsType();
  void adjustMutationParamsType();
  void adjustCrossoverParamsType();
  void renderRoadGeneratorControls();
  void renderSimulationControls();

  int population_size_;
  bool start_evolution_;
  MutationVariant mutation_variant_;
  MutationParams mutation_params_;
  ReproductionVariant reproduction_variant_;
  ReproductionParams reproduction_params_;
  SuccessionVariant succession_variant_;
  SuccessionParams succession_params_;
  CrossoverVariant crossover_variant_;
  CrossoverParams crossover_params_;
  float gravity_;
  RoadGenParams road_gen_params_;
  float distance_weight_;
  float speed_weight_;
  int computation_limit_;
};

#endif  // CONFIGURATIONPANEL_H
