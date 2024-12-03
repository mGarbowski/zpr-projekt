/**
 * @ingroup road
 * @brief Implementation of StaticRoadGenerator
 * @authors Mikolaj Garbowski, Michal Luszczek
 */

#include "StaticRoadGenerator.h"
StaticRoadGenerator::StaticRoadGenerator() {
  this->points_ = {
      {-11.0f, 0.0f}, {-7.0f, 1.0f}, {-6.0f, 0.5f}, {-5.0f, 0.0f}, {-4.0f, 0.0f},  {-3.0f, 0.0f},
      {-2.0f, 0.0f},  {-1.0f, 0.0f}, {0.0f, 0.0f},  {1.0f, 0.0f},  {2.0f, 0.0f},   {3.0f, 0.0f},
      {4.0f, 0.0f},   {5.0f, 0.0f},  {6.0f, 0.0f},  {7.0f, 0.0f},  {8.0f, 0.0f},   {9.0f, 0.0f},
      {10.0f, 0.0f},  {11.0f, 0.0f}, {12.0f, 0.0f}, {13.0f, 0.0f}, {100.0f, 0.0f},
  };
}

Road StaticRoadGenerator::generateRoadImpl() const {
  return Road(points_);
}
