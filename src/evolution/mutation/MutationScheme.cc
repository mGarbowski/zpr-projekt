/**
 * @ingroup evolution
 * @brief Implementation of MutationScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "MutationScheme.h"
void MutationScheme::mutatePopulation(std::vector<Specimen>& population) {
  for (auto& specimen : population) {
    mutateSpecimen(specimen);
  }
}
void MutationScheme::mutateSpecimen(Specimen& specimen) {
  doMutateSpecimen(specimen);
}