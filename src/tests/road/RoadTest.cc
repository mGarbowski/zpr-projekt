#include <gtest/gtest.h>

#include "GenericRoadGenerator.h"
#include "Road.h"
#include "StaticRoadGenerator.h"

using namespace std;
namespace RoadTest {
using Point = std::pair<float, float>;

TEST(RoadTest, StaticRoadGeneration) {
  const unique_ptr<GenericRoadGenerator> road_generator = make_unique<StaticRoadGenerator>();
  const Road road = road_generator->generateRoad();
  EXPECT_EQ(road.points_.size(), 23);
  EXPECT_EQ(road.points_[0], Point(-11.0, 0.0));
  EXPECT_EQ(road.points_[1], Point(-7.0, 1.0));
  EXPECT_EQ(road.points_[2], Point(-6.0, 0.5));
  EXPECT_EQ(road.points_[3], Point(-5.0, 0.0));
  EXPECT_EQ(road.points_[4], Point(-4.0, 0.0));
}

}  // namespace RoadTest