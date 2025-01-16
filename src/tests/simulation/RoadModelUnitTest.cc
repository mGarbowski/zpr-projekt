#include <box2d/box2d.h>
#include <gtest/gtest.h>

#include "Position.h"
#include "Road.h"
#include "RoadModel.h"

namespace RoadModelUnitTest {

Road givenRoad() {
  return Road( { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 } } );
}

b2WorldId givenWorld() {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{ 0.0f, -9.81 };
  return b2CreateWorld( &world_def );
}

TEST( RoadModel, correspondsToRoad ) {
  const auto world_id = givenWorld();
  const auto road = givenRoad();
  const auto position = Position( 10, 10 );
  const auto road_model = RoadModel::create( world_id, road, position );

  // Runway and wall are added at the beginning
  EXPECT_TRUE( road_model.getSegments().size() > road.points_.size() );

  // Only checking the end as wall and runway is added to the beginning
  EXPECT_EQ( road_model.getEnd().x_, 5 );
  EXPECT_EQ( road_model.getEnd().y_, 0 );

  b2DestroyWorld( world_id );
}

}  // namespace RoadModelUnitTest