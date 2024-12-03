/**
 * @ingroup road
 * @brief Abstract base class for road generation
 * @authors Mikolaj Garbowski, Michal Luszczek
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

#ifndef ROAD_GENERATOR_H
#define ROAD_GENERATOR_H

#include <memory>

#include "Road.h"

class RoadGenerator {
 public:
  virtual ~RoadGenerator() = default;

  RoadGenerator() = default;

  /// generateRoadImpl has to be implemented in each child class
  Road generateRoad() {
    return generateRoadImpl();
  };

  // Delete copy constructor and assignment operator to prevent slicing
  RoadGenerator( const RoadGenerator& ) = delete;
  RoadGenerator& operator=( const RoadGenerator& ) = delete;

 private:
  /// Pure virtual function that returns a Road class
  virtual Road generateRoadImpl() const = 0;
};

using URoadGenerator = std::unique_ptr<RoadGenerator>;

#endif  // ROAD_GENERATOR_H
