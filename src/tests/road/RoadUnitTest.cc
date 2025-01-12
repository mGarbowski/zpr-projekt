#include <gtest/gtest.h>

#include "Road.h"

namespace RoadUnitTest {
using Point = std::pair<float, float>;

TEST( Road, storesPassedPoints ) {
  const std::vector<Point> points = { { 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 } };

  const Road road( points );

  EXPECT_EQ( road.points_, points );
}

}  // namespace RoadUnitTest
