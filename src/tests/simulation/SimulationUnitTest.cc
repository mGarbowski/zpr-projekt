#include <gtest/gtest.h>

#include "Simulation.h"

namespace SimulationUnitTest {
  TEST(SimulationUnitTest, firstTest) {
    Simulation sim;
    for (size_t i = 0; i < 1000; ++i) {
      sim.step();
    }
    EXPECT_NEAR(sim.getBodyPosition().y, 1.0, 0.01);
  }
}