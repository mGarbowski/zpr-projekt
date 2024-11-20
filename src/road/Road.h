//
// Created by mgarbowski on 11/3/24.
//


#ifndef ROAD_H
#define ROAD_H

#include <vector>
#include <utility>

class Road {
public:
    // Virtual destructor for abstract class
    virtual ~Road() = default;

    Road() = default;

    // Pure virtual function that returns vector of pairs of floats
    virtual std::vector<std::pair<float, float>> getRoadPoints() const = 0;

    // Delete copy constructor and assignment operator to prevent slicing
    Road(const Road&) = delete;
    Road& operator=(const Road&) = delete;

   protected:
    std::vector<std::pair<float, float>> road_points_;

};

int add(int a, int b);

#endif //ROAD_H
