#include <gtest/gtest.h>

#include "Road.h"
#include "GenericRoadGenerator.h"
#include "StaticRoadGenerator.h"

namespace TestTest {
  TEST(RoadTest, test) {
    EXPECT_EQ(add(2, 2), 4);
  }

  TEST(RoadTest, StaticRoadGeneration) {
    GenericRoadGenerator* road_generator = new StaticRoadGenerator();
    Road road = road_generator->generateRoad();
    EXPECT_EQ(road.points_[0].first,  0);
    EXPECT_EQ(road.points_[0].second,  0);
  }
  }  // namespace TestTest