/**
 * @ingroup evolution
 * @brief Implementation of GaussianMutationScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "GaussianMutationScheme.h"
void GaussianMutationScheme::doMutateSpecimen( Specimen& specimen ) {
  for( auto& attribute : specimen.attributesRef() ) {
    attribute += normal_distribution_( random_number_generator_ );
  }
}