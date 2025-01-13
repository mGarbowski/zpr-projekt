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

class ConfigurationPanel {
 public:
  explicit ConfigurationPanel()
      : population_size_( 20 ),
        start_evolution_( false ),
        mutation_variant_( MutationVariant::GAUSSIAN ),
        mutation_params_( GaussianMutationParams{ 0.1 } ),
        reproduction_variant_( ReproductionVariant::PROPORTIONAL ),
        reproduction_params_( ProportionalReproductionParams{} ) {}

  int populationSize() const;
  bool shouldStartEvolution() const;
  MutationVariant mutationVariant() const;
  MutationParams mutationParams() const;
  ReproductionVariant reproductionVariant() const;
  ReproductionParams reproductionParams() const;

  void render();

 private:
  void renderMutationControls();
  void renderReproductionControls();
  void adjustReproductionParamsType();

  int population_size_;
  bool start_evolution_;
  MutationVariant mutation_variant_;
  MutationParams mutation_params_;
  ReproductionVariant reproduction_variant_;
  ReproductionParams reproduction_params_;
};

#endif  // CONFIGURATIONPANEL_H
