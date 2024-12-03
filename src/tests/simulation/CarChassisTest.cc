//
// Created by mgarbowski on 11/12/24.
//
#include <box2d/box2d.h>
#include <gtest/gtest.h>

#include "CarChassis.h"

namespace CarChassisTest {
void printTriangle(const int idx, const b2Polygon& triangle) {
  std::cout << "v" << idx << ": ";
  for (int i = 0; i < 3; ++i) {
    std::cout << "(" << triangle.vertices[i].x << ", " << triangle.vertices[i].y << ") ";
  }
  std::cout << std::endl;
}

void assertPointsEqual(const Position a, const b2Vec2 b) {
  ASSERT_FLOAT_EQ(a.x_, b.x);
  ASSERT_FLOAT_EQ(a.y_, b.y);
}

TEST(CarChassisTest, vertexPositions) {
  const Position center{0, 0};
  const Position top_left{-4, 2};
  const Position top{0, 1};
  const Position top_right{4, 2};
  const Position right{2, 0};
  const Position bottom_right{4, -2};
  const Position bottom{0, -1};
  const Position bottom_left{-4, -2};
  const Position left{-2, 0};

  const CarDescription car_description = {top_left, top,         top_right, right, bottom_right,
                                          bottom,   bottom_left, left,      1.0f,  1.0f,
                                          1.0f,     0.5f,        0.5f};

  const auto world_def = b2DefaultWorldDef();
  const auto world_id = b2CreateWorld(&world_def);
  const auto car_chassis = CarChassis::create(world_id, center, car_description);

  for (int i = 0; i < 8; ++i) {
    const auto tri = car_chassis.getTriangle(i);
    ASSERT_EQ(tri.count, 3);
    printTriangle(i, tri);
  }

  assertPointsEqual(top_left, car_chassis.getTriangle(7).vertices[1]);
  assertPointsEqual(top_left, car_chassis.getTriangle(6).vertices[2]);

  assertPointsEqual(top, car_chassis.getTriangle(6).vertices[1]);
  assertPointsEqual(top, car_chassis.getTriangle(5).vertices[2]);

  assertPointsEqual(top_right, car_chassis.getTriangle(5).vertices[1]);
  assertPointsEqual(top_right, car_chassis.getTriangle(4).vertices[2]);

  assertPointsEqual(right, car_chassis.getTriangle(4).vertices[1]);
  assertPointsEqual(right, car_chassis.getTriangle(3).vertices[2]);

  assertPointsEqual(bottom_right, car_chassis.getTriangle(3).vertices[1]);
  assertPointsEqual(bottom_right, car_chassis.getTriangle(2).vertices[2]);

  assertPointsEqual(bottom, car_chassis.getTriangle(2).vertices[1]);
  assertPointsEqual(bottom, car_chassis.getTriangle(1).vertices[2]);

  assertPointsEqual(bottom_left, car_chassis.getTriangle(1).vertices[1]);
  assertPointsEqual(bottom_left, car_chassis.getTriangle(0).vertices[2]);

  assertPointsEqual(left, car_chassis.getTriangle(0).vertices[1]);
  assertPointsEqual(left, car_chassis.getTriangle(7).vertices[2]);

  for (int i = 0; i < 8; ++i) {
    assertPointsEqual(center, car_chassis.getTriangle(i).vertices[0]);
  }
}

}  // namespace CarChassisTest