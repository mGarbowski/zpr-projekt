//
// Created by Michał on 20/11/2024.
//

#include "StaticRoadGenerator.h"
Road StaticRoadGenerator::generateRoad() const {
  return Road(std::vector<std::pair<float, float>>{
      {0.0f, 0.0f},
      {1.0f, 1.0f},
      {2.0f, 1.0f},
      {3.0f, 1.0f},
      {4.0f, 0.0f},
      {5.0f, 2.0f},
      {6.0f, 1.0f},
      {7.0f, 1.0f},
      {8.0f, 0.0f},
      {9.0f, 0.0f}
  });
}
