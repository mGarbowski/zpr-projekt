/**
 * @ingroup evolution
 * @brief Succession with an elite
 * @authors Mikołaj Garbowski, Michał Łuszczek
 *
 * The elite are the best specimens from the original population.
 * the next population consists of elite and a subset of mutants.
 */

#include "ElitistSuccessionScheme.h"
Population ElitistSuccessionScheme::doNextGeneration( const Population& previous_population,
                                                      const Population& mutants,
                                                      const std::vector<float>& fitness ) const {
  return Population();
}