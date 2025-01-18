/**
 * @ingroup evolution
 * @brief Dummy crossover variant that does not crossover any specimens
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "NoCrossoverScheme.h"
Population NoCrossoverScheme::doCrossoverPopulation( const Population& population ) {
  return population;
}
