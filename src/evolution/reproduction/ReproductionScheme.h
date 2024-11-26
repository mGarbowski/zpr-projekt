//
// Created by mgarbowski on 11/26/24.
//

#ifndef REPRODUCTIONSCHEME_H
#define REPRODUCTIONSCHEME_H

#include <memory>
#include <vector>

#include "../Specimen.h"

using Population = std::vector<Specimen>;

/**
* @ingroup evolution
* @brief Interface for creating a new population from the old one using fitness values
*/
class ReproductionScheme {
 public:
  ReproductionScheme() = default;
  virtual ~ReproductionScheme() = default;

  Population reproducePopulation(const Population& population,
                                 const std::vector<float>& fitness) const;

 protected:
  virtual Population doReproducePopulation(const Population& population,
                                           std::vector<float> fitness) const = 0;
};

using UReproductionScheme = std::unique_ptr<ReproductionScheme>;

#endif  // REPRODUCTIONSCHEME_H
