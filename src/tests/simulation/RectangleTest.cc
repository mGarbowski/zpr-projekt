//
// Created by mgarbowski on 11/4/24.
//
#include <gtest/gtest.h>

#include <box2d/box2d.h>
#include "Rectangle.h"

namespace RectangleUnitTest {
TEST(RectangleUnitTest, constructor) {
  b2WorldDef world_def = b2DefaultWorldDef();
  world_def.gravity = b2Vec2{0.0f, -10.0f};
  auto world_id = b2CreateWorld(&world_def);

  Rectangle r(world_id, {1.0, 1.0}, {5.0, 5.0});
  ASSERT_EQ(r.position().x, 1.0);
}

}