#include <gtest/gtest.h>

#include "SimulationsManager.h"

namespace SimulationsManagerUnitTest {

TEST(SimulationsManager, initializeForPopulation) {
  SimulationsManager manager;
  EXPECT_TRUE( 2 + 2 == 4 );
}

}