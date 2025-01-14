#include <Position.h>
#include <Utils.h>
#include <box2d/box2d.h>
#include <gtest/gtest.h>

namespace UtilsUnitTest {

b2WorldId givenWorld() {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{ 0.0f, -9.81 };
  return b2CreateWorld( &world_def );
}

TEST( Utils, dynamicCircle ) {
  const auto world_id = givenWorld();
  const auto position = Position{ 1, 5 };
  constexpr auto radius = 1.0f;
  constexpr auto density = 1.0f;
  constexpr auto friction = 1.0f;

  const auto circle_id =
      Utils::createDynamicCircle( world_id, position, radius, density, friction );

  const auto actual_radius = Utils::getCircleRadius( circle_id );
  EXPECT_FLOAT_EQ( actual_radius, radius );

  const auto circle_rot = Utils::getCircleRot( circle_id );
  EXPECT_EQ( circle_rot.pos(), position );
  EXPECT_FLOAT_EQ( circle_rot.radius(), radius );
  EXPECT_FLOAT_EQ( circle_rot.rotation(), 0.0f );

  b2DestroyWorld( world_id );
}

}  // namespace UtilsUnitTest