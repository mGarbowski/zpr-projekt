#include <PerlinRoadGenerator.h>
#include <RoadGenerator.h>
#include <gtest/gtest.h>

namespace PerlinRoadGeneratorTest {

TEST( PerlinRoadGeneratorTest, generateRoad ) {
  constexpr auto length = 50;
  constexpr auto grid_size = 200;
  constexpr auto layers = 20;
  constexpr auto scale_y = 10;
  constexpr auto scale_x = 8;
  const URoadGenerator road_generator =
      std::make_unique<PerlinRoadGenerator>( length, grid_size, layers, scale_y, scale_x );

  auto road = road_generator->generateRoad();

  // Should have the correct number of points
  EXPECT_EQ( road.points_.size(), length );

  // Should start at (0, 0)
  constexpr auto expected_first_point = std::pair<float, float>{ 0, 0 };
  EXPECT_EQ( road.points_[0], expected_first_point );

  // Should have points in increasing x order
  for( auto i = 0; i < road.points_.size() - 1; ++i ) {
    EXPECT_LT( road.points_[i].first, road.points_[i + 1].first );
  }

  // Should have expected last x value
  constexpr auto expected_last_x = ( length - 1 ) * scale_x;
  EXPECT_EQ( road.points_[length - 1].first, expected_last_x );

  // Should have points in the correct y range
  for( const auto& [x, y] : road.points_ ) {
    EXPECT_GE( y, -scale_y );
    EXPECT_LE( y, scale_y );
  }
}

}  // namespace PerlinRoadGeneratorTest