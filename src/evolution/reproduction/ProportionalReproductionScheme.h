/**
 * @ingroup evolution
 * @brief Proportional reproduction concrete implementation of ReproductionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef PROPORTIONALREPRODUCTIONSCHEME_H
#define PROPORTIONALREPRODUCTIONSCHEME_H

#include <random>

#include "ReproductionScheme.h"

class ProportionalReproductionScheme : public ReproductionScheme {
 public:
  explicit ProportionalReproductionScheme( std::mt19937 random_engine )
      : random_engine_( random_engine ) {}

 protected:
  Population doReproducePopulation( const Population& population,
                                    std::vector<float> fitness ) override;

 private:
  std::mt19937 random_engine_;
};

#endif  // PROPORTIONALREPRODUCTIONSCHEME_H
