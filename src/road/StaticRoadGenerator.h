//
// Created by Michał on 20/11/2024.
//

#ifndef EVOLUTION_STATICROADGENERATOR_H
#define EVOLUTION_STATICROADGENERATOR_H

#include "GenericRoadGenerator.h"
/**
 * @brief A class that generates a static road for testing purposes.
 * This class is used to generate a road that is always the same for testing purposes.
 * It inherits from the GenericRoadGenerator class.
 */
class StaticRoadGenerator : public GenericRoadGenerator {
 public:
  using Point = std::pair<float, float>;
  StaticRoadGenerator();
  ~StaticRoadGenerator() override = default;
  /**
   * Always returns the same road for testing purposes
   */
  Road generateRoad() const override;

 private:
  std::vector<Point> points_;
};

#endif  // EVOLUTION_STATICROADGENERATOR_H
