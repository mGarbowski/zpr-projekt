/**
 * @ingroup evolution
 * @brief Gaussian mutation with the same mutation strength for each attribute
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef GAUSSIANMUTATIONSCHEME_H
#define GAUSSIANMUTATIONSCHEME_H
#include <random>

#include "MutationScheme.h"

class GaussianMutationScheme : public MutationScheme {
 public:
  explicit GaussianMutationScheme(const double mutation_strength,
                                  const std::mt19937& random_number_generator)
      : random_number_generator_(random_number_generator),
        normal_distribution_(0.0, mutation_strength) {}

 protected:
  void doMutateSpecimen(Specimen& specimen) override;

 private:
  std::mt19937 random_number_generator_;
  std::normal_distribution<> normal_distribution_;
};

#endif  // GAUSSIANMUTATIONSCHEME_H
