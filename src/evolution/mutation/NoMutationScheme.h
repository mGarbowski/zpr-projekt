/**
 * @ingroup evolution
 * @brief Dummy mutation variant that does not mutate the population
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef NOMUTATION_H
#define NOMUTATION_H
#include "MutationScheme.h"

class NoMutationScheme : public MutationScheme {
 protected:
  void doMutateSpecimen( Specimen& specimen ) override;
};

#endif  // NOMUTATION_H
