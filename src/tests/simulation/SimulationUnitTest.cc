#include <gtest/gtest.h>

#include "Simulation.h"
#include "Evolution.h"

namespace SimulationUnitTest {
  TEST(SimulationUnitTest, firstTest) {
    Simulation sim;
    for (size_t i = 0; i < 1000; ++i) {
      sim.step();
    }
    EXPECT_NEAR(sim.getBodyPosition().y, 1.0, 0.01);
  }

  TEST(SimulationEvolution, testUsingLinkedLibrary) {
    Evolution ev;
    EXPECT_EQ(ev.add(2, 2), 4);
  }
}