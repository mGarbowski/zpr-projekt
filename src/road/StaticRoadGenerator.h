//
// Created by Michał on 20/11/2024.
//

#ifndef EVOLUTION_STATICROADGENERATOR_H
#define EVOLUTION_STATICROADGENERATOR_H

#include "RoadGenerator.h"
/**
 * @brief A class that generates a static road for testing purposes.
 */
class StaticRoadGenerator : public RoadGenerator {
 public:
  using Point = std::pair<float, float>;
  StaticRoadGenerator();
  explicit StaticRoadGenerator(const std::vector<Point>& points): points_(points) {}
  ~StaticRoadGenerator() override = default;
  /**
   * Always returns the same road for testing purposes
   */


 private:
  Road generateRoadImpl() const override;
  std::vector<Point> points_;
};

#endif  // EVOLUTION_STATICROADGENERATOR_H
