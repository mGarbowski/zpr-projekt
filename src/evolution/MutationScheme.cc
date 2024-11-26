//
// Created by mgarbowski on 11/26/24.
//

#include "MutationScheme.h"
void MutationScheme::mutatePopulation(std::vector<Specimen>& population) const {
  for (auto& specimen : population) {
    mutateSpecimen(specimen);
  }
}
void MutationScheme::mutateSpecimen(Specimen& specimen) const {
  doMutateSpecimen(specimen);
}