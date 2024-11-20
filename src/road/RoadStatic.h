//
// Created by Michał on 20/11/2024.
//

#ifndef EVOLUTION_ROADSTATIC_H
#define EVOLUTION_ROADSTATIC_H

#include "Road.h"
class RoadStatic: protected Road {
// create constuctor which takes in a vector of float std_pairs and creates a road
public:
    RoadStatic(std::vector<std::pair<float, float>> point_pairs);

    //getroadpoints
    std::vector<std::pair<float, float>> getRoadPoints() const override;
};

#endif  // EVOLUTION_ROADSTATIC_H
