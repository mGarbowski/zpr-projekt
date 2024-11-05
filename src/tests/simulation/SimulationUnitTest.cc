#include <gtest/gtest.h>

#include "BoxesSimulation.h"

namespace SimulationUnitTest {
  TEST(SimulationUnitTest, firstTest) {

    Rect box = {{0, 10}, {2, 2}};
    Rect ground = {{0, 0}, {20, 1}};
    BoxesSimulation sim({box}, ground);
    for (size_t i = 0; i < 1000; ++i) {
      sim.step();
    }
    EXPECT_NEAR(sim.getBox(0).pos().y, 1.5, 0.01);
  }
}