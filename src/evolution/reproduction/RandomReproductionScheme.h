/**
 * @ingroup evolution
 * @brief Random reproduction, concrete implementation of ReproductionScheme
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_RANDOMREPRODUCTIONSCHEME_H
#define EVOLUTION_RANDOMREPRODUCTIONSCHEME_H
#include <random>

#include "ReproductionScheme.h"
class RandomReproductionScheme : public ReproductionScheme {
 public:
  explicit RandomReproductionScheme( std::mt19937 random_engine )
      : random_engine_( random_engine ) {}

 protected:
  Population doReproducePopulation( const Population& population,
                                    std::vector<float> fitness ) override;

 private:
  std::mt19937 random_engine_;
};

#endif  // EVOLUTION_RANDOMREPRODUCTIONSCHEME_H
