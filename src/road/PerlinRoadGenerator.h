//
// Created by Michał on 08/01/2025.
//

#ifndef EVOLUTION_PERLINROADGENERATOR_H
#define EVOLUTION_PERLINROADGENERATOR_H
#include "RoadGenerator.h"
/**
 * @ingroup road
 * @brief A class that generates a road using perlin noise.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

class PerlinRoadGenerator: public RoadGenerator {
 public:
  using Point = std::pair<float, float>;
  /**
   * @brief Constructor for PerlinRoadGenerator.
   * @param layers The number of layers of the perlin noise.
   * @param scale The scale of the maximum road height.
   */
  PerlinRoadGenerator(int layers, int scale): layers_(layers), scale_(scale) {};
  ~PerlinRoadGenerator() override = default;

 private:
  Road generateRoadImpl() const override;

  int layers_;
  int scale_;
};

#endif  // EVOLUTION_PERLINROADGENERATOR_H
