#include <ControlPanel.h>
#include <gtest/gtest.h>

namespace ControlPanelUnitTest {

TEST( ControlPanel, defaultDelayIsPositive ) {
  const ControlPanel control_panel;
  EXPECT_TRUE( control_panel.getDelayMicroseconds() > 0 );
}

}  // namespace ControlPanelUnitTest