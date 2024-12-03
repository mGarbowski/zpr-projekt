//
// Created by mgarbowski on 11/26/24.
//

#ifndef MUTATIONSCHEME_H
#define MUTATIONSCHEME_H

#include <memory>

#include "../Specimen.h"

/**
 * @ingroup evolution
 * @brief Interface for mutating a population
 */
class MutationScheme {
 public:
  MutationScheme() = default;
  virtual ~MutationScheme() = default;

  void mutatePopulation(std::vector<Specimen>& population);

  void mutateSpecimen(Specimen& specimen);

 protected:
  virtual void doMutateSpecimen(Specimen& specimen) = 0;
};

using UMutationScheme = std::unique_ptr<MutationScheme>;

#endif  // MUTATIONSCHEME_H
