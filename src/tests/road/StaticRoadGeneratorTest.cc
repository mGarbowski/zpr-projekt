#include <gtest/gtest.h>

#include "Road.h"
#include "RoadGenerator.h"
#include "StaticRoadGenerator.h"

using namespace std;
namespace RoadTest {
using Point = std::pair<float, float>;

TEST(StaticRoadGenerator, generateWithDefaultConstructor) {
  const unique_ptr<RoadGenerator> road_generator = make_unique<StaticRoadGenerator>();
  const Road road = road_generator->generateRoad();
  EXPECT_EQ(road.points_.size(), 23);
  EXPECT_EQ(road.points_[0], Point(-11.0, 0.0));
  EXPECT_EQ(road.points_[1], Point(-7.0, 1.0));
  EXPECT_EQ(road.points_[2], Point(-6.0, 0.5));
  EXPECT_EQ(road.points_[3], Point(-5.0, 0.0));
  EXPECT_EQ(road.points_[4], Point(-4.0, 0.0));
}

TEST(StaticRoadGenerator, generateWithPassedPoints) {
  const std::vector<Point> points = {
      {-11.0f, 0.0f}, {-7.0f, 1.0f}, {-6.0f, 0.5f}, {-5.0f, 0.0f}, {-4.0f, 0.0f},  {-3.0f, 0.0f},
      {-2.0f, 0.0f},  {-1.0f, 0.0f}, {0.0f, 0.0f},  {1.0f, 0.0f},  {2.0f, 0.0f},   {3.0f, 0.0f},
      {4.0f, 0.0f},   {5.0f, 0.0f},  {6.0f, 0.0f},  {7.0f, 0.0f},  {8.0f, 0.0f},   {9.0f, 0.0f},
      {10.0f, 0.0f},  {11.0f, 0.0f}, {12.0f, 0.0f}, {13.0f, 0.0f}, {100.0f, 0.0f},
  };

  const unique_ptr<RoadGenerator> road_generator = make_unique<StaticRoadGenerator>(points);
  const Road road = road_generator->generateRoad();
  EXPECT_EQ(road.points_.size(), points.size());
  for (auto i = 0; i < points.size(); ++i) {
    EXPECT_EQ(points[i], road.points_[i]);
  }
}

}  // namespace RoadTest