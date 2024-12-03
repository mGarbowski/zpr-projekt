/**
 * @ingroup road
 * @brief A class that generates a static road for testing purposes.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_STATICROADGENERATOR_H
#define EVOLUTION_STATICROADGENERATOR_H

#include "RoadGenerator.h"

class StaticRoadGenerator : public RoadGenerator {
 public:
  using Point = std::pair<float, float>;
  StaticRoadGenerator();
  explicit StaticRoadGenerator(const std::vector<Point>& points) : points_(points) {}
  ~StaticRoadGenerator() override = default;

 private:
  Road generateRoadImpl() const override;
  std::vector<Point> points_;
};

#endif  // EVOLUTION_STATICROADGENERATOR_H
