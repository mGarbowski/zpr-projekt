#include <gtest/gtest.h>

#include "GenericRoadGenerator.h"
#include "Road.h"
#include "StaticRoadGenerator.h"

namespace TestTest {

TEST(RoadTest, StaticRoadGeneration) {
  GenericRoadGenerator* road_generator = new StaticRoadGenerator();
  Road road = road_generator->generateRoad();
  EXPECT_EQ(road.points_[0].first, 0);
  EXPECT_EQ(road.points_[0].second, 0);
}

}  // namespace TestTest