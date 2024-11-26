//
// Created by mgarbowski on 11/3/24.
//

#ifndef ROAD_GENERATOR_H
#define ROAD_GENERATOR_H

#include <memory>

#include "Road.h"

/**
 * @brief Abstract base class for road generation
 *
 * GenericRoadGenerator serves as an interface for different road generation strategies.
 * It defines the common interface that all concrete road generators must implement.
 * Usage example:
 * @code
 * class ConcreteRoadGenerator : public GenericRoadGenerator {
 *     Road generateRoad() const override;
 * };
 * @endcode
 */
class RoadGenerator {
 public:
  virtual ~RoadGenerator() = default;

  RoadGenerator() = default;

  /// Pure virtual function that returns a Road class
  virtual Road generateRoad() const = 0;

  // Delete copy constructor and assignment operator to prevent slicing
  RoadGenerator(const RoadGenerator&) = delete;
  RoadGenerator& operator=(const RoadGenerator&) = delete;
};

using URoadGenerator = std::unique_ptr<RoadGenerator>;

#endif  // ROAD_GENERATOR_H
