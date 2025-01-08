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
  PerlinRoadGenerator(int length, int grid_size, int layers, float scale_y, float scale_x): grid_size_(grid_size), length_( length ), layers_(layers), scale_y_(scale_y), scale_x_(scale_x) {};
  ~PerlinRoadGenerator() override = default;

 private:
  Road generateRoadImpl() const override;
  int length_;
  int grid_size_;
  int layers_;
  float scale_y_;
  float scale_x_;
};

#endif  // EVOLUTION_PERLINROADGENERATOR_H
