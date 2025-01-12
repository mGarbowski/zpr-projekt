/**
 * @ingroup app
 * @brief Panel for configuring the evolution parameters before it starts.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef CONFIGURATIONPANEL_H
#define CONFIGURATIONPANEL_H

#include <variant>

#include "mutation/MutationSchemeFactory.h"

class ConfigurationPanel {
 public:
  explicit ConfigurationPanel()
      : population_size_( 20 ),
        start_evolution_( false ),
        mutation_variant_( MutationVariant::GAUSSIAN ),
        mutation_params_( GaussianMutationParams{ 0.1 } ) {}

  int populationSize() const;
  bool shouldStartEvolution() const;
  MutationVariant mutationVariant() const;
  MutationParams mutationParams() const;

  void render();

 private:
  void renderMutationControls();

  int population_size_;
  bool start_evolution_;
  MutationVariant mutation_variant_;
  MutationParams mutation_params_;
};

#endif  // CONFIGURATIONPANEL_H
