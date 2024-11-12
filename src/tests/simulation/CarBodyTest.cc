//
// Created by mgarbowski on 11/12/24.
//
#include <box2d/box2d.h>
#include <gtest/gtest.h>

#include "CarBody.h"

namespace CarBodyTest {
void printTriangle(const int idx, const b2Polygon& triangle) {
  std::cout << "v" << idx << ": ";
  for (int i = 0; i < 3; ++i) {
    std::cout << "(" << triangle.vertices[i].x << ", " << triangle.vertices[i].y << ") ";
  }
  std::cout << std::endl;
}

void assertPointsEqual(b2Vec2 a, b2Vec2 b) {
  ASSERT_FLOAT_EQ(a.x, b.x);
  ASSERT_FLOAT_EQ(a.y, b.y);
}


TEST(CarBodyTest, vertexPositions) {
  const CarDescription car_description = {{-4, 2}, {0, 1}, {4, 2}, {2, 0}, {4, -2}, {0, -1}, {-4, -2},
                                    {-2, 0}, 1.0f,   1.0f,   1.0f,   0.5f,    0.5f};


  const auto world_def = b2DefaultWorldDef();
  const auto world_id = b2CreateWorld(&world_def);
  const auto car_body = CarBody::create(world_id, {0, 0}, car_description);
  const auto body_id = car_body.bodyId();

  std::vector<b2ShapeId> shape_ids(8);
  const auto n_shapes = b2Body_GetShapes(body_id, shape_ids.data(), shape_ids.size());
  ASSERT_EQ(n_shapes, 8);

  for (int i = 0; i < 8; ++i) {
    const auto tri = b2Shape_GetPolygon(shape_ids[i]);
    ASSERT_EQ(tri.count, 3);
    printTriangle(i, tri);
  }

  // top left
  assertPointsEqual(b2Vec2{-4, 2}, b2Shape_GetPolygon(shape_ids[7]).vertices[1]);
  assertPointsEqual(b2Vec2{-4, 2}, b2Shape_GetPolygon(shape_ids[6]).vertices[2]);
}

}  // namespace CarBodyTest