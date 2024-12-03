/**
 * @ingroup evolution
 * @brief Interface for creating a new population from the old one using fitness values
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef REPRODUCTIONSCHEME_H
#define REPRODUCTIONSCHEME_H

#include <memory>
#include <vector>

#include "../Specimen.h"

class ReproductionScheme {
 public:
  ReproductionScheme() = default;
  virtual ~ReproductionScheme() = default;

  Population reproducePopulation(const Population& population, const std::vector<float>& fitness);

 protected:
  virtual Population doReproducePopulation(const Population& population,
                                           std::vector<float> fitness) = 0;
};

using UReproductionScheme = std::unique_ptr<ReproductionScheme>;

#endif  // REPRODUCTIONSCHEME_H
