//
// Created by mgarbowski on 11/3/24.
//


#ifndef ROAD_GENERATOR_H
#define ROAD_GENERATOR_H

#include <utility>
#include <vector>

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

class GenericRoadGenerator {
public:
    virtual ~GenericRoadGenerator() = default;

    GenericRoadGenerator() = default;

    /// Pure virtual function that returns a Road class
    virtual Road generateRoad() const = 0;

    // Delete copy constructor and assignment operator to prevent slicing
    GenericRoadGenerator(const GenericRoadGenerator&) = delete;
    GenericRoadGenerator& operator=(const GenericRoadGenerator&) = delete;
};

#endif //ROAD_GENERATOR_H
