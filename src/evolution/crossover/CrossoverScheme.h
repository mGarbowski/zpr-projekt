/**
 * @ingroup evolution
 * @brief Interface for creating new specimens from 2 parents for larger exploration
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_CROSSOVERSCHEME_H
#define EVOLUTION_CROSSOVERSCHEME_H
#include <memory>
#include <vector>

#include "../Specimen.h"

class CrossoverScheme {
 public:
  CrossoverScheme() = default;
  virtual ~CrossoverScheme() = default;

  Population crossoverPopulation( const Population& population );

 protected:
  virtual Population doCrossoverPopulation( const Population& population) = 0;
};

using UCrossoverScheme = std::unique_ptr<CrossoverScheme>;

#endif  // EVOLUTION_CROSSOVERSCHEME_H
