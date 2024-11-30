//
// Created by mgarbowski on 11/26/24.
//

#include "GaussianMutationScheme.h"
void GaussianMutationScheme::doMutateSpecimen(Specimen& specimen) {
  for (auto& attribute : specimen.attributesRef()) {
    attribute += normal_distribution_(random_number_generator_);
  }
}