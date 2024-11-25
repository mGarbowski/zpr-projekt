//
// Created by Michał on 20/11/2024.
//

#ifndef EVOLUTION_STATICROADGENERATOR_H
#define EVOLUTION_STATICROADGENERATOR_H

#include "GenericRoadGenerator.h"
class StaticRoadGenerator : public GenericRoadGenerator {
public:
    StaticRoadGenerator() = default;
    ~StaticRoadGenerator() override = default;
    // Always returns the same road for testing purposes
    Road generateRoad() const override;
};

#endif  // EVOLUTION_STATICROADGENERATOR_H
