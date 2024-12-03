/**
 * @ingroup evolution
 * @brief Interface for mutating a population
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef MUTATIONSCHEME_H
#define MUTATIONSCHEME_H

#include <memory>

#include "../Specimen.h"

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
