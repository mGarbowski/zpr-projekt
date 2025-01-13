/**
 * @ingroup road
 * @brief A class that generates a road using perlin noise.
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#ifndef EVOLUTION_PERLINROADGENERATOR_H
#define EVOLUTION_PERLINROADGENERATOR_H
#include "RoadGenerator.h"

class PerlinRoadGenerator : public RoadGenerator {
 public:
  using Point = std::pair<float, float>;
  /**
   * @brief Constructor for PerlinRoadGenerator.
   * @param length The number of points on on the road. Gets scaled with scale_x
   * @param grid_size The size of the grid for perlin noise generation, higher = more consistent
   * terrain
   * @param layers The number of layers of the perlin noise.
   * @param scale_y Changes the maximum and minimum road height. higher=higher peaks.
   * @param scale_x The distance between points of the road. The higher, the more gentle the slopes.
   */
  PerlinRoadGenerator( int length, int grid_size, int layers, float scale_y, float scale_x )
      : grid_size_( grid_size ),
        length_( length ),
        layers_( layers ),
        scale_y_( scale_y ),
        scale_x_( scale_x ){};
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
