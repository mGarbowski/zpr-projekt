#include <gtest/gtest.h>

#include "Evolution.h"

namespace EvolutionUnitTest {
  TEST(Evolution, test) {
    Evolution ev;
    EXPECT_EQ(ev.add(1, 2), 3);
  }
}