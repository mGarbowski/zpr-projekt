//
// Created by michluszcz on 23.11.24.
//

#ifndef ROAD_H
#define ROAD_H

#include <vector>
/**
 * @brief class serving as a container for points creating a road
 */
class Road {
public:
    Road(std::vector<std::pair<float, float>> road) : points_(std::move(road)) {}

    std::vector<std::pair<float, float>> points_;
};
#endif  // ROAD_H
