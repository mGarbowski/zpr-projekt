/**
 * @ingroup evolution
 * @brief Two-point crossover
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_TWOPOINTCROSSOVERSCHEME_H
#define EVOLUTION_TWOPOINTCROSSOVERSCHEME_H
#include "CrossoverScheme.h"

class TwoPointCrossoverScheme : public CrossoverScheme {
 public:
  explicit TwoPointCrossoverScheme( const std::mt19937& random_number_generator,
                                    const float crossover_prob )
      : random_number_generator_( random_number_generator ), crossover_prob_( crossover_prob ) {}

 protected:
  virtual Population doCrossoverPopulation( const Population& population );

 private:
  std::mt19937 random_number_generator_;
  float crossover_prob_;

  std::pair<std::vector<float>, std::vector<float>> twoPointCrossover(
      const std::vector<float>& parent1, const std::vector<float>& parent2 );
};

#endif  // EVOLUTION_TWOPOINTCROSSOVERSCHEME_H
