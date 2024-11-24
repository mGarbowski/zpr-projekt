//
// Created by mgarbowski on 11/3/24.
//


#ifndef ROAD_GENERATOR_H
#define ROAD_GENERATOR_H

#include <utility>
#include <vector>

#include "Road.h"

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
