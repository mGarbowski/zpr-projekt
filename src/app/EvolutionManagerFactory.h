/**
 * @ingroup app
 * @brief Factory for creating EvolutionManager objects based on UI configuration.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTIONMANAGERFACTORY_H
#define EVOLUTIONMANAGERFACTORY_H

#include "ConfigurationPanel.h"
#include "EvolutionManager.h"

class EvolutionManagerFactory {
 public:
  static EvolutionManager create( const ConfigurationPanel& configuration_panel, std::mt19937 rng );
};

#endif  // EVOLUTIONMANAGERFACTORY_H
