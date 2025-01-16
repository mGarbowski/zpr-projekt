#include <gtest/gtest.h>

#include "Position.h"

namespace PositionUnitTest {
TEST( Position, storesPassedCoordinates ) {
  const Position position( 1, 2 );
  EXPECT_EQ( 1, position.x_ );
  EXPECT_EQ( 2, position.y_ );
}

TEST( Position, equalityOperator ) {
  const Position position1( 1, 2 );
  const Position position2( 1, 2 );
  const Position position3( 2, 2 );
  const Position position4( 1, 3 );

  EXPECT_EQ( position1, position2 );
  EXPECT_FALSE( position1 == position3 );
  EXPECT_FALSE( position1 == position4 );
}

TEST( Position, asPair ) {
  const Position position( 1, 2 );
  constexpr std::pair<float, float> expected_pair = { 1, 2 };
  EXPECT_EQ( expected_pair, position.asPair() );
}

TEST( Position, toString ) {
  const Position position( 1.2345, 2.789 );
  EXPECT_EQ( "(1.23, 2.79)", position.toString() );
}

TEST( Position, addition ) {
  const Position a( 1, 3 );
  const Position b( 2, 4 );
  const Position c = a + b;
  EXPECT_EQ( 3, c.x_ );
  EXPECT_EQ( 7, c.y_ );
}

}  // namespace PositionUnitTest