/**
 * @ingroup evolution
 * @brief Implementation of CrossoverScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "CrossoverScheme.h"
Population CrossoverScheme::crossoverPopulation( const Population& population ) {
  return doCrossoverPopulation( population );
}