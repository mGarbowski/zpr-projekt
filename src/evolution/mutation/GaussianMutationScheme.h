//
// Created by mgarbowski on 11/26/24.
//

#ifndef GAUSSIANMUTATIONSCHEME_H
#define GAUSSIANMUTATIONSCHEME_H
#include <random>

#include "MutationScheme.h"

/**
 * @ingroup evolution
 * @brief Gaussian mutation with the same mutation strength for each attribute
 */
class GaussianMutationScheme : public MutationScheme {
 public:
  explicit GaussianMutationScheme(const double mutation_strength,
                                  const std::mt19937& random_number_generator)
      : random_number_generator_(random_number_generator),
        normal_distribution_(0.0, mutation_strength) {}

 protected:
  void doMutateSpecimen(Specimen& specimen) override {
    for (auto& attribute : specimen.attributes()) {
      attribute += normal_distribution_(random_number_generator_);
    }
  }

 private:
  std::mt19937 random_number_generator_;
  std::normal_distribution<> normal_distribution_;
};

#endif  // GAUSSIANMUTATIONSCHEME_H
