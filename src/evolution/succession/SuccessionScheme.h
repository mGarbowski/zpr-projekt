//
// Created by mgarbowski on 11/26/24.
//

#ifndef SUCCESSIONSCHEME_H
#define SUCCESSIONSCHEME_H

#include <memory>
#include <vector>

#include "../Specimen.h"

/**
 * @ingroup evolution
 * @brief Interface for creating a population for the next iteration of evolution
 */
class SuccessionScheme {
 public:
  SuccessionScheme() = default;
  virtual ~SuccessionScheme() = default;

  /**
   * @brief Create a new population for the next iteration of evolution
   * @param previous_population The population from the start of the iteration
   * @param mutants The population after genetic operations
   * @param fitness The fitness of each specimen in the previous population
   */
  Population nextGeneration(const Population& previous_population, const Population& mutants,
                            const std::vector<float>& fitness) const;

 protected:
  virtual Population doNextGeneration(const Population& previous_population,
                                      const Population& mutants,
                                      const std::vector<float>& fitness) const = 0;
};

using USuccessionScheme = std::unique_ptr<SuccessionScheme>;

#endif  // SUCCESSIONSCHEME_H
