#include <gtest/gtest.h>

#include "Road.h"
#include "RoadGenerator.h"
#include "StaticRoadGenerator.h"

using namespace std;
namespace StaticRoadGeneratorTest {
using Point = std::pair<float, float>;

TEST( StaticRoadGenerator, generateWithDefaultConstructor ) {
  const unique_ptr<RoadGenerator> road_generator = make_unique<StaticRoadGenerator>();
  const Road road = road_generator->generateRoad();
  EXPECT_EQ( road.points_.size(), 23 );

  for( size_t i = 0; i < road.points_.size() - 1; ++i ) {
    EXPECT_TRUE( road.points_[i].first < road.points_[i + 1].first );
  }
}

TEST( StaticRoadGenerator, generateWithPassedPoints ) {
  const std::vector<Point> points = {
      { -11.0f, 0.0f }, { -7.0f, 1.0f }, { -6.0f, 0.5f },  { -5.0f, 0.0f }, { -4.0f, 0.0f },
      { -3.0f, 0.0f },  { -2.0f, 0.0f }, { -1.0f, 0.0f },  { 0.0f, 0.0f },  { 1.0f, 0.0f },
      { 2.0f, 0.0f },   { 3.0f, 0.0f },  { 4.0f, 0.0f },   { 5.0f, 0.0f },  { 6.0f, 0.0f },
      { 7.0f, 0.0f },   { 8.0f, 0.0f },  { 9.0f, 0.0f },   { 10.0f, 0.0f }, { 11.0f, 0.0f },
      { 12.0f, 0.0f },  { 13.0f, 0.0f }, { 100.0f, 0.0f },
  };

  const unique_ptr<RoadGenerator> road_generator = make_unique<StaticRoadGenerator>( points );
  const Road road = road_generator->generateRoad();
  EXPECT_EQ( road.points_.size(), points.size() );
  for( auto i = 0; i < points.size(); ++i ) {
    EXPECT_EQ( points[i], road.points_[i] );
  }
}

}  // namespace StaticRoadGeneratorTest