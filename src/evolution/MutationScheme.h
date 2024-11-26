//
// Created by mgarbowski on 11/26/24.
//

#ifndef MUTATIONSCHEME_H
#define MUTATIONSCHEME_H

#include "Specimen.h"

/**
 * @ingroup evolution
 * @brief Interface for mutating a population
 */
class MutationScheme {
 public:
  MutationScheme() = default;
  virtual ~MutationScheme() = default;

  void mutatePopulation(std::vector<Specimen>& population) const;

  void mutateSpecimen(Specimen& specimen) const;

 protected:
  virtual void doMutateSpecimen(Specimen& specimen) const = 0;
};

#endif  // MUTATIONSCHEME_H
